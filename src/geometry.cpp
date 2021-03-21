#include "morpho/geometry.h"
#define PI 3.14159265358979323846

morpho::Geometry::Geometry(vector3 t1,
                           vector3 t2,
                           vector3 t3,
                           int n1,
                           int n2,
                           int n3) {
  this->t1 = t1;
  this->t2 = t2;
  this->t3 = t3;
  this->n1 = n1;
  this->n2 = n2;
  this->n3 = n3;
  this->epsr = tensor3(n1, n2, n3);
  this->mur = tensor3(n1, n2, n3);

  this->epsr.setConstant(1.0);
  this->mur.setConstant(1.0);
}

morpho::vector3 morpho::Geometry::get_T1() {
  return 2 * PI * t2.cross(t3) / t1.dot(t2.cross(t3));
}

morpho::vector3 morpho::Geometry::get_T2() {
  return 2 * PI * t3.cross(t1) / t1.dot(t2.cross(t3));
}

morpho::vector3 morpho::Geometry::get_T3() {
  return 2 * PI * t1.cross(t2) / t1.dot(t2.cross(t3));
}

void morpho::Geometry::set_properties(double (*f)(double, double, double),
                                      double (*g)(double, double, double)) {
  auto d1 = (t1[0] + t2[0] + t3[0]) * Eigen::VectorXd::LinSpaced(n1, -0.5, 0.5);
  auto d2 = (t1[1] + t2[1] + t3[1]) * Eigen::VectorXd::LinSpaced(n2, -0.5, 0.5);
  auto d3 = (t1[2] + t2[2] + t3[2]) * Eigen::VectorXd::LinSpaced(n3, -0.5, 0.5);

  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < n2; ++j) {
      for (int k = 0; k < n3; ++k) {
        this->epsr(i, j, k) = (*f)(d1(i), d2(k), d3(k));
        this->mur(i, j, k) = (*g)(d1(i), d2(k), d3(k));
      }
    }
  }
}
