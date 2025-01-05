#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_

struct Vector3d {
  double x;
  double y;
  double z;

  Vector3d() : x(0), y(0), z(0){};
  Vector3d(double x, double y, double z) : x(x), y(y), z(z){};
};

#endif  // _VECTOR3D_H_