#include <torch/torch.h>

#include "geom_ode/geometry.h"

namespace geom_ode {

template <unsigned Dim>
VectorField<Dim>::VectorField(const unsigned n_layers) {}

template <unsigned Dim>
TangentVector<Dim> operator*(const TangentVector<Dim>& tangent_vector,
                             float scalar) {
  TangentVector<Dim> result_vector;

  for (unsigned i = 0; i < Dim; i++) {
    result_vector.vector[i] = scalar * tangent_vector.vector[i];
  }

  return result_vector;
}

}  // namespace geom_ode
