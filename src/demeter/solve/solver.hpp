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
  const auto& getFiss() const { return fiss_; }
  const auto& getPower() const { return power_; }

  auto& updateFissSrc();
  auto& updateScatSrc();

 private:
  const Lattice& geo__;
  AngularMethod& am_;
  SpatialMethod& sm_;

  double keff_ = 1.0;
  ArrayXd flux_;
  ArrayXd fiss_;
  ArrayXd power_;

  double tolerence_keff_ = 1e-5;
  double tolerence_flux_ = 1e-5;
  double tolerence_fiss_ = 1e-4;
};

/**
 * @brief Class that solve a problem of the
 * type Ax=lb, with l a scalar.
 */
class PowerIteration {
 public:
 
  /**
  * @brief Standard eigenvalue problem constructor.
  */
  PowerIteration(const Eigen::MatrixXd& A) 
      : A_(A) {
      std::cout << "Initialisation" << std::endl;
  }

  /**
  * @brief Generalized eigenvalue problem constructor. 
  */
  PowerIteration(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B) 
      : A_(A), B_(B) {
      std::cout << "Initialisation" << std::endl;
  }

  /**
  * @brief Solve the eigenvalue problem. 
  */
  void solve();

 private:

  double lambda_;
  double tol_eigvector_ = 1e-10;
  double tol_eigvalue_  = 1e-5;

  Eigen::MatrixXd A_; 
  Eigen::MatrixXd B_;
  Eigen::ArrayXd  x_;
};



}  // namespace Demeter
