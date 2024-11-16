#pragma once

#include <vector>
#include <string>
#include <string_view>
#include <Eigen/Core>

// TODO add optional xs and name
// TODO some material maybe not need all xs, make them optional
namespace Demeter {

/**
 * @brief Describes the material properties. The cross-sections (xs) are:
 * total, scatering, absorption and fission.
 */
class Material {
  using ArrayXd = Eigen::ArrayXd;  // TODO move to a global definition header
  using ArrayXXd = Eigen::ArrayXXd;

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
  Material(const Material& other);

  auto name() const { return name_; }
  auto NumEnergyGroups() const { return num_groups_; }
  const auto& SigmaT() const { return sigma_t_; }
  auto MaxSigmaT() const { return sigma_t_.maxCoeff(); };
  const auto& SigmaS() const { return sigma_s_; }
  const auto& SigmaA() const { return sigma_a_; }
  const auto& SigmaF() const { return sigma_f_; }
  const auto& NuSigmaF() const { return nu_sigma_f_; }
  const auto& Chi() const { return chi_; }
  auto SigmaT(size_t group) const { return sigma_t_(check(group)); }
  auto SigmaS(size_t from, size_t to) const {
    return sigma_s_(check(from), check(to));
  };
  auto SigmaA(size_t group) const { return sigma_a_(check(group)); }
  auto SigmaF(size_t group) const { return sigma_f_(check(group)); };
  auto NuSigmaF(size_t group) const { return nu_sigma_f_(check(group)); };
  auto Chi(size_t group) const { return chi_(check(group)); };
  bool fissile() const { return fissile_; }

 private:
  void check() const;
  size_t check(size_t group) const {
    assert((group >= 0) and (group < num_groups_));
    return group;
  }

 private:
  /* A name for the Material */
  std::string name_;

  /* The number of energy groups */
  size_t num_groups_;

  /* The total xs for each energy group */
  ArrayXd sigma_t_;

  /* A 2D array of the scattering cross-section matrix from/into each group */
  ArrayXXd sigma_s_;

  /* The absorption xs for each energy group */
  ArrayXd sigma_a_;

  /* The fission xs for each energy group */
  ArrayXd sigma_f_;

  /* The fission xs multiplied by nu for each energy group */
  ArrayXd nu_sigma_f_;

  /* The chi values for each energy group */
  ArrayXd chi_;

  /* The Material is fissile if it contains a non-zero fission xs */
  bool fissile_;
};
}  // namespace Demeter