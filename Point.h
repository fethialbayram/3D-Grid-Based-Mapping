#pragma once
#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;

class Point {
    friend class PointCloud;
    
private:
  double x;
  double y;
  double z;
        
public:
    
    //Constructor
    Point();
    Point(double,double,double) ;
    //Set-Get Functions
    void setX(double);
    double getX() const;
    void setY(double);
    double getY() const;
    void setZ(double);
    double getZ() const;
    //Equal Operator Overload
    bool operator==(const Point&)const;
    //Distance
    double distance(const Point&)const;
};
