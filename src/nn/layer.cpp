#include "geom_ode/detail/nn_internal.h"

namespace geom_ode {

template <typename T>
Layer<T>::Layer(const unsigned n_params, const unsigned dim_out,
                const unsigned dim_in, const ParamInitType& param_init_type,
                std::mt19937& gen)
    : n_params(n_params) {
  this->params.reserve(n_params);

  for (unsigned i = 0; i < n_params; i++) {
    this->params.push_back(Parameter<T>(dim_out, dim_in, param_init_type, gen));
  }
}

}  // namespace geom_ode
