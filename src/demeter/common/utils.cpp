#include "utils.hpp"

namespace Demeter {

void CheckOpenMP() {
#if defined(_OPENMP)
  unsigned num_threads = 0;
#pragma omp parallel reduction(+ : num_threads)
  num_threads += 1;
  std::cerr << "OpenMP version " << _OPENMP << " number of threads "
            << num_threads << '\n';
#endif
}

}  // namespace Demeter