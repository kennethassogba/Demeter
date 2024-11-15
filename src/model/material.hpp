#pragma once

#include <vector>
#include <string>
#include <string_view>
#include <Eigen/Core>

// TODO switch to Eigen
// TODO add optional xs and name
namespace Demeter {

/**
 * @brief Describes the material properties. The cross-sections (xs) are:
 * total, scatering, absorption and fission.
 */
class Material {
 public:
  Material(std::vector<double>& sigma_t, std::vector<double>& sigma_s,
           std::vector<double>& sigma_a, std::vector<double>& sigma_f,
           std::vector<double>& nu_sigma_f, std::vector<double>& chi,
           std::string_view name = "");
  // rvalue reference constructor
  Material(std::vector<double>&& sigma_t, std::vector<double>&& sigma_s,
           std::vector<double>&& sigma_a, std::vector<double>&& sigma_f,
           std::vector<double>&& nu_sigma_f, std::vector<double>&& chi,
           std::string_view name = "");
  // move constructor
  Material(Material&& other);
  // copy constructor
  Material(const Material& other);

 private:
  /* A name for the Material */
  std::string name_;

  /* The number of energy groups */
  int num_groups_;

  /* The total xs for each energy group */
  std::vector<double> sigma_t_;

  /* A 2D (TODO) array of the scattering cross-section matrix from/into each
   * group */
  std::vector<double> sigma_s_;

  /* The absorption xs for each energy group */
  std::vector<double> sigma_a_;

  /* The fission xs for each energy group */
  std::vector<double> sigma_f_;

  /* The fission xs multiplied by nu for each energy group */
  std::vector<double> nu_sigma_f_;

  /* The chi values for each energy group */
  std::vector<double> chi_;

  /* The Material is fissile if it contains a non-zero fission xs */
  bool fissile_;
};
}  // namespace Demeter