#ifndef MORPHO_GEOMETRY_H_
#define MORPHO_GEOMETRY_H_

#include "Eigen/Dense"
#include "Eigen/Geometry"
#include "morpho/types.h"
#include "unsupported/Eigen/CXX11/Tensor"

namespace morpho {

class Geometry {
private:
  vector3d a1_;
  vector3d a2_;
  vector3d a3_;
  int n1;
  int n2;
  int n3;
  tensor3d epsr_;
  tensor3d mur_;

public:
  Geometry(vector3d a1, vector3d a2, vector3d a3, int n1, int n2, int n3);
  Geometry(const Geometry &other) = delete;
  Geometry(Geometry &&other) noexcept = delete;
  Geometry &operator=(const Geometry &other) = delete;
  Geometry &operator=(Geometry &&other) noexcept = delete;

  const vector3d &a1() const { return a1_; };
  const vector3d &a2() const { return a2_; };
  const vector3d &a3() const { return a3_; };

  const tensor3d &eps_r() const { return epsr_; };
  const tensor3d &mu_r() const { return mur_; };

  void set_properties(
      double (*f)(double, double, double),
      double (*g)(double, double, double));
};
}; // namespace morpho

#endif // MORPHO_GEOMETRY_H_
