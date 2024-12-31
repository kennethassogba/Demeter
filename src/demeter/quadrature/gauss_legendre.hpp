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

  /**
  * @brief Getter func to return weights.
  */
  const Eigen::ArrayXd& getweights() const { return weights_; }

  /**
  * @brief Getter func to return cosines.
  */
  const Eigen::ArrayXd& getcosteta() const { return costeta_; }

  /**
  * @brief Getter func to return teta.
  *  
  * @note Teta is define starting from the (Oz)
  * axis as in [Applied Reactor Physics, Hebert]
  */
  const Eigen::ArrayXd& getteta() const { return teta_; }

 private:
  static Eigen::ArrayXd weights_;
  static Eigen::ArrayXd costeta_;
  static Eigen::ArrayXd teta_;
};


} // namespace Demeter
