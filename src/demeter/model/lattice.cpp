#include "lattice.hpp"

namespace Demeter {
std::string Lattice::print() const {
  std::ostringstream s;
  s << "Lattice:" << name_ << "\n";
  // if cell, print the cells, else print the cells inside the lattices
  
  // for (const auto& c : components_) {
  //   s += c.get().print(false);
  // }
  return s.str();
}

}  // namespace Demeter