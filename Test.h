/*
* @file Test.h
* @author Umut Birinci (152120171046)
* @date 21.12.2022
* @brief Header of Test class.
*/
#include <cassert>
#include <iostream>
#include "PointCloud.h"
#include "PointCloudRecorder.h"
#include "DepthCamera.h"
#include "Transform.h"
#include "ThreeDGridMap.h"
using namespace std;



void Point_Test(){// ------------------------------------POİNT CLASS TEST-------------------------------
    // Test default constructor
    Point p1;
    assert(p1.getX() == 0);
    assert(p1.getY() == 0);
    assert(p1.getZ() == 0);
    
    // Test parameterized constructor
    Point p2(1, 2, 3);
    assert(p2.getX() == 1);
    assert(p2.getY() == 2);
    assert(p2.getZ() == 3);
    
    // Test setters and getters
    p1.setX(4);
    assert(p1.getX() == 4);
    p1.setY(5);
    assert(p1.getY() == 5);
    p1.setZ(6);
    assert(p1.getZ() == 6);
    
    // Test equality operator
    Point p3(4, 5, 6);
    assert(p1 == p3);
    p3.setX(7);
    assert(p1 != p3);
    
    // Test distance function
    assert(p1.distance(p2) == sqrt(27));
   
  
}


void PointCloud_Test(){// ------------------------------------POİNTCLOUD CLASS TEST-------------------------------
    // Test PointCloud constructor
    PointCloud pc1(5);
    assert(pc1.getPointNumber() == 5);
    
    // Test setPoints and getPoints methods
    Point* points = new Point[10];
    pc1.setPoints(points);
    assert(pc1.getPoints() == points);
    
    // Test setPointNumber and getPointNumber methods
    pc1.setPointNumber(10);
    assert(pc1.getPointNumber() == 10);
    
    // Test PointCloud copy constructor
    PointCloud pc2(pc1);
    assert(pc2.getPointNumber() == 10);
    assert(pc2.getPoints() == points);
    
    // Test PointCloud + operator
    PointCloud pc3(5);
    PointCloud pc4 = pc1 + pc3;
    assert(pc4.getPointNumber() == 15);
    
    // Test PointCloud assignment operator
    PointCloud pc5(10);
    pc5 = pc1;
    assert(pc5.getPointNumber() == 10);
    assert(pc5.getPoints() == points);
    
    
    points=nullptr;
    
    // Create a point cloud with 3 points
    Point p6(1, 2, 3),p7(4,5,6),p8(7,8,9);
    PointCloud pointcloud(3);
    points = new Point[pointcloud.getPointNumber()];
    points[0]=p6;
    points[1]=p7;
    points[2]=p8;
    pointcloud.setPoints(points);
    
    assert(points[0]==p6);
    assert(points[1]==p7);
    assert(points[2]==p8);
    pointcloud.setPoints(points);
    assert(pointcloud.getPoints() == points);
}
void PointCloudRecorder_Test(){// ------------------------------------POİNTCLOUDRECORDER CLASS TEST-------------------------------
    // Create a point cloud recorder with a file name
    PointCloudRecorder recorder("test.txt");
    
    // Save the point cloud to a file
   // bool success = recorder.save(pointcloud);
    //assert(success);
    
    // Check that the file name was set correctly
    assert(recorder.getFileName() == "test.txt");
    
    // Change the file name and check that it was updated
    recorder.setFileName("new_test.txt");
    assert(recorder.getFileName() == "new_test.txt");
    
}
    
void DepthCamera_Test(){// ------------------------------------DEPTHCAMERA CLASS TEST-------------------------------
    
    // Create a DepthCamera object with a file name
    DepthCamera depthCamera("pointcloud.txt");
    
    // Test the getFilename function
    assert(depthCamera.getFilename() == "pointcloud.txt");
    
    // Test the setFilename function
    depthCamera.setFilename("new_pointcloud.txt");
    assert(depthCamera.getFilename() == "new_pointcloud.txt");
    
    
    
    DepthCamera dcamera("cam.txt");
    
   // PointCloud pcloud=dcamera.capture();
    
    // Test the capture function
    //PointCloud pcloud=dcamera.capture();

    
}
void Transform_Test(){// ------------------------------------TRANSFORM CLASS TEST-------------------------------
    
    /*
     
     
     // create a new transformation with rotation angles (30, 45, 60) and translation vector (1, 2, 3)
     double angles[] = {30, 60, 60};
     double trans[] = {1, 2, 5};
     Transform t(angles, trans);
     
     // create a point with coordinates (1, 2, 3)
     Point p(1, 2, 3);
     
     // apply the transformation to the point
     Point p_transformed = t.doTransform(p);
     
     // print the transformed coordinates
     cout << "Transformed coordinates: (" << p_transformed.getX() << ", " << p_transformed.getY() << ", " << p_transformed.getZ() << ")" << endl;
     
     */
    
    
    
    
}
    
void ThreeDGridMap_Test(){// ------------------------------------3DGRIDMAP CLASS TEST-------------------------------


  // Create a 3D grid map with depth 10 and grid size 1
  ThreeDGridMap map(10, 1);

  // Insert some points into the map
  PointCloud pcc(2);
  Point p9(1, 2, 3),p10(4,5,6);

   Point*  pointss = new Point[pcc.getPointNumber()];
    pointss[0]=p9;
    pointss[1]=p10;
    
    pcc.setPoints(pointss);
 
    
    map.insertPointCloud(pcc);

  // Check that the points are correctly inserted into the map
  assert(map.getGrid(1, 2, 3) == true);
  assert(map.getGrid(2, 3, 4) == true);

  // Check that a point outside the map returns false
  assert(map.getGrid(11, 2, 3) == false);
  assert(map.getGrid(-1, 2, 3) == false);

  // Save the map to a file and then load it back
  map.saveMap("map.txt");
  ThreeDGridMap map2(0, 0);
  map2.loadMap("map.txt");

  // Check that the map was correctly loaded from the file
  assert(map2.getGrid(1, 2, 3) == true);
  assert(map2.getGrid(2, 3, 4) == true);



}
    
    
    
    
    
    
    
    

