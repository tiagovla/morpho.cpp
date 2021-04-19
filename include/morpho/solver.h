#ifndef MORPHO_SOLVER_H_
#define MORPHO_SOLVER_H_

#include "morpho/brillouinzone.h"
#include "morpho/geometry.h"
#include "morpho/types.h"

namespace morpho {
class Solver3D {
private:
  const morpho::Geometry &geo;
  const morpho::BrillouinZonePath &path;
  int P, Q, R;
  tensor3d eps_rc;
  tensor3d mu_rc;

public:
  Solver3D(
      morpho::Geometry &geometry,
      morpho::BrillouinZonePath &path,
      int P,
      int Q,
      int R);
};

}; // namespace morpho

#endif // MORPHO_SOLVER_H_
