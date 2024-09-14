#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_cloud.h>
#include <pcl/common/transforms.h>
#include <pcl/visualization/pcl_visualizer.h>

int main(int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr source_cloud(new pcl::PointCloud<pcl::PointXYZ>);

    if (pcl::io::loadPCDFile("/home/czj/Desktop/pcl_learning/data/test_pcd.pcd", *source_cloud) == -1)
    {
        PCL_ERROR("Couldn't read file test_pcd.pcd \n");
        return (-1);
    }

    Eigen::Affine3f transform_1 = Eigen::Affine3f::Identity();
    float theta = M_PI/4;

    transform_1.rotate(Eigen::AngleAxisf(theta, Eigen::Vector3f::UnitZ()));
    transform_1.rotate(Eigen::AngleAxisf(theta, Eigen::Vector3f::UnitY()));
    transform_1.rotate(Eigen::AngleAxisf(theta, Eigen::Vector3f::UnitX()));

    transform_1.translation() << 0.0, 0.0, 5.0;

    std::cout << transform_1.matrix() << std::endl;

    pcl::PointCloud<pcl::PointXYZ>::Ptr transformed_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::transformPointCloud(*source_cloud, *transformed_cloud, transform_1);

    pcl::visualization::PCLVisualizer viewer("Matrix Transform");

    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> source_cloud_color_handler(source_cloud, 255, 255, 255);
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> transformed_cloud_color_handler(transformed_cloud, 230, 20, 20); // Red

    viewer.addPointCloud(source_cloud,source_cloud_color_handler, "source_cloud");
    viewer.addPointCloud(transformed_cloud, transformed_cloud_color_handler,"transformed_cloud");
    viewer.spin();

    return 0;
}