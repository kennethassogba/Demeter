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
  double lambda_k1;
  double lambda_k2;
  double error_eigvalue;
  
  // Initialization
  lambda_k1 = 0;
  lambda_k2 = 0;
  size = A_.rows();
  Eigen::ArrayXd x1 = Eigen::ArrayXd::Ones(size);
  Eigen::ArrayXd x2 = Eigen::ArrayXd::Ones(size);

  // Iterations
  while (error_eigvalue >= tol_eigvalue_ ) {

     // Vector update 
     // x2 = A_ * x1;
     // x2 = x2 / |x2|

     // Value update 
     //lambda_k1 = 1;     
     //lambda_k2 = <x2,x1> / (<x1,x1>;
     //x2 = x2 / |x2|
     
     // Convergence test
     error_eigvalue = lambda_k2-lambda_k1;
     std::cout << "Lambda: " << lambda_k2 << std::endl;
     } 

  std::cout << "Eigenvalue: " << lambda_k2 << std::endl;

}
}  // namespace Demeter
