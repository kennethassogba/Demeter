#include "lattice.hpp"

namespace Demeter {
std::string Lattice::print() const {
  std::ostringstream s;
  s << "Lattice:" << name_ << "\n";
  // print names in a matrix view
  // for (const auto& c : components_) {
  // }
  return s.str();
}

}  // namespace Demeter