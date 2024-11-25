#include <iostream>
#include <vector>
#include <omp.h>
#include <Eigen/Dense>
#include "demeter/model/material.hpp"

int main() {
  using namespace Demeter;

  CheckOpenMP();

  ArrayXd sigma_t{{0.222222, 0.833333}};
  ArrayXd D = 1. / (3. * sigma_t);
  ArrayXd sigma_a{{0.010120, 0.080032}};
  ArrayXd nu_sigma_f{{0., 0.135}};
  ArrayXd sigma_f{{0., 0.135}};
  ArrayXd chi{{1., 0.}};
  ArrayXXd sigma_s{{0.00, 0.02}, {0.00, 0.00}};

  Material uo2(sigma_t, sigma_s, sigma_a, sigma_f, nu_sigma_f, chi, "UO2");

  std::cout << uo2 << std::endl;

  return 0;
}