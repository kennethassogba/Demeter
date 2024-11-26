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

  Material UO2(sigma_t, sigma_s, sigma_a, sigma_f, nu_sigma_f, chi, "UO2");

  sigma_t = {{0.111111, 0.444443}};
  sigma_s = {{0.10, 0.02}, {0.20, 0.05}};
  sigma_a = {{0.040120, 0.010032}};
  sigma_f = {{0., 0.635}};
  nu_sigma_f = {{0., 0.535}};
  chi = {{1., 0.}};

  Material M4(sigma_t, sigma_s, sigma_a, sigma_f, nu_sigma_f, chi, "M4");

  sigma_t = {{0.11434, 0.41343}};
  sigma_s = {{0.70, 0.02}, {0.50, 0.25}};
  sigma_a = {{0.041340, 0.0113432}};

  Material H2O(sigma_t, sigma_s, sigma_a, "H2O");

  for (const auto* m : {&UO2, &M4, &H2O}) std::cout << *m << '\n';

  double side = 1.0;

  Cell UO2cell(side, {0.5}, {UO2, H2O}, "UO2");

  Cell H2Ocell(side, H2O, "H2O");

  for (const auto* c : {&UO2cell, &H2Ocell}) std::cout << *c << '\n';

  Lattice assm00{{UO2cell, H2Ocell}, "assm00"};
  // Lattice assm01{{uo2_cell, uo2_cell}};
  // Lattice assm10{{uo2_cell, uo2_cell}};
  // Lattice assm11{{uo2_cell, uo2_cell}};

  // Lattice core{{assm00, assm01, assm10, assm11}};

  return 0;
}