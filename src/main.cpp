#include "Eigen/Dense"
#include "morpho/geometry.h"
#include "unsupported/Eigen/CXX11/Tensor"
#include <iostream>
#include <tuple>

typedef std::tuple<float, float, float> tuple3f;

int main() {
  std::cout << "morpho.cpp" << std::endl;
  float a = 1;

  tuple3f t1 = std::make_tuple(a, 0, 0);
  tuple3f t2 = std::make_tuple(0, a, 0);
  tuple3f t3 = std::make_tuple(0, 0, a);

  int N1 = 32;
  int N2 = 32;
  int N3 = 32;

  morpho::Geometry geo(t1, t2, t3, N1, N2, N3);

  std::cout << std::get<0>(geo.get_t1()) << std::endl;

  return 0;
}
