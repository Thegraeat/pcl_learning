cmake_minimum_required(VERSION 3.5.0)
project(pcl_learning VERSION 0.1.0 LANGUAGES C CXX)

find_package(PCL REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})


#add_subdirectory(00base)
#add_subdirectory(01tree)
#add_subdirectory(02filtering)
add_subdirectory(03rangImages)
