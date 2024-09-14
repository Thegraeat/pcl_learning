#include <iostream>
#include <pcl/io/file_io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>


int main(int argc, char const *argv[])
{
    /* code */
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile("/home/czj/Desktop/pcl_learning/data/test_pcd.pcd",*cloud);
    pcl::visualization::CloudViewer viewer("cloud viewer");
    viewer.showCloud(cloud);

    while (!viewer.wasStopped())
    {
        /* code */
    }
    

    return 0;
}
