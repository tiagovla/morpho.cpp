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

morpho::vector3d morpho::BrillouinZonePath::b1() {
  return 2 * PI * a2_.cross(a3_) / a1_.dot(a2_.cross(a3_));
}

morpho::vector3d morpho::BrillouinZonePath::b2() {
  return 2 * PI * a3_.cross(a1_) / a1_.dot(a2_.cross(a3_));
}

morpho::vector3d morpho::BrillouinZonePath::b3() {
  return 2 * PI * a1_.cross(a2_) / a1_.dot(a2_.cross(a3_));
}
