/**
 * @file lattice.hpp
 * @author Kenneth Assogba
 * @brief Lattice class
 */

#pragma once

#include <vector>
#include <initializer_list>
#include <iostream>

#include "demeter/model/cell.hpp"

namespace Demeter {

class Lattice {
 public:
  Lattice(std::vector<std::reference_wrapper<Cell>>& cells,
          std::string name = "")
      : cells_(cells), name_(name) {}
  Lattice(std::initializer_list<std::reference_wrapper<Cell>>& cells,
          std::string name = "")
      : cells_(cells), name_(name) {}

  std::vector<std::reference_wrapper<Cell>>& cells() { return cells_; }
  const std::vector<std::reference_wrapper<Cell>>& cells() const {
    return cells_;
  }

  friend std::ostream& operator<<(std::ostream& os, const Lattice& l) {
    return os << l.print();
  }
  std::string print() const;

 private:
  std::vector<std::reference_wrapper<Cell>> cells_;

  std::string name_;
};

}  // namespace Demeter