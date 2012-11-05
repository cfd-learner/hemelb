// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_EXTRACTION_LOCALPROPERTYOUTPUT_H
#define HEMELB_EXTRACTION_LOCALPROPERTYOUTPUT_H

#include "extraction/IterableDataSource.h"
#include "extraction/PropertyOutputFile.h"
#include "mpiInclude.h"

namespace hemelb
{
  namespace extraction
  {
    /**
     * Stores sufficient information to output property information from this core.
     */
    class LocalPropertyOutput
    {
      public:
        /**
         * Initialises a LocalPropertyOutput. Required so we can use const reference types.
         * @param file
         * @param offset
         * @return
         */
        LocalPropertyOutput(IterableDataSource& dataSource, const PropertyOutputFile* outputSpec);

        /**
         * Tidies up the LocalPropertyOutput (close files etc).
         * @return
         */
        ~LocalPropertyOutput();

        /**
         * True if this property output should be written on the current iteration.
         * @return
         */
        bool ShouldWrite(unsigned long timestepNumber) const;

        /**
         * Returns the property output file object to be written.
         * @return
         */
        const PropertyOutputFile* GetOutputSpec() const;

        /**
         * Write this core's section of the data file. Only writes if appropriate for the current
         * iteration number
         */
        void Write(unsigned long timestepNumber);

      private:
        /**
         * Returns the number of floats written for the field.
         * @param field
         */
        unsigned GetFieldLength(OutputField::FieldType field);

        /**
         * The MPI file to write into.
         */
        MPI_File outputFile;

        /**
         * The data source to use for file output.
         */
        IterableDataSource& dataSource;

        /**
         * PropertyOutputFile spec.
         */
        const PropertyOutputFile* outputSpec;

        /**
         * Where to begin writing into the file.
         */
        uint64_t localDataOffsetIntoFile;

        /**
         * The length, in bytes, of the local write.
         */
        uint64_t writeLength;

        /**
         * The length, in bytes, of the total write length;
         */
        uint64_t allCoresWriteLength;

        /**
         * Buffer to write into before writing to disk.
         */
        char* buffer;
    };
  }
}

#endif /* HEMELB_EXTRACTION_LOCALPROPERTYOUTPUT_H */
