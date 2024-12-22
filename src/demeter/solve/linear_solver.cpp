#include "linear_solver.hpp"

#include <cmath>
#include <iostream>

namespace Demeter {

void LinearSolver::solve_llt() {
  std::cout << "Standard Cholesky decomposition" << std::endl;
}

void LinearSolver::solve_ldtl() {
  std::cout << "Robust Cholesky decomposition with pivoting" << std::endl;
}

void LinearSolver::solve_PartialPivLu() {
 std::cout << "Partial LU pivoting" << std::endl;
}

}  // namespace Demeterr
