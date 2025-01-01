#include <iostream>
#include <vector>
#include <omp.h>
#include <Eigen/Dense>

#include "demeter/model.hpp"
#include "demeter/solve.hpp"
#include "demeter/quadrature.hpp"

int main() {
  using namespace Demeter;
  using namespace Eigen;

  CheckOpenMP();

  // Define variables
  constexpr size_t nteta   = 48;
  constexpr size_t ngroups = 2;
  constexpr size_t naniso  = 0;
  constexpr size_t nmoms   = (naniso+1)*(naniso+1);

  // Test sum of gaussian weights
  GaussLegendre<nteta> gauss;
  gauss.getweights();
  
  ArrayXd weights(nteta/2);
  weights = gauss.getweights();
  std::cout << weights.sum();
  std::cout << "\n";

  // Test power iteration solver
  // 1st problem, vp : (5, 2)
  Eigen::MatrixXd A1(2,2);
  Eigen::VectorXd  x1(2);
  Eigen::VectorXd  y1(2);
  
  A1 << 4, 1,
        1, 3;
 
  PowerIteration PowIteA(A1);
  PowIteA.solve(); 

  // 2nd problem, vp : (11.25, 7.34, 5.11, 4.30)
  Eigen::MatrixXd B1(4,4);
  B1 << 10, 2, 0, 0,
         2, 8, 1, 0,
         0, 1, 6, 1,
         0, 0, 1, 4;

  PowerIteration PowIteB(B1);
  PowIteB.solve(); 

  // 3rd problem
  // vp : (11.34, 11.28, 8.56, 6.68, 4.84, 2.20)
  Eigen::MatrixXd C1(6,6);
  C1 << 12,  3, 0, 0, 0, 0, 
         3, 11, 2, 0, 0, 0,
         0,  2, 9, 1, 0, 0,
         0,  0, 1, 7, 1, 0,
         0,  0, 0, 1, 5, 1,
         0,  0, 0, 0, 1, 3;

  PowerIteration PowIteC(C1);
  PowIteC.solve(); 

  // Test linear solvers
  Eigen::Matrix2f A, b;
  A << 2, -1, -1, 3; 
  b << 1, 2, 3, 1;
  
  LinearSolver LinSolver(A,b); 
  LinSolver.solve_llt();
  LinSolver.solve_ldtl();
  LinSolver.solve_PartialPivLu();
  std::cout << '\n';

  // Define cross sections
  ArrayXd  sigma_t(ngroups);
  ArrayXXd sigma_s(ngroups,ngroups);
  ArrayXd  sigma_a(ngroups); 
  ArrayXd  sigma_f(ngroups);
  ArrayXd  nu_sigma_f(ngroups);
  ArrayXd  chi(ngroups);   

  // Define UO2 material
  sigma_t << 0.22222, 0.88888;
  sigma_s << 0.00, 0.02, 
             0.00, 0.00;
  sigma_a << 0.010120, 0.080032;
  sigma_f << 0., 0.135;
  nu_sigma_f << 0., 0.135;
  chi << 1., 0.;   
  Material UO2(sigma_t, sigma_s, sigma_a, sigma_f, nu_sigma_f, chi, "UO2");

  // Define M4 material
  sigma_t << 0.111111, 0.444443;
  sigma_s << 0.10, 0.02,
             0.20, 0.05;
  sigma_a << 0.040120, 0.010032;
  sigma_f << 0., 0.635;
  nu_sigma_f << 0., 0.535;
  chi << 1., 0.;
  Material M4(sigma_t, sigma_s, sigma_a, sigma_f, nu_sigma_f, chi, "M4");

  // Define H20 material
  sigma_t << 0.11434, 0.41343;
  sigma_s << 0.70, 0.02,
             0.50, 0.25;
  sigma_a << 0.041340, 0.0113432;
  Material H2O(sigma_t, sigma_s, sigma_a, "H2O");

  for (const auto* m : {&UO2, &M4, &H2O}) std::cout << *m << '\n';
  std::cout << '\n';

  // Define cells
  double side = 1.0;
  Cell UO2cell(side, {0.5}, {UO2, H2O}, "UO2");
  Cell M4cell(side, {0.4, 0.6}, {M4, UO2, H2O}, "M4");
  Cell H2Ocell(side, H2O, "H2O");

  for (const auto* c : {&UO2cell, &M4cell, &H2Ocell}) std::cout << *c << '\n';
  std::cout << '\n';

  // Define assemblies
  Lattice assm00{{UO2cell, H2Ocell, UO2cell, H2Ocell}, "assm00"};
  Lattice assm01{{M4cell, UO2cell, H2Ocell, H2Ocell}, "assm01"};
  Lattice assm10{{UO2cell, H2Ocell, UO2cell, M4cell}, "assm10"};
  Lattice assm11{{UO2cell, M4cell, H2Ocell, UO2cell}, "assm11"};

  // Define core
  Lattice core{{assm00, assm01, assm10, assm11}, "core"};
  std::cout << core << '\n';

  //// Set boundary conditions
  ////core.BoundaryCondition(BoundarySide::xmin, BoundaryCondition::Vacuum);
  ////core.BoundaryCondition(BoundarySide::xmax, BoundaryCondition::Reflection);

  ////// Define solver and solve the transport equation
  ////AngularMethod sn (AngularMethod::Type::SN, 2);
  ////SpatialMethod dg (SpatialMethod::Type::DG, 1);
  ////Solver solver(core, sn, dg);
  ////solver.solve();

  return 0;
}
