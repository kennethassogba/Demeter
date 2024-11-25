#include "cell.hpp"

namespace Demeter {
void Cell::check() const {
  assert(side_ > 0.0);
  assert(materials_.size() == radii_.size() + 1);
}

std::string Cell::print() const {
  std::ostringstream ss;
  ss << "Cell " << name_ << " has " << radii_.size() << " rings and "
     << materials_.size() << " materials";
  return ss.str();
}
}  // namespace Demeter