#pragma once

namespace Demeter {

/**
 * @brief Base class for angular methods
 */
class AngularMethod {
 public:
  enum class Type { SN, PN, FEM, DG };

  AngularMethod(Type type = Type::SN, unsigned order = 1)
      : type_(type), order_(order) {}

 private:
  Type type_;
  unsigned order_;
};
}  // namespace Demeter