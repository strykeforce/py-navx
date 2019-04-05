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
        )pbdoc")
        .def("get_pitch", &AHRS::GetPitch, R"pbdoc(
        Returns the current pitch value (in degrees, from -180 to 180) reported
        by the sensor.

        Pitch is a measure of rotation around the X Axis.
        )pbdoc")
        .def("get_roll", &AHRS::GetRoll, R"pbdoc(
        Returns the current roll value (in degrees, from -180 to 180) reported
        by the sensor.

        Roll is a measure of rotation around the X Axis.
        )pbdoc")
        .def("get_yaw", &AHRS::GetYaw, R"pbdoc(
        Returns the current yaw value (in degrees, from -180 to 180) reported
        by the sensor.

        Yaw is a measure of rotation around the Z Axis (which is perpendicular
        to the earth).  Note that the returned yaw value will be offset by a
        user-specified offset value; this user-specified offset value is set by
        invoking the zeroYaw() method.
        )pbdoc")
        .def("zero_yaw", &AHRS::ZeroYaw, R"pbdoc(
        Sets the user-specified yaw offset to the current yaw value reported by
        the sensor.

        This user-specified yaw offset is automatically subtracted from
        subsequent yaw values reported by the getYaw() method.
        )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
