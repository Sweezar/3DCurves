#ifndef _HELIX_H_
#define _HELIX_H_

#include "curve.h"

class Helix : public Curve {
 public:
  Helix(double r, double step);
  Point getPoint(double t) const override;
  Vector3d getDerivative(double t) const override;
  CurveType getType() const override;

 private:
  double radius;
  double step;
};

#endif  // _HELIX_H_