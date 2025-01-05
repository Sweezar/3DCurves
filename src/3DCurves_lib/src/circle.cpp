#include "circle.h"

Circle::Circle(double r) : radius(r) {
  if (r <= 0) throw std::invalid_argument("Radius must be positive");
}

Point Circle::getPoint(double t) const {
  return {radius * cos(t), radius * sin(t), 0};
}

Vector3d Circle::getDerivative(double t) const {
  return {radius * -sin(t), radius * cos(t), 0};
}

CurveType Circle::getType() const { return CurveType::Circle; }

double Circle::getRadius() const { return this->radius; }
