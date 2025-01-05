#include "helix.h"

Helix::Helix(double r, double step) : radius(r), step(step) {
  if (r <= 0) throw std::invalid_argument("radius must be positive");
}

Point Helix::getPoint(double t) const {
  return {radius * cos(t), radius * sin(t), (step * t) / (2 * M_PI)};
}

Vector3d Helix::getDerivative(double t) const {
  return {radius * -sin(t), radius * cos(t), step / (2 * M_PI)};
}

CurveType Helix::getType() const { return CurveType::Helix; }
