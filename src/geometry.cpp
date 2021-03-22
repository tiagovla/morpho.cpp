#include "morpho/geometry.h"
#define PI 3.14159265358979323846

morpho::Geometry::Geometry(
    vector3 a1,
    vector3 a2,
    vector3 a3,
    int n1,
    int n2,
    int n3)
    : n1(n1), n2(n2), n3(n3) {
  a1_ = a1;
  a2_ = a2;
  a3_ = a3;
  epsr_ = tensor3(n1, n2, n3);
  mur_ = tensor3(n1, n2, n3);
  epsr_.setConstant(1.0);
  mur_.setConstant(1.0);
}

morpho::vector3 morpho::Geometry::b1() {
  return 2 * PI * a2_.cross(a3_) / a1_.dot(a2_.cross(a3_));
}

morpho::vector3 morpho::Geometry::b2() {
  return 2 * PI * a3_.cross(a1_) / a1_.dot(a2_.cross(a3_));
}

morpho::vector3 morpho::Geometry::b3() {
  return 2 * PI * a1_.cross(a2_) / a1_.dot(a2_.cross(a3_));
}

void morpho::Geometry::set_properties(
    double (*f)(double, double, double),
    double (*g)(double, double, double)) {
  auto d1 =
      (a1_[0] + a2_[0] + a3_[0]) * Eigen::VectorXd::LinSpaced(n1, -0.5, 0.5);
  auto d2 =
      (a1_[1] + a2_[1] + a3_[1]) * Eigen::VectorXd::LinSpaced(n2, -0.5, 0.5);
  auto d3 =
      (a1_[2] + a2_[2] + a3_[2]) * Eigen::VectorXd::LinSpaced(n3, -0.5, 0.5);

  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < n2; ++j) {
      for (int k = 0; k < n3; ++k) {
        epsr_(i, j, k) = (*f)(d1(i), d2(k), d3(k));
        mur_(i, j, k) = (*g)(d1(i), d2(k), d3(k));
      }
    }
  }
}
