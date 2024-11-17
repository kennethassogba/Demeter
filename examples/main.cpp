#include <iostream>
#include <vector>
#include <omp.h>
#include <Eigen/Dense>
#include "demeter/model/material.hpp"

void CheckOpenMP() {
#if defined(_OPENMP)
  unsigned num_threads = 0;
#pragma omp parallel reduction(+ : num_threads)
  num_threads += 1;
  std::cerr << "OpenMP version " << _OPENMP << " number of threads "
            << num_threads << '\n';
#endif
}

int main() {
  CheckOpenMP();

  using Eigen::MatrixXd;

  MatrixXd m(2, 2);
  m(0, 0) = 3;
  m(1, 0) = 2.5;
  m(0, 1) = -1;
  m(1, 1) = m(1, 0) + m(0, 1);
  std::cout << m << std::endl;

  using Eigen::ArrayXd;
  using Eigen::ArrayXXd;

  ArrayXd sigma_t{{0.222222, 0.833333}};
  ArrayXd D = 1. / (3. * sigma_t);
  ArrayXd sigma_a{{0.010120, 0.080032}};
  ArrayXd nu_sigma_f{{0., 0.135}};
  ArrayXd sigma_f{{0., 0.135}};
  ArrayXd chi{{1., 0.}};
  ArrayXXd sigma_s{{0.00, 0.02}, {0.00, 0.00}};

  Demeter::Material uo2(sigma_t, sigma_s, sigma_a, sigma_f, nu_sigma_f, chi,
                        "UO2");

  return 0;
}