#pragma once

#include <Eigen/Core>

#include "demeter/common.hpp"
#include "demeter/methods.hpp"
#include "demeter/model/lattice.hpp"

namespace Demeter {

class Solver {
 public:
  Solver(const Lattice& core, AngularMethod& am, SpatialMethod& sm)
      : core_(core), am_(am), sm_(sm) {};
  void solve();

  auto getFlux() const { return flux_; }
  auto getPower() const { return power_; }

 private:
  const Lattice& core_;
  AngularMethod& am_;
  SpatialMethod& sm_;

  double keff_;
  ArrayXd flux_;
  ArrayXd power_;

  double tolerence_keff_ = 1e-5;
  double tolerence_flux_ = 1e-5;
};
}  // namespace Demeter