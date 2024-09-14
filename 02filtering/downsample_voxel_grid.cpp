#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/common/transforms.h>

int main(int argc, char const *argv[])
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);

    pcl::io::loadPCDFile("/home/czj/Desktop/pcl_learning/data/table_scene_lms400.pcd",*cloud);

    float leaf_size = 0.01f;

    pcl::VoxelGrid<pcl::PointXYZ> sor;
    sor.setInputCloud(cloud);
    sor.setLeafSize(leaf_size, leaf_size, leaf_size);
    sor.filter(*cloud_filtered);

    Eigen::Affine3f transform = Eigen::Affine3f::Identity();
    auto t = transform.translate(Eigen::Vector3f(5,0,0));

    pcl::transformPointCloud(*cloud_filtered,*cloud_filtered,t);

    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> red(cloud_filtered, 255, 0, 0);

    pcl::visualization::PCLVisualizer viewer("cloud viewer");
    viewer.addPointCloud(cloud,"cloud");
    viewer.addPointCloud(cloud_filtered,red,"cloud_filtered");
    viewer.spin();
    return 0;
}