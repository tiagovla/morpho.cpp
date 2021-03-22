#include "morpho/brillouinzone.h"
#include <iostream>

std::ostream &
morpho::operator<<(std::ostream &os, const morpho::SymmetryPoint &p) {
  return os << p.point;
};

morpho::SymmetryPoint::SymmetryPoint(
    Eigen::Vector<double, 3> point,
    std::string name)
    : point(point), name(name){};

morpho::BrillouinZonePath::BrillouinZonePath(
    std::vector<SymmetryPoint> path,
    Eigen::Vector<double, 3> a1,
    Eigen::Vector<double, 3> a2,
    Eigen::Vector<double, 3> a3,
    int n_points)
    : path(path), a1(a1), a2(a2), a3(a3), n_points(n_points){};
