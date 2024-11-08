#include <iostream>
#include <vector>
#include <omp.h>

int main()
{
#if defined(_OPENMP)
  std::cout << "OpenMP version " << _OPENMP << '\n';
#endif

#pragma omp parallel for
  for (int i = 0; i < 9; ++i)
  {
    std::cerr << "rank = " << omp_get_thread_num() 
      << " size = " << omp_get_num_threads()
      << '\n';
  }
  return 0;
}