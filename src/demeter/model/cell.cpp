#include "cell.hpp"

namespace Demeter {
void Cell::check() const { assert(materials_.size() == radii_.size() + 1); }
}  // namespace Demeter