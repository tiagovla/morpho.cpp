#ifndef MORPHO_GEOMETRY_H_
#define MORPHO_GEOMETRY_H_

#include "Eigen/Dense"
#include "Eigen/Geometry"
#include "unsupported/Eigen/CXX11/Tensor"

namespace morpho {

typedef Eigen::Vector<double, 3> vector3;
typedef Eigen::Tensor<double, 3> tensor3;

class Geometry {
private:
  vector3 a1_;
  vector3 a2_;
  vector3 a3_;
  int n1;
  int n2;
  int n3;
  tensor3 epsr_;
  tensor3 mur_;

public:
  Geometry(vector3 t1, vector3 t2, vector3 t3, int n1, int n2, int n3);
  Geometry(const Geometry &other) = delete;
  Geometry(Geometry &&other) noexcept = delete;
  Geometry &operator=(const Geometry &other) = delete;
  Geometry &operator=(Geometry &&other) noexcept = delete;

  const vector3 &a1() const { return a1_; };
  const vector3 &a2() const { return a2_; };
  const vector3 &a3() const { return a3_; };

  vector3 b1();
  vector3 b2();
  vector3 b3();

  const tensor3 &eps_r() const { return epsr_; };
  const tensor3 &mu_r() const { return mur_; };

  void set_properties(
      double (*f)(double, double, double),
      double (*g)(double, double, double));
};
}; // namespace morpho

#endif // MORPHO_GEOMETRY_H_
