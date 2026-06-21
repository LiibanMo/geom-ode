#ifndef GEOM_ODE_GEOMETRY_H
#define GEOM_ODE_GEOMETRY_H

#include <array>

namespace geom_ode {

template <typename T, unsigned dim>
class Point {
 public:
  std::array<T, dim> coordinates{};
};

template <typename T, unsigned dim>
struct PhasePoint {
  Point<T, dim> point;
  float time;
};

template <typename T, unsigned dim>
class TangentVector {
 public:
  std::array<T, dim> components{};

  friend TangentVector operator*(const TangentVector<T, dim>& tangent_vector,
                                 float scalar);
};

template <typename T, unsigned dim>
class Manifold {
 public:
  float exp_map(const Point<T, dim>& point, const TangentVector<T, dim>& input);

  float log_map(const Point<T, dim>& point, const Point<T, dim>& input);
};

}  // namespace geom_ode

#endif
