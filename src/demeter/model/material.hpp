#pragma once

#include <vector>
#include <string>
#include <string_view>
#include <Eigen/Core>

#include "demeter/common.hpp"

// TODO add optional xs and name
// TODO some material maybe not need all xs, make them optional
namespace Demeter {

/**
 * @brief Describes the material properties. The cross-sections (xs) are:
 * total, scatering, absorption and fission.
 */
class Material {
 public:
  Material(ArrayXd& sigma_t, ArrayXXd& sigma_s, ArrayXd& sigma_a,
           ArrayXd& sigma_f, ArrayXd& nu_sigma_f, ArrayXd& chi,
           std::string_view name = "");

  // rvalue reference constructor
  Material(ArrayXd&& sigma_t, ArrayXXd&& sigma_s, ArrayXd&& sigma_a,
           ArrayXd&& sigma_f, ArrayXd&& nu_sigma_f, ArrayXd&& chi,
           std::string_view name = "");

  // move constructor
  Material(Material&& other);

  // copy constructor
  Material(const Material& other) { *this = other; }

  // copy assignment operator
  Material& operator=(Material other) {
    swap(*this, other);
    return *this;
  }

  std::string print() const;

  friend std::ostream& operator<<(std::ostream& os, const Material& m) {
    return os << m.print();
  }

  auto name() const { return name_; }
  auto NumEnergyGroups() const { return num_groups_; }
  bool fissile() const { return fissile_; }

  const auto& SigmaT() const { return sigma_t_; }
  auto MaxSigmaT() const { return sigma_t_.maxCoeff(); };
  const auto& SigmaS() const { return sigma_s_; }
  const auto& SigmaA() const { return sigma_a_; }
  const auto& SigmaF() const { return sigma_f_; }
  const auto& NuSigmaF() const { return nu_sigma_f_; }
  const auto& Chi() const { return chi_; }

  auto SigmaT(Index group) const { return sigma_t_(check(group)); }
  auto SigmaA(Index group) const { return sigma_a_(check(group)); }
  auto SigmaF(Index group) const { return sigma_f_(check(group)); };
  auto NuSigmaF(Index group) const { return nu_sigma_f_(check(group)); };
  auto Chi(Index group) const { return chi_(check(group)); };
  auto SigmaS(Index from, Index to) const {
    return sigma_s_(check(from), check(to));
  };

  friend void swap(Material& a, Material& b) {
    using std::swap;
    swap(a.sigma_t_, b.sigma_t_);
    swap(a.sigma_s_, b.sigma_s_);
    swap(a.sigma_a_, b.sigma_a_);
    swap(a.sigma_f_, b.sigma_f_);
    swap(a.nu_sigma_f_, b.nu_sigma_f_);
    swap(a.chi_, b.chi_);
    swap(a.num_groups_, b.num_groups_);
    swap(a.fissile_, b.fissile_);
    swap(a.name_, b.name_);
  }

 private:
  void check() const;
  Index check(Index group) const {
    assert((group > 0) and (group < num_groups_));
    return group;
  }

 private:
  /* Total xs for each energy group */
  ArrayXd sigma_t_;

  /* A 2D array of the scattering cross-section matrix from/into each group */
  ArrayXXd sigma_s_;

  /* Absorption xs for each energy group */
  ArrayXd sigma_a_;

  /* Fission xs for each energy group */
  ArrayXd sigma_f_;

  /* Fission xs multiplied by nu for each energy group */
  ArrayXd nu_sigma_f_;

  /* Fission spectrum for each energy group */
  ArrayXd chi_;

  /* The number of energy groups */
  Index num_groups_;

  /* The Material is fissile if it contains a non-zero fission xs */
  bool fissile_;

  /* A name for the Material */
  std::string name_;
};
}  // namespace Demeter