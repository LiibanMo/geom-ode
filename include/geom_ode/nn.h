#ifndef GEOM_ODE_NN_H
#define GEOM_ODE_NN_H

#include <random>
#include <vector>

#include "geom_ode/geometry.h"

namespace geom_ode {

template <typename T>
class Tensor {
 public:
  std::vector<T> data;
  unsigned size;
  unsigned ndim;
  std::vector<unsigned> strides;
  std::vector<unsigned> shape;

  Tensor(std::vector<T>& data, std::vector<unsigned> shape);
};

struct ParamInitType {
  enum class Dist {
    Gaussian,
    Uniform,
  };
  enum class Method {
    He,      // For ReLU variants
    LeCun,   // For SELU & Tanh variants
    Xavier,  // For Sigmoid & Tanh variants
  };

  Dist dist;
  Method method;
};

template <typename T>
class Parameter {
 public:
  std::array<unsigned, 2> shape;
  unsigned size;
  Tensor<T> weights;

  Parameter(const unsigned dim_out, const unsigned dim_in,
            const ParamInitType& param_init_type, std::mt19937& gen);
};

template <typename T>
class Layer {
 public:
  std::vector<std::shared_ptr<Parameter<T>>> params;

  Layer(const unsigned n_params, const unsigned dim_out, const unsigned dim_in,
        const ParamInitType& param_init_type, std::mt19937& gen);

  virtual void apply();
};

template <typename T>
class Linear : public Layer<T> {
 public:
  unsigned n_params;
  std::vector<Parameter<T>> params;
};

template <typename T>
class MLP {
 public:
  unsigned n_layers;
  ParamInitType param_init_type;
  std::vector<Layer<T>> layers;

  MLP(const unsigned n_layers, const ParamInitType param_init_type);
};

template <typename T, unsigned dim>
class VectorField {
 public:
  unsigned n_layers;
  MLP<T> nn;

  VectorField(const unsigned n_layers);

  TangentVector<T, dim> apply(const Point<T, dim>& point, const float time) {
    return TangentVector<T, dim>();
  }
};

}  // namespace geom_ode

#endif
