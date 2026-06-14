#ifndef SOLVER_H
#define SOLVER_H

#include "nn.h"

namespace geom_ode {

template <typename T>
class RungeKutta {
 public:
  void solve(const VectorField& field, float time_step, unsigned n_iter);
};

}  // namespace geom_ode

#endif
