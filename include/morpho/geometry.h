#ifndef MORPHO_GEOMETRY_H_
#define MORPHO_GEOMETRY_H_

namespace morpho {

class Geometry {
private:
  int P;
  int Q;
  int R;

public:
  Geometry(int P, int Q, int R);
  int getP() { return this->P; }
  int getQ() { return this->Q; }
  int getR() { return this->R; }
};

}; // namespace morpho

#endif // MORPHO_GEOMETRY_H_
