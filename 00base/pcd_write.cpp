#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int main(int, char**){
    pcl::PointCloud<pcl::PointXYZ> cloud;

    cloud.width = 100;
    cloud.height = 100;
    cloud.is_dense = false;
    cloud.points.resize(cloud.width * cloud.height);

    for (auto &point : cloud)
    {
        point.x = 1024 * rand() / (RAND_MAX + 1.0f);
        point.y = 1024 * rand() / (RAND_MAX + 1.0f);
        point.z = 1024 * rand() / (RAND_MAX + 1.0f);
    }
    
    pcl::io::savePCDFile("/home/czj/Desktop/pcl_learning/data/test_pcd.pcd",cloud,true);
    std::cerr << "saved" << cloud.size() << "data point to test_pcd.pcd" << std::endl;

    return 0;
}
