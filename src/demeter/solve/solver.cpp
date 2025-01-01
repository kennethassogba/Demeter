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

void PowerIteration::solve() {
 
  size_t size;
  int nb_ite;
  double lambda_k1;
  double lambda_k2;
  double error_eigvalue;
  
  // Initialization
  nb_ite = 0;
  lambda_k1 = 1;
  lambda_k2 = 0;
  error_eigvalue = 10;
  size = A_.rows();
  Eigen::VectorXd x1 = Eigen::ArrayXd::Random(size);
  Eigen::VectorXd x2 = Eigen::ArrayXd::Ones(size);

  while (error_eigvalue >= tol_eigvalue_) {
    // Update
    nb_ite++;
    x2 = A_ * x1;
    lambda_k2 = x2.dot(x1) / x1.dot(x1);
    x1 = x2;

    // Convergence test
    error_eigvalue = std::abs((lambda_k2 - lambda_k1) / lambda_k2);
    lambda_k1 = lambda_k2;
  }
  
  std::cout << "Eigenvalue: " << lambda_k2 << std::endl;
  std::cout << "Iterations: " << nb_ite   << std::endl;
}
}  // namespace Demeter
