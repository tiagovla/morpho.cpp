#ifndef MORPHO_BRILLOUINZONE_H_
#define MORPHO_BRILLOUINZONE_H_

#include "Eigen/Dense"
#include "string"

namespace morpho {

struct SymmetryPoint {
  Eigen::Vector<double, 3> point;
  std::string name;
  SymmetryPoint(Eigen::Vector<double, 3> point, std::string name);
  friend std::ostream &operator<<(std::ostream &os, const SymmetryPoint &point);
};

class BrillouinZonePath {
private:
  std::vector<SymmetryPoint> path;
  Eigen::Vector<double, 3> a1, a2, a3;
  int n_points;

public:
  BrillouinZonePath(
      std::vector<SymmetryPoint> path,
      Eigen::Vector<double, 3> a1,
      Eigen::Vector<double, 3> a2,
      Eigen::Vector<double, 3> a3,
      int n_points);
};

} // namespace morpho

#endif // MORPHO_BRILLOUINZONE_H_
