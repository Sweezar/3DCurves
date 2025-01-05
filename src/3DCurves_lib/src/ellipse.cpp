#include "ellipse.h"

Ellipse::Ellipse(double rx, double ry) : radiusX(rx), radiusY(ry) {
  if (rx <= 0 || ry <= 0) throw std::invalid_argument("Invalid radius");
}

Point Ellipse::getPoint(double t) const {
  return {radiusX * cos(t), radiusY * sin(t), 0};
}

Vector3d Ellipse::getDerivative(double t) const {
  return {radiusX * -sin(t), radiusY * cos(t), 0};
}

CurveType Ellipse::getType() const { return CurveType::Ellipse; }
