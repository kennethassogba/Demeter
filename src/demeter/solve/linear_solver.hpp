#pragma once

#include <Eigen/Core>
#include <Eigen/Dense>

#include "methods.hpp"
#include "demeter/common.hpp"
#include "demeter/model/lattice.hpp"

namespace Demeter {

class LinearSolver {
 public: 
 
  LinearSolver(const Eigen::Matrix2f& A, const Eigen::Matrix2f& b) 
      : A_(A), b_(b) {
      // Initialisation par défaut
      std::cout << "Initialisation constructeur" << std::endl;
  } 

  void solve_llt();
  void solve_ldtl();
  void solve_PartialPivLu();	

 private:
  Eigen::Matrix2f A_; 
  Eigen::Matrix2f b_;
  
  double tolerance = 1e-5;
  
};
} // namespace Demeter
