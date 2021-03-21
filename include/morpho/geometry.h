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
  vector3 t1;
  vector3 t2;
  vector3 t3;
  int n1;
  int n2;
  int n3;
  tensor3 epsr;
  tensor3 mur;

public:
  Geometry(vector3 t1, vector3 t2, vector3 t3, int n1, int n2, int n3);
  Geometry(const Geometry &other) = delete;
  Geometry(Geometry &&other) noexcept = delete;
  Geometry &operator=(const Geometry &other) = delete;
  Geometry &operator=(Geometry &&other) noexcept = delete;

  vector3 get_t1() { return this->t1; };
  vector3 get_t2() { return this->t2; };
  vector3 get_t3() { return this->t3; };

  vector3 get_T1();
  vector3 get_T2();
  vector3 get_T3();

  const tensor3 &get_eps_r() const { return this->epsr; };
  const tensor3 &get_mu_r() const { return this->mur; };

  void set_properties(double (*f)(double, double, double),
                      double (*g)(double, double, double));
};
}; // namespace morpho

#endif // MORPHO_GEOMETRY_H_
