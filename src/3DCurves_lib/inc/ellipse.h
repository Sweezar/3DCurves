#ifndef _ELLIPSE_H_
#define _ELLIPSE_H_

#include "curve.h"

class Ellipse : public Curve {
 public:
  Ellipse(double rx, double ry);
  Point getPoint(double t) const override;
  Vector3d getDerivative(double t) const override;
  CurveType getType() const override;

 private:
  double radiusX;
  double radiusY;
};

#endif  // _ELLIPSE_H_