#pragma once

#include "demeter/common.hpp"
#include "demeter/model/lattice.hpp"

namespace Demeter {

/**
 * @brief Possible boundary condition
 */
enum class BoundaryCondition { Vacuum, Reflection };

/**
 * @brief Possible side of a lattice
 */
enum class BoundarySide {
  xmin,
  xmax,
  ymin,
  ymax,
  zmin,
  zmax
};  // TODO diagonal

}  // namespace Demeter