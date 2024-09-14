#add_executable(passthrough passthrough.cpp)
#target_link_libraries(passthrough ${PCL_LIBRARIES} ${OpenCV_LIBS} )


add_executable(downsample_voxel_grid downsample_voxel_grid.cpp)
target_link_libraries(downsample_voxel_grid ${PCL_LIBRARIES} ${OpenCV_LIBS} )