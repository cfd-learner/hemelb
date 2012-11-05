#include "PolyDataGenerator.h"

#include "Neighbours.h"
#include "Site.h"
#include "InconsistentFluidnessError.h"

#include "Debug.h"

#include "io/formats/geometry.h"

#include "vtkPolyDataAlgorithm.h"
#include "vtkOBBTree.h"
#include "vtkPolyData.h"
#include "vtkPoints.h"
#include "vtkIdList.h"
#include "vtkCellData.h"
#include "vtkDataSet.h"

using namespace hemelb::io::formats;

PolyDataGenerator::PolyDataGenerator() :
	GeometryGenerator(), ClippedSurface(NULL) {
	this->Locator = vtkOBBTree::New();
	this->Locator->SetTolerance(1e-9);
	this->hitPoints = vtkPoints::New();
	this->hitCellIds = vtkIdList::New();
}

PolyDataGenerator::~PolyDataGenerator() {
	this->Locator->Delete();
	this->hitPoints->Delete();
	this->hitCellIds->Delete();
}

void PolyDataGenerator::ComputeBounds(double bounds[6]) const {
	this->ClippedSurface->GetBounds(bounds);
}

void PolyDataGenerator::PreExecute(void) {
	// Build our locator.
	this->Locator->SetDataSet(this->ClippedSurface);
	this->Locator->BuildLocator();

	/*
	 * Get the scalars associated with the surface polygons. The scalars hold
	 * the index of the Iolet which they represent, -1 meaning they aren't an
	 * Iolet.
	 */
	this->IoletIdArray = vtkIntArray::SafeDownCast(
			this->ClippedSurface->GetCellData()->GetScalars());
	if (this->IoletIdArray == NULL) {
		throw GenerationErrorMessage(
				"Error getting Iolet ID array from clipped surface");
	}
}

/*
 * Given a site with known fluidness, examine the links to not-yet-visited
 * neighbouring sites. If the neighbours have unknown fluidness, set that.
 *
 * Since we wish to examine each link only once, this will set link properties
 * from neighbour => site as well as site => neighbour
 *
 */
void PolyDataGenerator::ClassifySite(Site& site) {

	for (LaterNeighbourIterator neighIt = site.begin(); neighIt != site.end(); ++neighIt) {
		Site& neigh = *neighIt;
		unsigned int iNeigh = neighIt.GetNeighbourIndex();
		vtkIdType nHits;

		if (!neigh.IsFluidKnown) {
			// Neighbour unknown, must always intersect
			nHits = this->ComputeIntersections(site, neigh);

			if (nHits % 2 == 0) {
				// Even # hits, hence neigh has same type as site
				neigh.IsFluid = site.IsFluid;
			} else {
				// Odd # hits, neigh is opposite type to site
				neigh.IsFluid = !site.IsFluid;
			}

			if (neigh.IsFluid)
				neigh.CreateLinksVector();

			neigh.IsFluidKnown = true;
		} else {
			// We know the fluidness of neigh, maybe don't need to intersect
			if (site.IsFluid != neigh.IsFluid) {
				// Only in the case of difference must we intersect.
				nHits = this->ComputeIntersections(site, neigh);
				if (nHits % 2 != 1) {
					throw InconsistentFluidnessError(site, neigh, nHits);
				}
			}
		}

		// Four cases: fluid-fluid, solid-solid, fluid-solid and solid-fluid.
		// Will handle the last two together.
		if (site.IsFluid == neigh.IsFluid) {
			if (site.IsFluid) {
				// Fluid-fluid, must set CUT_NONE for both
				site.Links[iNeigh].Type = geometry::CUT_NONE;
				neigh.Links[Neighbours::inverses[iNeigh]].Type
						= geometry::CUT_NONE;
			} else {
				// solid-solid, nothing to do.
			}
		} else {
			// They differ, figure out which is fluid and which is solid.
			Site* fluid;
			Site* solid;

			// Index of the solid site from the fluid site.
			int iSolid;
			// Index of the point in this->hitPoints we're considering as the
			// hit of interest (i.e. the one closest to the fluid site).
			int iHit;

			if (site.IsFluid) {
				fluid = &site;
				solid = &neigh;
				iSolid = iNeigh;
				iHit = 0;
			} else {
				fluid = &neigh;
				solid = &site;
				iSolid = Neighbours::inverses[iNeigh];
				iHit = nHits - 1;
			}

			Vector hitPoint;
			this->hitPoints->GetPoint(iHit, &hitPoint[0]);
			LinkData& link = fluid->Links[iSolid];

			// This is set in any solid case
			link.Distance = (hitPoint - fluid->Position).GetMagnitude();
			// The distance is in voxels but must be output as a fraction of
			// the lattice vector. Scale it.
			link.Distance /= Neighbours::norms[iSolid];

			// The index of the cell in the vtkPolyData that was hit
			int hitCellId = this->hitCellIds->GetId(iHit);
			// The value associated with that cell, which identifies what was hit.
			int ioletId = this->IoletIdArray->GetValue(hitCellId);

			if (ioletId < 0) {
				// -1 => we hit a wall
				link.Type = geometry::CUT_WALL;
			} else {
				// We hit an inlet or outlet
				Iolet* iolet = this->Iolets[ioletId];
				if (iolet->IsInlet) {
					link.Type = geometry::CUT_INLET;
				} else {
					link.Type = geometry::CUT_OUTLET;
				}
				// Set the Id
				link.IoletId = iolet->Id;
			}
		}

	}
}

int PolyDataGenerator::ComputeIntersections(Site& from, Site& to) {
	this->Locator->IntersectWithLine(&from.Position[0], &to.Position[0],
			this->hitPoints, this->hitCellIds);
	return this->hitPoints->GetNumberOfPoints();
}
