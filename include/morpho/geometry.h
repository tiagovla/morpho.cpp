#ifndef MORPHO_GEOMETRY_H_
#define MORPHO_GEOMETRY_H_

#include "unsupported/Eigen/CXX11/Tensor"
#include <tuple>

typedef std::tuple<float, float, float> tuple3f;

namespace morpho {

class Geometry {
private:
  tuple3f t1;
  tuple3f t2;
  tuple3f t3;
  int N1;
  int N2;
  int N3;
  Eigen::Tensor<float, 3> eps_r;
  Eigen::Tensor<float, 3> mu_r;

public:
  Geometry(tuple3f t1, tuple3f t2, tuple3f t3, int N1, int N2, int N3);
  Geometry(const Geometry &other) = delete;
  Geometry(Geometry &&other) noexcept = delete;
  Geometry &operator=(const Geometry &other) = delete;
  Geometry &operator=(Geometry &&other) noexcept = delete;

  std::tuple<float, float, float> get_t1() { return this->t1; };
  std::tuple<float, float, float> get_t2() { return this->t2; };
  std::tuple<float, float, float> get_t3() { return this->t3; };
};
}; // namespace morpho

#endif // MORPHO_GEOMETRY_H_
