#ifndef _POINT_H_
#define _POINT_H_

struct Point {
  double x;
  double y;
  double z;

  Point() : x(0), y(0), z(0){};
  Point(double x, double y, double z) : x(x), y(y), z(z){};
};

#endif  //_POINT_H_