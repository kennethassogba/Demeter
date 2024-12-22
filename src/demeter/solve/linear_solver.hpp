#pragma once

#include <Eigen/Core>

#include "methods.hpp"
#include "demeter/common.hpp"
#include "demeter/model/lattice.hpp"

namespace Demeter {

class LinearSolver {
 public: 
 
  // Constructeur vide
  Exemple() {
      // Initialisation par défaut
      std::cout << "Constructeur vide" << std::endl;
  } 

  void solve_llt();
  void solve_ldtl();
  void solve_PartialPivLu()	

 private:
  double tolerance = 1e-5;
  
};
} // namespace Demeter
