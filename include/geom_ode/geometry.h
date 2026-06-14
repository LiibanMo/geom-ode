#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <array>

namespace geom_ode {

template <typename T, unsigned dim>
class Point {
 public:
  std::array<T, dim> point{};
};

template <typename T, unsigned dim>
class TangentVector {
 public:
  std::array<T, dim> vector{};

  friend TangentVector operator*(const TangentVector<T, dim>& tangent_vector,
                                 float scalar);
};

template <typename T, unsigned dim>
class Manifold {
 public:
  float exp_map(const Point<T, dim>& point,
                const TangentVector<T, dim>& vector);
};

}  // namespace geom_ode

#endif
