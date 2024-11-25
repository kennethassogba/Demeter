#pragma once

#include <vector>
#include <string>
#include <string_view>
#include <memory>
#include <Eigen/Core>

#include "demeter/common.hpp"
#include "material.hpp"

namespace Demeter {

class Cell {
 public:
  Cell(double side, std::vector<std::shared_ptr<Material>>& materials,
       std::string_view name = "")
      : side(side), materials_(materials), name_(name) {}

  Cell(double side, std::vector<double>& radii,
       std::vector<std::shared_ptr<Material>>& materials,
       std::string_view name = "")
      : side(side), radii_(radii), materials_(materials), name_(name) {
    check();
  }

 private:
  void check() const;

 private:
  double side;  // we assume that every cell is a square

  std::vector<double> radii_;
  // size_t num_rings_;

  // size_t num_sectors_; //TODO

  std::vector<std::shared_ptr<Material>> materials_;

  /* A name for the Cell */
  std::string name_;
};
}  // namespace Demeter