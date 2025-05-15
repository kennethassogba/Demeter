#pragma once

#include <Eigen/Core>
#include <Eigen/Dense>

#include "methods.hpp"
#include "demeter/common.hpp"
#include "demeter/model/lattice.hpp"

namespace Demeter {

/**
 * @class LinearSolver
 * @brief The class different eigen solvers to solve
 * linear system of type Ax = b.
 */
class LinearSolver {
 public:
  /**
   * @brief The constructor take the matrix of the linear system
   * and the second member as entry.
   * @param A Matrix of the linear system.
   * @param b Second member of the linear system
   */
  LinearSolver(const Eigen::Matrix2f& A, const Eigen::Matrix2f& b)
      : A_(A), b_(b) {
    // Initialisation par défaut
    std::cout << "Initialisation constructeur" << std::endl;
  }

  /**
   * @brief Standard Cholesky decomposition.
   * @return void.
   */
  void solve_llt();

  /**
   * @brief Robust Cholesky decomposition with pivoting.
   * @return void.
   */
  void solve_ldtl();

  /**
   * @brief Partial LU pivoting.
   * @return void.
   */
  void solve_PartialPivLu();

 private:
  Eigen::Matrix2f A_;
  Eigen::Matrix2f b_;

  // double tolerance_ = 1e-5;
};
}  // namespace Demeter
