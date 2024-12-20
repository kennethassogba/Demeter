#pragma once

#include <Eigen/Core>

#include "methods.hpp"
#include "demeter/common.hpp"
#include "demeter/model/lattice.hpp"

namespace Demeter {

class Solver {
 public:
  Solver(const Lattice& geo_, AngularMethod& am, SpatialMethod& sm)
      : geo__(geo_), am_(am), sm_(sm) {};
  void solve();

  const auto& getFlux() const { return flux_; }
  const auto& getPower() const { return power_; }

 private:
  const Lattice& geo__;
  AngularMethod& am_;
  SpatialMethod& sm_;

  double keff_ = 1.0;
  ArrayXd flux_;
  ArrayXd power_;

  double tolerence_keff_ = 1e-5;
  double tolerence_flux_ = 1e-5;
};
}  // namespace Demeter