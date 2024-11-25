#include "lattice.hpp"

namespace Demeter {
std::string Lattice::print() const {
  std::string s = "Lattice:\n";
  for (const auto& c : cells_) {
    s += c.get().print(false);
  }
  return s;
}

}  // namespace Demeter