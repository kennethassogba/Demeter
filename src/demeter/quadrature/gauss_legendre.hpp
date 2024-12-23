#pragma once

#include <Eigen/Dense>

namespace Demeter {

template <std::size_t nteta>
class GaussLegendre {
 public:
  // Define array initializer
  static void initialization();

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
