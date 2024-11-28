#pragma once

#include <vector>
#include <variant>
#include <iostream>
#include <string_view>

#include "demeter/model/cell.hpp"

namespace Demeter {

class Lattice {
  using FillType = std::variant<std::reference_wrapper<Cell>,
                                std::reference_wrapper<Lattice>>;

 public:
  Lattice(std::vector<FillType>&& components, std::string_view name = "")
      : components_(std::move(components)), name_(name) {
    check();
  }

  // void setBoundaryCondition(BoundaryCondition condition, BoundarySide side);

  const auto& components() const { return components_; }
  std::string_view name() const { return name_; }

  friend std::ostream& operator<<(std::ostream& os, const Lattice& l) {
    return os << l.print();
  }
  std::string print() const;

 private:
  void check() const;

 private:
  std::vector<FillType> components_;  // TODO use matrix

  // TODO use one vector
  // std::vector<BoundaryCondition> boundaryConditions;
  // std::vector<BoundarySide> boundarySides;

  std::string name_;
};

}  // namespace Demeter