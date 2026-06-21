#include "geom_ode/solver.h"

namespace geom_ode {

template <typename T, unsigned dim>
void RungeKutta<T, dim>::solve(const VectorField<T, dim>& field,
                               float time_step, unsigned n_iter) {
  for (unsigned i = 0; i < n_iter; i++) {
    const VectorField<T, dim>& k1 = time_step * field();
  }
}

}  // namespace geom_ode
