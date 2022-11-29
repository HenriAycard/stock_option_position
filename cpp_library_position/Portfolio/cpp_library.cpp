#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/chrono.h>
#include "cpp_library/position.h"

namespace py = pybind11;


PYBIND11_MODULE(Portfolio, m) {
	py::class_<Position>(m, "Position")
	  .def(py::init<int, int, int, int, int, float, int, int, float, float, float>())
	  .def("__repr__", &Position::toString);
	py::class_<Positions>(m, "Positions")
	  .def(py::init<>())
	  .def("add_position", &Positions::add_position)
	  .def("__repr__", &Positions::toString);
	py::class_<Portfolio>(m, "Portfolio")
		.def(py::init<std::chrono::system_clock::time_point>())
		.def("set_position", &Portfolio::set_position)
		.def("__repr__", &Portfolio::toString);
}