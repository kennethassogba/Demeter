#include "linear_solver.hpp"

#include <cmath>
#include <iostream>
#include <Eigen/Dense>

namespace Demeter {

void LinearSolver::solve_llt() {
  std::cout << "Method: Standard Cholesky decomposition" << std::endl;
  Eigen::Matrix2f x1 = A_.llt().solve(b_);
  std::cout << "The solution is:\n" << x1 << std::endl;
}

void LinearSolver::solve_ldtl() {
  std::cout << "Method: Robust Cholesky decomposition with pivoting" << std::endl;
  Eigen::Matrix2f x1 = A_.ldlt().solve(b_);
  std::cout << "The solution is:\n" << x1 << std::endl;
}

void LinearSolver::solve_PartialPivLu() {
 std::cout << "Method: Partial LU pivoting" << std::endl;
 Eigen::Matrix2f x1 = A_.partialPivLu().solve(b_);
 std::cout << "The solution is:\n" << x1 << std::endl;
}
}  // namespace Demeterr
