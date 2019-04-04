#include <string>
#include <pybind11/pybind11.h>
#include <AHRS.h>

namespace py = pybind11;

PYBIND11_MODULE(py_navx, m) {

    m.doc() = "Python bindings for Kauai Labs navX";

    py::class_<AHRS>(m, "AHRS", R"pbdoc(
        The AHRS class provides an interface to AHRS capabilities of the
        KauaiLabs navX Robotics Navigation Sensor via Serial (TTL
        UART and USB) communications interfaces on Linux.
        )pbdoc")
        .def(py::init<std::string>(), R"pbdoc(
        Constructs the AHRS class using serial communication and the default
        update rate, and returning processed (rather than raw) data.

        Args:
            serial_port_id (str): serial port to use, for example: /dev/ACM0
        )pbdoc")
        .def("get_last_sensor_timestamp", &AHRS::GetLastSensorTimestamp, R"pbdoc(
        Returns the sensor timestamp corresponding to the last sample retrieved
        from the sensor.
        )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
