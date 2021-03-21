#include "morpho/geometry.h"
#include "unsupported/Eigen/CXX11/Tensor"
#include <iostream>

static double set_epsr(double x, double y, double z) { return 2.0; }
static double set_mur(double x, double y, double z) { return 1.0; }

using vector3 = morpho::vector3;
using Geometry = morpho::Geometry;

int main() {
  std::cout << "morpho.cpp" << std::endl;
  double a = 1.0;

  vector3 t1 = {a, 0, 0};
  vector3 t2 = {0, a, 0};
  vector3 t3 = {0, 0, a};

  int n1 = 32;
  int n2 = 32;
  int n3 = 32;

  Geometry geo(t1, t2, t3, n1, n2, n3);

  geo.set_properties(set_epsr, set_mur);
  std::cout << geo.get_T1() << std::endl;
  std::cout << (geo.get_eps_r())(0, 0, 0) << std::endl;

  return 0;
}
