#ifndef MORPHO_BRILLOUINZONE_H_
#define MORPHO_BRILLOUINZONE_H_

#include "Eigen/Dense"
#include "morpho/types.h"
#include <iostream>
#include <string>
#include <numeric>

namespace morpho {

struct SymmetryPoint {
  vector3d point;
  std::string name;
  SymmetryPoint(vector3d point, std::string name);
  friend std::ostream &operator<<(std::ostream &os, const SymmetryPoint &point);
};

class BrillouinZonePath {
private:
  std::vector<SymmetryPoint> path;
  vector3d a1_, a2_, a3_;
  int n_points;

public:
  BrillouinZonePath(
      std::vector<SymmetryPoint> path,
      vector3d a1,
      vector3d a2,
      vector3d a3,
      int n_points);

  const vector3d &a1() const { return a1_; };
  const vector3d &a2() const { return a2_; };
  const vector3d &a3() const { return a3_; };

  vector3d b1();
  vector3d b2();
  vector3d b3();

  matrixXd beta_vec();
	vectorXd beta_len();
};

} // namespace morpho

#endif // MORPHO_BRILLOUINZONE_H_
