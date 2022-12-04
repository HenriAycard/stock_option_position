#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/chrono.h>

#include "cpp_library/position.h"
#include "cpp_library/positions.h"
#include "cpp_library/portfolio.h"

namespace py = pybind11;


PYBIND11_MODULE(Portfolio, m) {
	py::class_<cpp_library::Position>(m, "Position")
	  .def(py::init<int, std::chrono::system_clock::time_point, std::chrono::system_clock::time_point, std::string, float, float, float, float>())
	  .def("__repr__", &cpp_library::Position::toString);
	py::class_<cpp_library::Positions>(m, "Positions")
	  .def(py::init<>())
	  .def("add_position", &cpp_library::Positions::add_position)
	  .def("__repr__", &cpp_library::Positions::toString);
	py::class_<cpp_library::Portfolio>(m, "Portfolio")
		.def(py::init<std::chrono::system_clock::time_point>())
		.def("set_position", &cpp_library::Portfolio::set_position)
		.def("setActivePortfolio", &cpp_library::Portfolio::setActivePortfolio)
		.def("mapTest", &cpp_library::Portfolio::map_to_string)
		.def("__repr__", &cpp_library::Portfolio::toString);
}