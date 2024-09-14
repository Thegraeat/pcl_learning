#include <pcl/point_cloud.h>        //点类型定义头文件
#include <pcl/kdtree/kdtree_flann.h> //kdtree类定义头文件
#include <iostream>
#include <vector>
#include <ctime>

int
main (int argc, char** argv)
{
    srand (time (NULL));   //用系统时间初始化随机种子

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    cloud->width = 1000;
    cloud->height = 1 ;
    cloud->points.resize(cloud->width * cloud->height);

    for (size_t i = 0; i < cloud->points.size(); i++)
    {
        cloud->points[i].x = 1024.0f * rand() / (RAND_MAX + 1.0f); // // 产生数值为0-1024的浮点数
        cloud->points[i].y = 1024.0f * rand () / (RAND_MAX + 1.0f);
        cloud->points[i].z = 1024.0f * rand () / (RAND_MAX + 1.0f);
    }
    
    pcl::KdTreeFLANN<pcl::PointXYZ> kdtree;
    kdtree.setInputCloud(cloud);

    pcl::PointXYZ searchPoint;
    searchPoint.x = 1024.0f * rand () / (RAND_MAX + 1.0f);
    searchPoint.y = 1024.0f * rand () / (RAND_MAX + 1.0f);
    searchPoint.z = 1024.0f * rand () / (RAND_MAX + 1.0f);

    int k = 10;
    std::vector<int> pointIdxNKNSearch(k);
    std::vector<float> pointNKNSquaredDistance(k);

    std::cout << "K nearest neighbor search at (" << searchPoint.x 
            << " " << searchPoint.y 
            << " " << searchPoint.z
            << ") with K=" << k << std::endl;

    if (kdtree.nearestKSearch(searchPoint,k,pointIdxNKNSearch,pointNKNSquaredDistance)>0)
    {

        for (size_t i = 0; i < pointIdxNKNSearch.size(); i++)
        {
            std::cout<< "K nearest neighbor point (" 
            << cloud->points[pointIdxNKNSearch[i]].x << " "
            << cloud->points[pointIdxNKNSearch[i]].y << " "
            << cloud->points[pointIdxNKNSearch[i]].z << ")" 
            << " squared distance " << pointNKNSquaredDistance[i] << std::endl;
            
        }
        
    }
    
    std::vector<int> pointIdxRadiusSearch;           
    std::vector<float> pointRadiusSquaredDistance;   

    float radius = 256.0f * rand () / (RAND_MAX + 1.0f);   

    std::cout << "Neighbors within radius search at (" << searchPoint.x 
            << " " << searchPoint.y 
            << " " << searchPoint.z
            << ") with radius=" << radius << std::endl;

    if ( kdtree.radiusSearch (searchPoint, radius, pointIdxRadiusSearch, pointRadiusSquaredDistance) > 0 )  //执行半径R内近邻搜索方法
    {
        for (size_t i = 0; i < pointIdxRadiusSearch.size (); ++i)
        {
            std::cout << "    "  <<   cloud->points[ pointIdxRadiusSearch[i] ].x 
                << " " << cloud->points[ pointIdxRadiusSearch[i] ].y 
                << " " << cloud->points[ pointIdxRadiusSearch[i] ].z 
                << " (squared distance: " << pointRadiusSquaredDistance[i] << ")" << std::endl;
        }
    }

    return 0;
}
