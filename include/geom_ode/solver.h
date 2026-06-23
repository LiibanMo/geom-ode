#ifndef GEOM_ODE_SOLVER_H
#define GEOM_ODE_SOLVER_H

#include "geom_ode/geometry.h"

namespace geom_ode {

template <unsigned Dim>
class RungeKutta {
 public:
  void solve(const VectorField<Dim>& field, float time_step, unsigned n_iter);
};

}  // namespace geom_ode

#endif
