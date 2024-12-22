#include "solver.hpp"

#include <cmath>
#include <iostream>

namespace Demeter {

/**
 * Go straitforward for a first implementation
 * TODO
 * Get geo dim, ncells, ngroups
 */
void Solver::solve() {
  const auto ndof_per_group = 1;         // ncells * ndof_per_cell
  const auto ndof = ndof_per_group * 1;  // ngroups * ndofpergroup;
  flux_ = ArrayXd::Ones(ndof);

  // Calcul des sources
  // Methode de la puissance iteree
}
}  // namespace Demeter
