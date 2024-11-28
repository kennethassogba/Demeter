#pragma once

namespace Demeter {

/**
 * @brief Base class for spatial methods
 */
class SpatialMethod {
 public:
  enum class Type { DG, FEM, VEM, HHO };

  SpatialMethod(Type type = Type::DG, unsigned order = 1)
      : type_(type), order_(order) {}

 private:
  Type type_;
  unsigned order_;
};

}  // namespace Demeter