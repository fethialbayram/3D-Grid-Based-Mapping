#include "Point.h"

    Point::Point( double x,  double y,  double z) : x(x), y(y), z(z) {}
    Point::Point() : x(0), y(0), z(0) {} 
    void Point::setX(double x) { this->x = x; }
    double Point::getX() const { return x; }
    void Point::setY(double y) { this->y = y; }
    double Point::getY() const { return y; }
    void Point::setZ(double z) { this->z = z; }
    double Point::getZ() const  { return z; }

    bool Point::operator==(const Point& point)const {
      return x == point.x && y == point.y && z == point.z;
    }

    double Point::distance(const Point& point) const {
      double dx = x - point.x;
      double dy = y - point.y;
      double dz = z - point.z;
      return sqrt(dx*dx + dy*dy + dz*dz);
    }


