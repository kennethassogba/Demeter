/**
 * @brief Contains some useful macros and typedefs
 */

#pragma once

#include <iostream>

/// @brief Print the name and value of a variable
#define PRINTER(x) #x << " = " << x

namespace Demeter {

void CheckOpenMP();

// auto watch =
//     [&](std::vector<std::variant<std::reference_wrapper<Material>,
//                                  std::reference_wrapper<Cell>,
//                                  std::reference_wrapper<Lattice>>>&& vec) {
//       for (const auto& v : vec) {
//         std::visit([](auto&& v) { std::cout << v.get() << std::endl; }, v);
//       }
//     };

}  // namespace Demeter
