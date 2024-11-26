#include "lattice.hpp"

#include <cmath>

namespace Demeter {
void Lattice::check() const {
  // check if the number of component is a perfect square
  auto n = components_.size();
  auto root = static_cast<decltype(n)>(std::round(std::sqrt(n)));
  if (root * root != n) {
    throw std::runtime_error("Number of cell/lattice is not a perfect square");
  }
}

std::string Lattice::print() const {
  std::ostringstream s;
  s << "Lattice: " << name_;
  // print names in a matrix view
  auto n = components_.size();
  auto root = static_cast<size_t>(std::round(std::sqrt(n)));
  for (size_t i = 0; i < root; ++i) {
    s << '\n';
    for (size_t j = 0; j < root; ++j) {
      std::visit([&](auto&& v) { s << v.get().name() << " "; },
                 components_[i * root + j]);
    }
  }

  return s.str();
}

}  // namespace Demeter