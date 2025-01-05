#ifndef _CURVE_H_
#define _CURVE_H_

#include <array>
#include <cmath>
#include <stdexcept>

#include "point.h"
#include "vector3d.h"

enum class CurveType { Circle, Ellipse, Helix };

class Curve {
 public:
  virtual ~Curve() = default;
  virtual Point getPoint(double t) const = 0;
  virtual Vector3d getDerivative(double t) const = 0;
  virtual CurveType getType() const = 0;
};

#endif  //_CURVE_H_