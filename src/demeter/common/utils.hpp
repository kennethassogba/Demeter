/**
 * @brief Contains some useful macros and typedefs
 */

#pragma once

#include <iostream>

/// @brief Print the name and value of a variable
#define PRINTER(x) #x << " = " << x

namespace Demeter {

void CheckOpenMP();

}  // namespace Demeter
