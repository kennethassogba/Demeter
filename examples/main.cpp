#include <iostream>
#include <vector>
#include <omp.h>
#include <Eigen/Dense>

#include "demeter/model.hpp"

int main() {
  using namespace Demeter;

  CheckOpenMP();

  ArrayXd sigma_t{{0.222222, 0.833333}};
  ArrayXXd sigma_s{{0.00, 0.02}, {0.00, 0.00}};
  ArrayXd sigma_a{{0.010120, 0.080032}};
  ArrayXd sigma_f{{0., 0.135}};
  ArrayXd nu_sigma_f{{0., 0.135}};
  ArrayXd chi{{1., 0.}};

  Material uo2(sigma_t, sigma_s, sigma_a, sigma_f, nu_sigma_f, chi, "UO2");
  std::cout << uo2 << std::endl;

  Cell uo2_cell(1.0, uo2, "UO2");
  std::cout << uo2_cell << std::endl;

  // Lattice assm00{{uo2_cell, uo2_cell}};
  // Lattice assm01{{uo2_cell, uo2_cell}};
  // Lattice assm10{{uo2_cell, uo2_cell}};
  // Lattice assm11{{uo2_cell, uo2_cell}};

  // Lattice core{{assm00, assm01, assm10, assm11}};

  return 0;
}