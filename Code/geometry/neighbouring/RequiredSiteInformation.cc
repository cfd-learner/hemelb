// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "geometry/neighbouring/RequiredSiteInformation.h"
#include "mpiInclude.h"
namespace hemelb
{
  namespace geometry
  {
    namespace neighbouring
    {
      RequiredSiteInformation::RequiredSiteInformation(bool initial) :
          choices(terms::Length, initial)
      {
      }
      void RequiredSiteInformation::Require(terms::Term term)
      {
        choices[term] = true;
      }
      bool RequiredSiteInformation::Any()
      {
        for (std::vector<bool>::iterator choice = choices.begin(); choice != choices.end(); choice++)
        {
          if (*choice)
          {
            return true;
          }
        }
        return false;
      }
      bool RequiredSiteInformation::AnyFieldDependent()
      {
        for (int choice = terms::Distribution; choice < terms::Length; choice++)
        {
          if (choices[choice])
          {
            return true;
          }
        }
        return false;
      }
      bool RequiredSiteInformation::AnyNonFieldDependent()
      {
        for (int choice = terms::SiteData; choice <= terms::WallNormal; choice++)
        {
          if (choices[choice])
          {
            return true;
          }
        }
        return false;
      }
      bool RequiredSiteInformation::AnyMacroscopic()
      {
        for (int choice = terms::Velocity; choice < terms::Length; choice++)
        {
          if (choices[choice])
          {
            return true;
          }
        }
        return false;
      }

      void RequiredSiteInformation::Or(const RequiredSiteInformation& other)
      {
        for (int choice = terms::SiteData; choice < terms::Length; choice++)
        {
          choices[choice]=choices[choice] || other.choices[choice];
        }
      }
      void RequiredSiteInformation::And(const RequiredSiteInformation& other)
      {
        for (int choice = terms::SiteData; choice < terms::Length; choice++)
        {
         choices[choice]=choices[choice] && other.choices[choice];
        }
      }
    }
  }
}
