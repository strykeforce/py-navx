#include <string>
#include <pybind11/pybind11.h>
#include <AHRS.h>

namespace py = pybind11;

PYBIND11_MODULE(py_navx, m) {
    py::class_<AHRS>(m, "AHRS")
        .def(py::init<std::string>())
        .def("get_last_sensor_timestamp", &AHRS::GetLastSensorTimestamp);

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
