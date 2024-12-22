#pragma once


#include <Eigen/Core>
#include <Eigen/Dense>

namespace Demeter {

class GaussLegendre {
 public:

  GaussLegendre(const int& nphi, const int& nteta) 
     : nphi_(nphi), nteta_(nteta) {
  }

  void compute_angles();
  void compute_weights();
 
 private:
  size_t nphi_;  // nber of azimutal angles
  size_t nteta_; // nber of polar    angles

};
} // namespace Demeter
