#include "morpho/geometry.h"
#include "morpho/types.h"
#define PI 3.14159265358979323846

morpho::Geometry::Geometry(
    vector3d a1,
    vector3d a2,
    vector3d a3,
    int n1,
    int n2,
    int n3)
    : n1(n1), n2(n2), n3(n3) {
  a1_ = a1;
  a2_ = a2;
  a3_ = a3;
  epsr_ = tensor3d(n1, n2, n3);
  mur_ = tensor3d(n1, n2, n3);
  epsr_.setConstant(1.0);
  mur_.setConstant(1.0);
}

void morpho::Geometry::set_properties(
    double (*f)(double, double, double),
    double (*g)(double, double, double)) {

  Eigen::VectorXd d1 = Eigen::VectorXd::LinSpaced(n1, -0.5, 0.5);
  Eigen::VectorXd d2 = Eigen::VectorXd::LinSpaced(n2, -0.5, 0.5);
  Eigen::VectorXd d3 = Eigen::VectorXd::LinSpaced(n3, -0.5, 0.5);

  d1 *= (a1_[0] + a2_[0] + a3_[0]);
  d2 *= (a1_[1] + a2_[1] + a3_[1]);
  d3 *= (a1_[2] + a2_[2] + a3_[2]);

  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < n2; ++j) {
      for (int k = 0; k < n3; ++k) {
        epsr_(i, j, k) = (*f)(d1(i), d2(k), d3(k));
        mur_(i, j, k) = (*g)(d1(i), d2(k), d3(k));
      }
    }
  }
}
