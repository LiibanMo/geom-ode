#include <vector>

#include "geom_ode/nn.h"

namespace geom_ode {

template <typename T>
Tensor<T>::Tensor(std::vector<T>& data, std::vector<unsigned> shape)
    : data(data), shape(shape), ndim(shape.size()) {
  this->size = 1;
  for (unsigned element : shape) {
    this->size *= element;
  }

  this->strides = std::vector<T>(this->ndim, 1);
  for (unsigned i = this->ndim - 2; i >= 0; i--) {
    this->strides[i] = this->strides[i - 1] * shape[i - 1];
  }
}

}  // namespace geom_ode
