#include "solver.hpp"

#include <cmath>
#include <iostream>

namespace Demeter {

/**
 * TODO
 * Mesh
 * Num methods
 * Build matrices
 */

/**
 * Go straitforward for a first implementation
 * TODO
 * Get geo dim, ncells, ngroups
 */
void Solver::solve() {
  const auto ndof_per_group = 1;         // ncells * ndof_per_cell
  const auto ndof = ndof_per_group * 1;  // ngroups * ndofpergroup;
  flux_ = ArrayXd::Ones(ndof);
  auto first_thermal_group_ = 1;  // todo

  // Calcul des sources
  // Methode de la puissance iteree
  // Initialisation of keff and flux
  unsigned iter_outer(0);    // ito
  unsigned iter_thermal(0);  // itt
  unsigned max_iter_outer_(100);
  unsigned max_iter_thermal_(100);
  unsigned nbgroup(4);

  while (iter_outer < max_iter_outer_) {
    // outer
    /*and Fu and keff have not converged*/
    // Compute fission source
    // fission_source^g,(n) =  (1/keff) F u^(n) in group (move to inner)
    for (unsigned g = 0; g < first_thermal_group_; g++) {  // fast neutrons
      // inner(g)
      // compute source Qg = Hg u^(n+1) + fission_source^g,(n) in group
      // solve(g) Ag ug = Qg
    }

    while (iter_thermal < max_iter_thermal_) {
      // thermal
      /* and Hup u not converged */
      // Compute up-scattering source Hup^g,(t) = Hup^g u^(n+1, t)
      for (unsigned g = first_thermal_group_; g < nbgroup; g++) {
        //
      }
      iter_thermal++;
    }

    iter_outer++;
  }
  // Print end reason
}
}  // namespace Demeter