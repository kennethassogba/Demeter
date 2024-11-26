#include "cell.hpp"

namespace Demeter {
void Cell::check() const {
  assert(side_ > 0.0);
  assert(materials_.size() == radii_.size() + 1);

  // check every material have same number of energy groups
  if (materials_.size() == 1) return;
  for (size_t i = 0; i < materials_.size() - 1; i++) {
    assert(materials_[i].get().NumGroups() ==
           materials_[i + 1].get().NumGroups());
  }

  // check radii: 0 < r[i] < r[i+1] < side
  if (radii_.empty()) return;
  assert(radii_[0] > 0.0);
  assert(radii_.back() < side_);
  for (size_t i = 0; i < radii_.size() - 1; i++) {
    assert(radii_[i] < radii_[i + 1]);
  }
}

std::string Cell::print(bool full) const {
  std::ostringstream ss;
  ss << "Cell " << name_ << " has " << radii_.size() << " rings and "
     << materials_.size() << " materials:";
  if (full)
    for (const auto& m : materials_) ss << "\n  * " << m.get().print();
  return ss.str();
}
}  // namespace Demeter