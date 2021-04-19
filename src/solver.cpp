
#include "morpho/solver.h"

morpho::Solver3D::Solver3D(
    morpho::Geometry &geometry,
    morpho::BrillouinZonePath &path,
    int P,
    int Q,
    int R)
    : geo(geometry), path(path) {
  this->P = P;
  this->Q = Q;
  this->R = R;
};
