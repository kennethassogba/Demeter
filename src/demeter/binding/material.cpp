#include <nanobind/nanobind.h>

namespace nb = nanobind;
using namespace nb::literals;

int add(int a, int b = 1) { return a + b; }

NB_MODULE(demeter_ext, m) {
  m.doc() = "A simple example python extension";
  m.def(
      "add", &add, "a"_a, "b"_a = 1,
      "This function adds two numbers and increments if only one is provided.");
  m.attr("the_answer") = 42;
}