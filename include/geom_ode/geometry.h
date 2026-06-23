#ifndef GEOM_ODE_GEOMETRY_H
#define GEOM_ODE_GEOMETRY_H

#include <torch/torch.h>

#include <array>
#include <concepts>

#include "geom_ode/details/types.h"

namespace geom_ode {

template <std::floating_point T, unsigned Dim>
class Point {
 private:
  torch::Tensor coord_;

 public:
  torch::Tensor coord(torch::Tensor new_coord) { this->coord_ = new_coord; }
  torch::Tensor coord() const { return this->coord_; }
};

template <std::floating_point T, unsigned Dim>
struct PhasePoint {
  Point<T, Dim> point;
  Unsigned<float> time;
};

template <std::floating_point T, unsigned Dim>
class TangentVector {
 public:
  std::array<T, Dim> components{};

  friend TangentVector operator*(const TangentVector<T, Dim>& tangent_vector,
                                 T scalar);
  friend TangentVector operator*(T scalar,
                                 const TangentVector<T, Dim>& tangent_vector);
};

template <typename V, typename T, unsigned Dim>
concept NeuralVectorField =
    requires(V vector_field, const Point<T, Dim>& p, const Unsigned<T>& t) {
      requires std::floating_point<T>;

      { vector_field.forward(p, t) } -> std::same_as<TangentVector<T, Dim>>;
    };

template <typename M, typename T, unsigned Dim>
concept RiemannianManifold =
    requires(M manifold, const Point<T, Dim>& p, const Point<T, Dim>& x,
             const TangentVector<T, Dim>& v, const Unsigned<T>& t) {
      requires std::floating_point<T>;
      { manifold.exp_map(p, v, t) } -> std::same_as<Point<T, Dim>>;
      { manifold.log_map(p, x, t) } -> std::same_as<TangentVector<T, Dim>>;
    };

}  // namespace geom_ode

#endif
