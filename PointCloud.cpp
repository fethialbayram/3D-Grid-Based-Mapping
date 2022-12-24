#include "PointCloud.h"

PointCloud::PointCloud(int pointNumber) : pointNumber(pointNumber) {
    points = new Point[pointNumber];
  }

PointCloud::PointCloud(const PointCloud& pointcloud) {
    pointNumber = pointcloud.pointNumber;
    points = pointcloud.points;
  }


void PointCloud::setPoints(class Point* points) { this->points = points; }
Point* PointCloud::getPoints() const { return points; }
void PointCloud::setPointNumber(int pointNumber) { this->pointNumber = pointNumber; }
int PointCloud::getPointNumber() const { return pointNumber; }


PointCloud PointCloud::operator+(const PointCloud& pointcloud) const {
  int newpointNumber = pointNumber + pointcloud.pointNumber;
  Point*  points = new Point[newpointNumber];
  copy(this->points, this->points + pointNumber, points);
  copy(pointcloud.points, pointcloud.points + pointcloud.pointNumber, points + pointNumber);
  return PointCloud(newpointNumber);
}

PointCloud& PointCloud::operator=(const PointCloud& pointcloud) {
  if (this == &pointcloud) return *this;
  PointCloud temp(pointcloud);
  swap(pointNumber, temp.pointNumber);
  swap(points, temp.points);
  return *this;
}


