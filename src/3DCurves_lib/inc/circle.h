#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "curve.h"

class Circle : public Curve {
 public:
  Circle(double r);
  Point getPoint(double t) const override;
  Vector3d getDerivative(double t) const override;
  CurveType getType() const override;
  double getRadius() const;

 private:
  double radius;
};

#endif  //_CIRCLE_H_