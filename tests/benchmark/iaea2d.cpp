#include <iostream>
#include <valarray>
#include <vector>

class DiffusionCrossSection {  // TODO
  DiffusionCrossSection();
};

/**
 * param[in] note text to print before values
 * param[in] vala by-value, see Notes valarray/operator_arith
 * Example
 * std::valarray<int> x{1, 2, 3, 4};
 * print<int>("x: ", x);
 */
template <typename T>
void print(const std::string_view note, const std::valarray<T> vala) {
  std::cout << note << std::boolalpha << std::showpos;
  for (const T element : vala) std::cout << '\t' << element;
  std::cout << "\n";
}

int main() {
  using vec = std::valarray<double>;
  using mat = std::valarray<std::valarray<double>>;

  vec sigma_t = {0.222222, 0.833333};
  auto D = 1. / (3. * sigma_t);
  vec sigma_a = {0.010120, 0.080032};
  vec nusigma_f = {0., 0.135};
  vec sigma_f = {0., 0.135};
  vec chi = {1., 0.};
  mat sigma_s = {{0.00, 0.02}, {0.00, 0.00}};
  // auto a1 = DiffusionCrossSection(D, Ea, Es, Ef, vEf, chi, "A1");
  DiffusionCrossSection a1();

  sigma_t = {0.222222, 0.833333};
  auto D = 1. / (3. * sigma_t);
  sigma_a = {0.010120, 0.085032};
  nusigma_f = {0., 0.135};
  sigma_f = {0., 0.135};
  chi = {1., 0.};
  sigma_s = {{0.00, 0.02}, {0.00, 0.00}};
  // auto a2 = DiffusionCrossSection(D, Ea, Es, Ef, vEf, chi, "A2");
  DiffusionCrossSection a2();

  sigma_t = {0.222222, 0.833333};
  auto D = 1. / (3. * sigma_t);
  sigma_a = {0.010120, 0.130032};
  nusigma_f = {0., 0.135};
  sigma_f = {0., 0.135};
  chi = {1., 0.};
  sigma_s = {{0.00, 0.02}, {0.00, 0.00}};
  // auto a3 = DiffusionCrossSection(D, Ea, Es, Ef, vEf, chi, "A3");
  DiffusionCrossSection a3();
  // Faire une cellulle carre qui contient le materiaux et qui est maillable

  sigma_t = {0.166667, 1.111111};
  auto D = 1. / (3. * sigma_t);
  sigma_a = {0.000160, 0.010024};
  sigma_s = {{0.00, 0.04}, {0.00, 0.00}};
  // auto a4 = DiffusionCrossSection(D, Ea, Es, "Aauto 4");
  DiffusionCrossSection a4();

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

  auto dx = {10., 20., 20., 20., 20., 20., 20., 20., 20.};
  auto nx = {9, 17, 17, 17, 17, 17, 17, 17, 17};

  auto dy = {20., 20., 20., 20., 20., 20., 20., 20., 10.};
  auto ny = {17, 17, 17, 17, 17, 17, 17, 17, 9};

  // auto geom = DiffusionGeometry(core, dx, nx, dy, ny, 1., 0., 0., 1.);
  // auto solver = FDDiffusionDriver(geom);
  // auto solver.solve();
  // auto flux, x, y, _ = solver.flux();
  // auto power, x, y, _ = solver.power();
}
