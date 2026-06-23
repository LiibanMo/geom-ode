#ifndef GEOM_ODE_DETAILS_H
#define GEOM_ODE_DETAILS_H

#include <torch/torch.h>

#include <cassert>
#include <concepts>

namespace geom_ode {

template <std::floating_point T>
struct Unsigned {
 private:
  T value;

 public:
  explicit Unsigned(T value) : value(value) {
    assert(value >= 0.0 && "value inputted is not non-negative");
  }

  operator T() const { return value; }
};

template <std::floating_point T>
struct TorchTypeMapping;

template <>
struct TorchTypeMapping<float> {
  static constexpr torch::ScalarType value = torch::kFloat32;
};

template <>
struct TorchTypeMapping<double> {
  static constexpr torch::ScalarType value = torch::kFloat64;
};

}  // namespace geom_ode

#endif
