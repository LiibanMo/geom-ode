#include "geom_ode/geometry.h"

namespace geom_ode {

template <typename T, unsigned dim>
TangentVector<T, dim> operator*(const TangentVector<T, dim>& tangent_vector,
                                float scalar) {
  TangentVector<T, dim> result_vector;

  for (unsigned i = 0; i < dim; i++) {
    result_vector.vector[i] = scalar * tangent_vector.vector[i];
  }

  return result_vector;
}

}  // namespace geom_ode
