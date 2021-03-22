#include "morpho/brillouinzone.h"
#include "morpho/geometry.h"
#include "unsupported/Eigen/CXX11/Tensor"
#include <iostream>
#include <utility>
#include <vector>

static double set_epsr(double x, double y, double z) { return 2.0; }
static double set_mur(double x, double y, double z) { return 1.0; }

int main() {
  std::cout << "morpho.cpp" << std::endl;
  double a{1.0};

  morpho::vector3 a1{a, 0, 0}, a2{0, a, 0}, a3{0, 0, a};

  int n1{32}, n2{32}, n3{32};

  morpho::Geometry geo(a1, a2, a3, n1, n2, n3);
  geo.set_properties(set_epsr, set_mur);

  auto pX = morpho::SymmetryPoint{morpho::vector3{0.5, 0, 0}, "X"};
  auto pY = morpho::SymmetryPoint{morpho::vector3{0, 0.5, 0}, "Y"};
  auto pZ = morpho::SymmetryPoint{morpho::vector3{0, 0, 0.5}, "Z"};

  auto points = std::vector<morpho::SymmetryPoint>{pZ, pX, pY, pZ};
  auto bz_path = morpho::BrillouinZonePath(points, a1, a2, a3, 50);

  for (auto &point : points) {
    std::cout << point << std::endl;
  }

  return 0;
}
