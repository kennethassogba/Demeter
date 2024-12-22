#include <iostream>
#include <vector>
#include <omp.h>
#include <Eigen/Dense>

#include "demeter/model.hpp"
#include "demeter/solve.hpp"

int main() {
  using namespace Demeter;
  using namespace Eigen;

  CheckOpenMP();

  Eigen::Matrix2f A, b;
  A << 2, -1, -1, 3; 
  b << 1, 2, 3, 1;
  std::cout << "Here is the matrix A:\n" << A << std::endl;
  std::cout << "Here is the right hand side b:\n" << b << std::endl;
  Eigen::Matrix2f x1 = A.ldlt().solve(b);
  std::cout << "The solution is:\n" << x1 << std::endl;

  Eigen::Matrix2f x2 = A.llt().solve(b);
  std::cout << "The solution is:\n" << x2 << std::endl;
  std::cout << '\n';

  LinearSolver LinSolver(A,b); 
  LinSolver.solve_llt();
  LinSolver.solve_ldtl();
  LinSolver.solve_PartialPivLu();
  std::cout << '\n';


  // Define variables
  int ngroups = 2;
  int naniso  = 0;
  int nmoms   = (naniso+1)*(naniso+1);

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
