#include "utils.hpp"
// #include <filesystem>
// #include <nanobind/nanobind.h>
//namespace nb = nanobind;
//namespace fs = std::filesystem;
//
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

void PrintBanner() {
    std::cout << R"(
 _____  ______ ______ _____ _____ ______ _____   
|  __ \|  ____|  \/  |  ___|_   _|  ____|  __ \ 
| |  | | |__  | \  / | |__   | | | |__  | |__) |
| |  | |  __| | |\/| |  __|  | | |  __| |  _  / 
| |__| | |____| |  | | |___  | | | |____| | \ \ 
|_____/|______|_|  |_|_____|_|_|_|_|______|_\__\

          P R O J E T   D E M E T E R

)" << std::endl;
}

//NB_MODULE(demeter, m) {
//    m.def("PrintBanner",
//          static_cast<void(*)(const std::string&)>(&PrintBanner),
//          "Affiche une bannière de projet à partir du nom de fichier");
//}

}  // namespace Demeter
