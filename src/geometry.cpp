#include "morpho/geometry.h"

morpho::Geometry::Geometry(std::tuple<float, float, float> t1,
                           std::tuple<float, float, float> t2,
                           std::tuple<float, float, float> t3, int N1, int N2,
                           int N3) {
  this->t1 = t1;
  this->t2 = t2;
  this->t3 = t3;
  this->N1 = N1;
  this->N2 = N2;
  this->N3 = N3;
}
