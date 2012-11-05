// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_UTIL_FILEUTILS_H
#define HEMELB_UTIL_FILEUTILS_H

#include <dirent.h>
#include <string>

// Define a suitable type for the system we're on
// (scandir has slightly different definitions on different
// architectures)
namespace hemelb
{
  namespace util
  {
#ifdef HEMELB_CFG_ON_BSD
    typedef struct direct direct_t;
#else // HEMELB_CFG_ON_BSD
    typedef const struct direct direct_t;
#endif // HEMELB_CFG_ON_BSD
    // Copy a file from the source path destination path to the destination
    // path.
    bool FileCopy(const char* iOriginalPath, const char* iNewPath);

    // Return true if file exists for reading, false if not.
    bool file_exists(const char * filename);
    // Exits if the named file doesn't exist or can't be opened for
    // reading.
    void check_file(const char * filename);

    // Delete all files within a directory.
    int DeleteDirContents(std::string pathname);

    // Check whether a directory exists.
    bool DoesDirectoryExist(const char *pathname);

    // Function to create the directory of given path, which user group
    // and anyone can read write and execute.
    void MakeDirAllRXW(std::string &dirPath);

    // Get the full path of inPath relative to basePath
    // which can be either a directory or a file (in this case, use
    // the containing directory).
    std::string NormalizePathRelativeToPath(std::string inPath, std::string basePath);

    std::string GetTemporaryDir();

    void ChangeDirectory(const char * target);
    void ChangeDirectory(const std::string &target);
    void GetCurrentDir(char * result, int bufflength);
    std::string GetCurrentDir();
  }
}
#endif // HEMELB_UTIL_FILEUTILS_H
