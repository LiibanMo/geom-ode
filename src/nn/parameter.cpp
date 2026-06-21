#include <cmath>
#include <random>

#include "geom_ode/nn.h"

namespace geom_ode {

template <typename T>
Parameter<T>::Parameter(const unsigned dim_out, const unsigned dim_in,
                        const ParamInitType& param_init_type, std::mt19937& gen)
    : shape({dim_out, dim_in}), size(dim_out * dim_in) {
  using enum ParamInitType::Method;
  using enum ParamInitType::Dist;

  const auto dist_type = param_init_type.dist;
  const auto method_type = param_init_type.method;

  this->weights.reserve(this->size);

  if (dist_type == Gaussian) {
    T std_dev = static_cast<T>(1.0);
    if (method_type == He) {
      std_dev = std::sqrt(static_cast<T>(2) / dim_in);
    } else if (method_type == LeCun) {
      std_dev = std::sqrt(static_cast<T>(1) / dim_in);
    } else if (method_type == Xavier) {
      std_dev = std::sqrt(static_cast<T>(6) / (dim_in + dim_out));
    }
    std::normal_distribution<T> gaussian_dist(0, std_dev);

    for (unsigned i = 0; i < this->size; i++) {
      this->weights.data[i] = gaussian_dist(gen);
    }

  } else if (dist_type == Uniform) {
    T bound = static_cast<T>(1.0);
    if (method_type == He) {
      bound = std::sqrt(static_cast<T>(6) / dim_in);
    } else if (method_type == LeCun) {
      bound = std::sqrt(static_cast<T>(3) / dim_in);
    } else if (method_type == Xavier) {
      bound = std::sqrt(static_cast<T>(6) / (dim_in + dim_out));
    }
    std::uniform_real_distribution<T> uniform_dist(-bound, bound);

    for (unsigned i = 0; i < this->size; i++) {
      this->weights[i] = uniform_dist(gen);
    }
  }
}

}  // namespace geom_ode
