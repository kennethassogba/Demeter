#include "demeter/model/material.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include <nanobind/nanobind.h>
#include <nanobind/eigen/dense.h>
#include <nanobind/stl/string_view.h>
#pragma GCC diagnostic pop

namespace nb = nanobind;
using namespace nb::literals;

using Eigen::ArrayXd;
using Eigen::ArrayXXd;

NB_MODULE(_demeter, m) {
  m.doc() = "A deterministic neutron transport solver for reactor simulations";

  // clang-format off
  // Material class bindings
  nb::class_<Demeter::Material>(m, "Material")
      .def(nb::init<ArrayXd&,  /* sigma_t */
                    ArrayXXd&, /* sigma_s */
                    ArrayXd&,  /* sigma_a */
                    ArrayXd&,  /* sigma_f */
                    ArrayXd&,  /* nu_sigma_f */
                    ArrayXd&,  /* chi */
                    std::string_view>(),
           "sigma_t"_a, "sigma_s"_a, "sigma_a"_a,
           "sigma_f"_a, "nu_sigma_f"_a, "chi"_a,
           "name"_a = "",
           "Create a Material object with the given cross-sections.");
  // .def_ro("name", &Demeter::Material::name, "The name of the material.")
  // .def_ro("num_energy_groups", &Demeter::Material::NumEnergyGroups);
  // .def_prop_ro("sigma_t", &Demeter::Material::SigmaT)
  // .def_prop_ro("sigma_s", &Demeter::Material::SigmaS)
  // .def_prop_ro("sigma_a", &Demeter::Material::SigmaA)
  // .def_prop_ro("sigma_f", &Demeter::Material::SigmaF)
  // .def_prop_ro("nu_sigma_f", &Demeter::Material::NuSigmaF)
  // .def_prop_ro("chi", &Demeter::Material::Chi)
  // .def("sigma_t", &Demeter::Material::SigmaT, "group"_a)
  // .def("sigma_s", &Demeter::Material::SigmaS, "from"_a, "to"_a)
  // .def("sigma_a", &Demeter::Material::SigmaA, "group"_a)
  // .def("sigma_f", &Demeter::Material::SigmaF, "group"_a)
  // .def("nu_sigma_f", &Demeter::Material::NuSigmaF, "group"_a)
  // .def("chi", &Demeter::Material::Chi, "group"_a)
  // .def("fissile", &Demeter::Material::fissile);

  // clang-format on
}