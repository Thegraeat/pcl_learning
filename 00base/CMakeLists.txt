add_executable(pcd_write pcd_write.cpp)
target_link_libraries(pcd_write ${PCL_LIBRARIES})

add_executable(pcd_load pcd_load.cpp)
target_link_libraries(pcd_load ${PCL_LIBRARIES})

add_executable(matrix_transform matrix_transform.cpp)
target_link_libraries(matrix_transform ${PCL_LIBRARIES})