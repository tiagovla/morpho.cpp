#include "Eigen/Dense"
#include "morpho/geometry.h"
#include <iostream>

int main() {
  std::cout << "Morpho.cpp" << std::endl;
  morpho::Geometry geo(3, 3, 3);
  std::cout << geo.getP() << std::endl;
  return 0;
}
