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

  morpho::vector3d a1{a, 0, 0}, a2{0, a, 0}, a3{0, 0, a};

  int n1{32}, n2{32}, n3{32};

  morpho::Geometry geo(a1, a2, a3, n1, n2, n3);
  geo.set_properties(set_epsr, set_mur);

  auto p_X = morpho::SymmetryPoint{morpho::vector3d{0.5, 0, 0}, "X"};
  auto p_Y = morpho::SymmetryPoint{morpho::vector3d{0, 0.5, 0}, "Y"};
  auto p_Z = morpho::SymmetryPoint{morpho::vector3d{0, 0, 0.5}, "Z"};

  auto points = std::vector<morpho::SymmetryPoint>{p_Z, p_X, p_Y, p_Z};
  auto bz_path = morpho::BrillouinZonePath(points, a1, a2, a3, 50);

  for (auto &point : points) {
    std::cout << std::endl << point << std::endl;
  }

  return 0;
}
