#pragma once

#include <Eigen/Dense>

// to do

// fonction qui permet assurer 
// somme des poids vaut 1
// permet assurer angles dans 0 pi


namespace Demeter {

 /**
 * @brief Template to store roots and weights
 *        for diffents number of polar angles.
 *
 * @tparam nteta Number of polar angles in [0,pi].
 *
 * @note If cos(teta) is in the quadrature set, 
 * then -cos(teta) is also in the quadrature set
 * with the same weight. This data are stored from 
 * nteta/2 to neta to reduce the footprint memory.
 */
template <std::size_t nteta>
class GaussLegendre {
 public:
  
  GaussLegendre() {
      initialization();
  }
  
  /**
  * @brief Allocate the arrays to store the data.
  */
  void initialization();

  // Define getter methods
  const Eigen::ArrayXd& getweights() const { return weights_; }
  const Eigen::ArrayXd& getcosteta() const { return costeta_; }
  const Eigen::ArrayXd& getteta() const { return teta_; }

 
 private:
  static Eigen::ArrayXd weights_;
  static Eigen::ArrayXd costeta_;
  static Eigen::ArrayXd teta_;
};


} // namespace Demeter
