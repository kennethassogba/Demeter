#include <iostream>
#include <vector>
#include <Eigen/Core>

int main() {
  using Eigen::ArrayXd;
  using Eigen::ArrayXXd;

  ArrayXd sigma_t{{0.222222, 0.833333}};
  ArrayXd D = 1. / (3. * sigma_t);
  ArrayXd sigma_a{{0.010120, 0.080032}};
  ArrayXd nu_sigma_f{{0., 0.135}};
  ArrayXd sigma_f{{0., 0.135}};
  ArrayXd chi{{1., 0.}};
  ArrayXXd sigma_s{{0.00, 0.02}, {0.00, 0.00}};
  // auto a1 = Material(D, Ea, Es, Ef, vEf, chi, "A1");

  // sigma_t = {0.222222, 0.833333};
  // vec D2 = 1. / (3. * sigma_t);
  // sigma_a = {0.010120, 0.085032};
  // nusigma_f = {0., 0.135};
  // sigma_f = {0., 0.135};
  // chi = {1., 0.};
  // sigma_s = {{0.00, 0.02}, {0.00, 0.00}};
  // auto a2 = Material(D, Ea, Es, Ef, vEf, chi, "A2");

  // sigma_t = {0.222222, 0.833333};
  // vec D3 = 1. / (3. * sigma_t);
  // sigma_a = {0.010120, 0.130032};
  // nusigma_f = {0., 0.135};
  // sigma_f = {0., 0.135};
  // chi = {1., 0.};
  // sigma_s = {{0.00, 0.02}, {0.00, 0.00}};
  // auto a3 = Material(D, Ea, Es, Ef, vEf, chi, "A3");
  // Faire une cellulle carre qui contient le materiaux et qui est maillable

  // sigma_t = {0.166667, 1.111111};
  // vec D4 = 1. / (3. * sigma_t);
  // sigma_a = {0.000160, 0.010024};
  // sigma_s = {{0.00, 0.04}, {0.00, 0.00}};
  // auto a4 = Material(D, Ea, Es, "Aauto 4");

  // Lattice constituee de cellule
  // Lattice2d core {a3, a2, a2, a2, a3, a2, a2, a1, a4,
  //         a2, a2, a2, a2, a2, a2, a2, a1, a4,
  //         a2, a2, a2, a2, a2, a2, a1, a1, a4,
  //         a2, a2, a2, a2, a2, a2, a1, a4, a4,
  //         a3, a2, a2, a2, a3, a1, a1, a4, 0.,
  //         a2, a2, a2, a2, a1, a1, a4, a4, 0.,
  //         a2, a2, a1, a1, a1, a4, a4, 0., 0.,
  //         a1, a1, a1, a4, a4, a4, 0., 0., 0.,
  //         a4, a4, a4, a4, 0., 0., 0., 0., 0.};

  // auto dx = {10., 20., 20., 20., 20., 20., 20., 20., 20.};
  // auto nx = {9, 17, 17, 17, 17, 17, 17, 17, 17};

  // auto dy = {20., 20., 20., 20., 20., 20., 20., 20., 10.};
  // auto ny = {17, 17, 17, 17, 17, 17, 17, 17, 9};

  // auto geom = DiffusionGeometry(core, dx, nx, dy, ny, 1., 0., 0., 1.);
  // auto solver = FDDiffusionDriver(geom);
  // auto solver.solve();
  // auto flux, x, y, _ = solver.flux();
  // auto power, x, y, _ = solver.power();
}
