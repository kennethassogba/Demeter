/**
 * @brief Contains some useful macros and typedefs
 */

#pragma once

#include <iostream>
#include <cassert>

// @brief Print the name and value of a variable
#define PRINTER(x) #x << " = " << x
// usage: PRINTER(x);

// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))
// usage: assertm(exp, "message");

namespace Demeter {

void CheckOpenMP();

/*auto watch =
    [&](std::vector<std::variant<std::reference_wrapper<Material>,
                                 std::reference_wrapper<Cell>,
                                 std::reference_wrapper<Lattice>>>&& vec) {
      for (const auto& v : vec) {
        std::visit([](auto&& v) { std::cout << v.get() << std::endl; }, v);
      }
    };
*/

}  // namespace Demeter
