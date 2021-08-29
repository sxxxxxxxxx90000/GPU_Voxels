# this is for emacs file handling -*- mode: cmake; indent-tabs-mode: nil -*-

# ======================================
# CMakeLists file to demonstrate how to use GPU Voxels in your own project:
# ======================================

cmake_minimum_required (VERSION 3.10)
project (gvl_linkage_test)
SET(CMAKE_CXX_STANDARD 17)

# First we have to find our dependencies:
FIND_PACKAGE(CUDA REQUIRED)
FIND_PACKAGE(icmaker REQUIRED)
FIND_PACKAGE(icl_core REQUIRED )
FIND_PACKAGE(gpu_voxels REQUIRED)
FIND_PACKAGE(Boost COMPONENTS system REQUIRED)
find_package(catkin REQUIRED) 

# This is a quirk and should be removed in upcoming versions
# If you built GPU Voxels without ROS support, remove this.
#FIND_PACKAGE(urdfdom)
#FIND_PACKAGE(orocos_kdl)
#FIND_PACKAGE(kdl_parser)

# A little debug info:
MESSAGE(STATUS "GVL include dirs are: ${gpu_voxels_INCLUDE_DIRS}")

catkin_package() 

# Also we have to inherit some Environment definitions required for our base libs:
add_definitions(
  ${icl_core_DEFINITIONS}
  ${gpu_voxels_DEFINITIONS}
)

#include_directories(
#  ${icl_core_INCLUDE_DIRS}
#  ${gpu_voxels_INCLUDE_DIRS}
#)

# Create a library that uses GPU Voxels:
add_library (gvl_linkage_test_lib gvl_linkage_test_lib.cpp)

target_include_directories (gvl_linkage_test_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${icl_core_INCLUDE_DIRS}
    PUBLIC ${gpu_voxels_INCLUDE_DIRS}
    #PUBLIC ${orocos_kdl_INCLUDE_DIRS} # this should be removed in upcoming versions.
    #PUBLIC ${urdf_INCLUDE_DIRS}
    PUBLIC ${CUDA_INCLUDE_DIRS}
)
target_link_libraries (gvl_linkage_test_lib
    LINK_PUBLIC ${Boost_SYSTEM_LIBRARY}
    LINK_PUBLIC ${icl_core_LIBRARIES}
    LINK_PUBLIC ${gpu_voxels_LIBRARIES}
    LINK_PUBLIC ${CUDA_LIBRARIES}
)

# Add an executable that calls the lib:
add_executable (gvl_linkage_test gvl_linkage_test.cpp)

# Link the executable to the library.
# We currently also have to link against Boost and icl_core...
target_link_libraries (gvl_linkage_test
    LINK_PUBLIC gvl_linkage_test_lib
    LINK_PUBLIC ${Boost_SYSTEM_LIBRARY}
    LINK_PUBLIC ${icl_core_LIBRARIES}
    LINK_PUBLIC ${gpu_voxels_LIBRARIES}
    LINK_PUBLIC ${CUDA_LIBRARIES}
)
