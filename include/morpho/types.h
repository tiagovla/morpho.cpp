
#ifndef MORPHO_TYPES_H_
#define MORPHO_TYPES_H_

#include "Eigen/Dense"
#include "unsupported/Eigen/CXX11/Tensor"

namespace morpho {
typedef Eigen::Vector<double, 3> vector3d;
typedef Eigen::Tensor<double, 3> tensor3d;
} // namespace morpho

#endif // MORPHO_TYPES_H_
