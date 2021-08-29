// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// This file is part of the GPU Voxels Software Library.
//
// This program is free software licensed under the CDDL
// (COMMON DEVELOPMENT AND DISTRIBUTION LICENSE Version 1.0).
// You can find a copy of this license in LICENSE.txt in the top
// directory of the source code.
//
// © Copyright 2014 FZI Forschungszentrum Informatik, Karlsruhe, Germany
//
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Andreas Hermann
 * \date    2014-06-12
 *
 */
//----------------------------------------------------------------------

#ifndef GPU_VOXELS_HELPERS_PCD_FILE_READER_H_INCLUDED
#define GPU_VOXELS_HELPERS_PCD_FILE_READER_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include <gpu_voxels/helpers/FileReaderInterface.h>
#include <gpu_voxels/helpers/cuda_datatypes.h>
#include <gpu_voxels/logging/logging_gpu_voxels_helpers.h>

namespace gpu_voxels {
namespace file_handling {

class PcdFileReader : public FileReaderInterface
{
public:
  /*!
   * \brief readPointCloud is the file specific parsing function that has to be implemented
   * \param filename Filename
   * \param points points are written into this vector
   * \return true if succeeded, false otherwise
   */
  virtual bool readPointCloud(const std::string filename, std::vector<Vector3f> &points);
};

}  // end of namespace
}  // end of namespace
#endif
