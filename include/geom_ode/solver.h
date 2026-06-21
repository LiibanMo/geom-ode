#ifndef GEOM_ODE_SOLVER_H
#define GEOM_ODE_SOLVER_H

#include "nn.h"

namespace geom_ode {

template <typename T, unsigned dim>
class RungeKutta {
 public:
  void solve(const VectorField<T, dim>& field, float time_step,
             unsigned n_iter);
};

}  // namespace geom_ode

#endif
