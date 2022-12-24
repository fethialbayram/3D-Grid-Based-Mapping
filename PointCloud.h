#pragma once
#include<cmath>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include "Point.h"
#include <list>
#include <vector>
#include<fstream>
#include<string>

using namespace std;

class PointCloud {
    friend class PointCloudRecorder;
    friend class DepthCamera;
    friend class Transform;
    friend class ThreeDGridMap;
private:
  
  int pointNumber;
  Point* points;
    
public:

    PointCloud(int);
    PointCloud(const PointCloud&);
    void setPoints(Point*);
    Point* getPoints() const ;
    void setPointNumber(int);
    int getPointNumber() const;
    PointCloud operator+(const PointCloud&) const ;
    PointCloud& operator=(const PointCloud&) ;
    
    
};
