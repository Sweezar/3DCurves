#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

#include "circle.h"
#include "curve.h"
#include "ellipse.h"
#include "helix.h"
#include "omp.h"

int main() {
  srand(time(NULL));

  std::vector<std::shared_ptr<Curve>> curves;
  int curvesCount = rand() % 10 + 10;
  double t = M_PI / 4;

  // Заполнение массива случайными кривыми со случайными значениями
  for (int i = 0; i < curvesCount; i++) {
    switch (rand() % 3) {
      case static_cast<int>(CurveType::Ellipse):
        curves.push_back(
            std::make_shared<Ellipse>(rand() % 100 + 1, rand() % 100 + 1));
        break;
      case static_cast<int>(CurveType::Helix):
        curves.push_back(
            std::make_shared<Helix>(rand() % 100 + 1, rand() % 10 + 1));
        break;
      case static_cast<int>(CurveType::Circle):
        curves.push_back(std::make_shared<Circle>(rand() % 100 + 1));
        break;
    }
  }

  // Вывод в консоль массива кривых
  for (auto& curve : curves) {
    Point p = curve->getPoint(t);
    Vector3d v = curve->getDerivative(t);
    switch (curve->getType()) {
      case CurveType::Ellipse:
        std::cout << "Ellipse: " << std::endl;
        break;
      case CurveType::Helix:
        std::cout << "Helix: " << std::endl;
        break;
      case CurveType::Circle:
        std::cout << "Circle: " << std::endl;
        break;
    }
    std::cout << "  Point: x = " << p.x << ", y = " << p.y << ", z = " << p.z
              << std::endl;
    std::cout << "  Vector: x = " << v.x << ", y = " << v.y << ", z = " << v.z
              << std::endl;
  }

  // Заполнение второго массива с окружностями
  std::vector<std::shared_ptr<Circle>> circles;
  for (const auto& curve : curves) {
    std::shared_ptr<Circle> circle = std::dynamic_pointer_cast<Circle>(curve);
    if(circle) {
      circles.push_back(circle);
    }
  }

  // Сортировка второго массива
  std::sort(circles.begin(), circles.end(), [](const auto& a, const auto& b) {
    return a->getRadius() < b->getRadius();
  });

  for (auto& circle : circles) {
    std::cout << "Circle: " << circle->getRadius() << std::endl;
  }

  // Сумма радиусов окружностей
  double totalRadius = 0.0;

#pragma omp parallel reduction(+ : totalRadius)
  {
#pragma omp for
    for (size_t i = 0; i < circles.size(); i++) {
      totalRadius += circles[i]->getRadius();
    }
  }
  std::cout << "Total radius: " << totalRadius << std::endl;

  return 0;
}