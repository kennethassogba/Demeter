#pragma once

#include <vector>
#include <string>
#include <string_view>
#include <memory>
#include <functional>

#include <Eigen/Core>

#include "demeter/common.hpp"
#include "material.hpp"

namespace Demeter {

class Cell {
 public:
  Cell(double side, Material& material, std::string_view name = "")
      : side_(side), name_(name) {
    materials_.push_back(material);
    check();
  }

  Cell(double side, std::vector<double>&& radii,
       std::vector<std::reference_wrapper<Material>>&& materials,
       std::string_view name = "")
      : side_(side),
        radii_(std::move(radii)),
        materials_(std::move(materials)),
        name_(name) {
    check();
  }

  Cell(double side, std::vector<double>& radii,
       std::vector<std::reference_wrapper<Material>>&& materials,
       std::string_view name = "")
      : side_(side),
        radii_(radii),
        materials_(std::move(materials)),
        name_(name) {
    check();
  }

  double side() const { return side_; }

  const auto& radii() const { return radii_; }

  const auto& materials() const { return materials_; }

  std::string_view name() const { return name_; }

  std::string print(bool full = false) const;
  friend std::ostream& operator<<(std::ostream& os, const Cell& c) {
    return os << c.print(true);
  }

 private:
  void check() const;

 private:
  double side_;  // we assume that every cell is a square

  std::vector<double> radii_;  // in cm, in increasing order
  // size_t num_rings_;

  // size_t num_sectors_; //TODO

  std::vector<std::reference_wrapper<Material>> materials_;

  /* A name for the Cell */
  std::string name_;
};
}  // namespace Demeter