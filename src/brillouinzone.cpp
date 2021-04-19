#include "morpho/brillouinzone.h"
#define PI 3.14159265358979323846

namespace morpho {
std::ostream &operator<<(std::ostream &os, const morpho::SymmetryPoint &p) {
  return os << p.point;
};
} // namespace morpho

morpho::SymmetryPoint::SymmetryPoint(vector3d point, std::string name)
  : point(point), name(name){};

morpho::BrillouinZonePath::BrillouinZonePath(
    std::vector<SymmetryPoint> path,
    vector3d a1,
    vector3d a2,
    vector3d a3,
    int n_points) {
  a1_ = a1;
  a2_ = a2;
  a3_ = a3;
  this->path = path;
  this->n_points = n_points;
};

morpho::matrixXd morpho::BrillouinZonePath::beta_vec() {

  size_t sv = path.size();
  Eigen::MatrixXd beta{3, sv};
  for (int i = 0; i < sv; ++i) {
    beta.col(i) = path[i].point;
  }

  return beta;
}

morpho::vectorXd morpho::BrillouinZonePath::beta_len() {

  size_t sv = path.size();
  morpho::matrixXd beta = this->beta_vec();

  auto n_rows{beta.rows()}, n_cols{beta.cols()};
  auto e1 = beta.block(0, 1, n_rows, n_cols - 1);
  auto e2 = beta.block(0, 0, n_rows, n_cols - 1);

  morpho::vectorXd dif = (e2 - e1).colwise().norm();
  morpho::vectorXd csum(dif.size() + 1);
  csum << 0, dif;
  std::partial_sum(
      csum.data(), csum.data() + csum.size(), csum.data(), std::plus<double>());
  return csum;
}

morpho::vector3d morpho::BrillouinZonePath::b1() {
  return 2 * PI * a2_.cross(a3_) / a1_.dot(a2_.cross(a3_));
}

morpho::vector3d morpho::BrillouinZonePath::b2() {
  return 2 * PI * a3_.cross(a1_) / a1_.dot(a2_.cross(a3_));
}

morpho::vector3d morpho::BrillouinZonePath::b3() {
  return 2 * PI * a1_.cross(a2_) / a1_.dot(a2_.cross(a3_));
}
