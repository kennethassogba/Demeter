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
  }

  Cell(double side, std::vector<double>& radii,
       std::vector<std::reference_wrapper<Material>>& materials,
       std::string_view name = "")
      : side_(side), radii_(radii), materials_(materials), name_(name) {
    check();
  }

  std::string print() const;
  friend std::ostream& operator<<(std::ostream& os, const Cell& c) {
    return os << c.print();
  }

 private:
  void check() const;

 private:
  double side_;  // we assume that every cell is a square

  std::vector<double> radii_;
  // size_t num_rings_;

  // size_t num_sectors_; //TODO

  std::vector<std::reference_wrapper<Material>> materials_;

  /* A name for the Cell */
  std::string name_;
};
}  // namespace Demeter