#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/passthrough.h>
#include <pcl/visualization/cloud_viewer.h>

typedef pcl::PointXYZ PointT;

int
main(int argc, char **argv) {
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);

    if (pcl::io::loadPCDFile("/home/czj/Desktop/pcl_learning/data/test_pcd.pcd", *cloud))
    {
        /* code */
        return -1;
    }
    
    pcl::PassThrough<pcl::PointXYZ> pass;
    pass.setInputCloud(cloud);          
    pass.setFilterFieldName("z");       
    pass.setFilterLimits(0.0, 1.0);     
    pass.filter(*cloud_filtered);       

    pcl::visualization::CloudViewer viewer("Cloud Viewer");

    viewer.showCloud(cloud);
    while (!viewer.wasStopped()) {
    }
    return (0);
}
