#include "material.hpp"

#include <iostream>

namespace Demeter {

/**
 * @brief Construct a Material from a set of cross-sections.
 *
 * @param[in] sigma_t total cross-section
 * @param[in] sigma_s scattering cross-section matrix
 * @param[in] sigma_a absorption cross-section
 * @param[in] sigma_f fission cross-section
 * @param[in] nu_sigma_f nu*fission
 * @param[in] chi fission spectrum
 * @param[in] name material name (optional)
 *
 *
 * @note
 * To use it from Python, you can do something like
 *
 * >>> sigma_t = np.array([0.1, 0.2, 0.3])
 * >>> sigma_s = np.array([[0.1, 0.2, 0.3], [0.3, 0.2, 0.1], [0.1, 0.3, 0.2]])
 * >>> sigma_a = np.array([0.01, 0.02, 0.03])
 * >>> sigma_f = np.array([0.01, 0.02, 0.03])
 * >>> nu_sigma_f = np.array([0.01, 0.02, 0.03])
 * >>> chi = np.array([0.1, 0.2, 0.3])
 * >>> uo2 = Material(sigma_t, sigma_s, sigma_a, sigma_f, nu_sigma_f, chi,
 * 'UO2')
 */
Material::Material(ArrayXd& sigma_t, ArrayXXd& sigma_s, ArrayXd& sigma_a,
                   ArrayXd& sigma_f, ArrayXd& nu_sigma_f, ArrayXd& chi,
                   std::string_view name)
    : sigma_t_(sigma_t),
      sigma_s_(sigma_s),
      sigma_a_(sigma_a),
      sigma_f_(sigma_f),
      nu_sigma_f_(nu_sigma_f),
      chi_(chi),
      num_groups_(sigma_t_.size()),
      name_(name) {
  check();
  fissile_ = sigma_f.maxCoeff() > 0.0;
}

/**
 * @brief Construct a Material from a set of cross-sections.
 * Constructor from rvalue references, it takes ownership of the input arrays.
 *
 * @param[in] sigma_t total cross-section
 * @param[in] sigma_s scattering cross-section matrix
 * @param[in] sigma_a absorption cross-section
 * @param[in] sigma_f fission cross-section
 * @param[in] nu_sigma_f nu*fission
 * @param[in] chi fission spectrum
 * @param[in] name material name (optional)
 *
 *
 * @note
 * To use it from Python, you can do something like
 *
 * >>> sigma_t = np.array([0.1, 0.2, 0.3])
 * >>> sigma_s = np.array([[0.1, 0.2, 0.3], [0.3, 0.2, 0.1], [0.1, 0.3, 0.2]])
 * >>> sigma_a = np.array([0.01, 0.02, 0.03])
 * >>> sigma_f = np.array([0.01, 0.02, 0.03])
 * >>> nu_sigma_f = np.array([0.01, 0.02, 0.03])
 * >>> chi = np.array([0.1, 0.2, 0.3])
 * >>> uo2 = Material(sigma_t, sigma_s, sigma_a, sigma_f, nu_sigma_f, chi,
 * 'UO2')
 */
Material::Material(ArrayXd&& sigma_t, ArrayXXd&& sigma_s, ArrayXd&& sigma_a,
                   ArrayXd&& sigma_f, ArrayXd&& nu_sigma_f, ArrayXd&& chi,
                   std::string_view name)
    : sigma_t_(std::move(sigma_t)),
      sigma_s_(std::move(sigma_s)),
      sigma_a_(std::move(sigma_a)),
      sigma_f_(std::move(sigma_f)),
      nu_sigma_f_(std::move(nu_sigma_f)),
      chi_(std::move(chi)),
      num_groups_(sigma_t_.size()),
      name_(name) {
  check();
  fissile_ = sigma_f_.maxCoeff() > 0.0;
}

/**
 * @brief Move constructor
 *
 * @param[in] other other Material object
 */
Material::Material(Material&& other)
    : sigma_t_(std::move(other.sigma_t_)),
      sigma_s_(std::move(other.sigma_s_)),
      sigma_a_(std::move(other.sigma_a_)),
      sigma_f_(std::move(other.sigma_f_)),
      nu_sigma_f_(std::move(other.nu_sigma_f_)),
      chi_(std::move(other.chi_)),
      num_groups_(other.num_groups_),
      fissile_(other.fissile_),
      name_(other.name_) {}

// TODO change assert since we also want to check in release
void Material::check() const {  // TODO use fmt and a logger
  if (not(num_groups_ > 0)) {
    std::string msg = "Material " + name_ + " has " +
                      std::to_string(num_groups_) + " energy groups";
    throw std::runtime_error(msg);
  }

  auto cast = [&](long int x) { return static_cast<decltype(num_groups_)>(x); };
  for (auto size :
       {sigma_t_.size(), sigma_s_.rows(), sigma_s_.cols(), sigma_a_.size(),
        sigma_f_.size(), nu_sigma_f_.size(), chi_.size()}) {
    if (cast(size) != num_groups_) {
      std::string msg =
          "Material " + name_ + " has " + std::to_string(num_groups_) +
          " energy groups but " +
          "sigma_t.size()=" + std::to_string(sigma_t_.size()) +
          ", sigma_s.rows()=" + std::to_string(sigma_s_.rows()) +
          ", sigma_s.cols()=" + std::to_string(sigma_s_.cols()) +
          ", sigma_a.size()=" + std::to_string(sigma_a_.size()) +
          ", sigma_f.size()=" + std::to_string(sigma_f_.size()) +
          ", nu_sigma_f.size()=" + std::to_string(nu_sigma_f_.size()) +
          ", chi.size()=" + std::to_string(chi_.size());
      throw std::runtime_error(msg);
    }
  }
}

}  // namespace Demeter