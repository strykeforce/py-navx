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
        .def("get_compass_heading", &AHRS::GetCompassHeading, R"pbdoc(
        Returns the current tilt-compensated compass heading value (in degrees,
        from 0 to 360) reported by the sensor.

        Note that this value is sensed by a magnetometer, which can be affected
        by nearby magnetic fields (e.g., the magnetic fields generated by
        nearby motors).

        Before using this value, ensure that (a) the magnetometer has been
        calibrated and (b) that a magnetic disturbance is not taking place at
        the instant when the compass heading was generated.
        )pbdoc")
        .def("zero_yaw", &AHRS::ZeroYaw, R"pbdoc(
        Sets the user-specified yaw offset to the current yaw value reported by
        the sensor.

        This user-specified yaw offset is automatically subtracted from
        subsequent yaw values reported by the getYaw() method.
        )pbdoc")
        .def("is_calibrating", &AHRS::IsCalibrating, R"pbdoc(
        Returns true if the sensor is currently performing automatic
        gyro/accelerometer calibration.

        Automatic calibration occurs when the sensor is initially powered on,
        during which time the sensor should be held still, with the Z-axis
        pointing up (perpendicular to the earth).

        Note that during this automatic calibration, the yaw, pitch and roll
        values returned may not be accurate.

        Once calibration is complete, the sensor will automatically remove an
        internal yaw offset value from all reported values.
        )pbdoc")
        .def("is_connected", &AHRS::IsConnected, R"pbdoc(
        Indicates whether the sensor is currently connected to the host
        computer.

        A connection is considered established whenever communication with the
        sensor has occurred recently.
        )pbdoc")
        .def("get_byte_count", &AHRS::GetByteCount, R"pbdoc(
        Returns the count in bytes of data received from the sensor.

        This could can be useful for diagnosing connectivity issues.  If the
        byte count is increasing, but the update count (see getUpdateCount())
        is not, this indicates a software misconfiguration.
        )pbdoc")
        .def("get_update_count", &AHRS::GetUpdateCount, R"pbdoc(
        Returns the count of valid updates which have been received from the
        sensor.

        This count should increase at the same rate indicated by the configured
        update rate.
        )pbdoc")
        .def("get_last_sensor_timestamp", &AHRS::GetLastSensorTimestamp, R"pbdoc(
        Returns the sensor timestamp corresponding to the last sample retrieved
        from the sensor.
        )pbdoc")
        .def("get_world_linear_accel_x", &AHRS::GetWorldLinearAccelX, R"pbdoc(
        Returns the current linear acceleration in the X-axis (in G).

        World linear acceleration refers to raw acceleration data, which has
        had the gravity component removed, and which has been rotated to the
        same reference frame as the current yaw value.  The resulting value
        represents the current acceleration in the x-axis of the body (e.g.,
        the robot) on which the sensor is mounted.
        )pbdoc")
        .def("get_world_linear_accel_y", &AHRS::GetWorldLinearAccelY, R"pbdoc(
        Returns the current linear acceleration in the y-axis (in G).

        World linear acceleration refers to raw acceleration data, which has
        had the gravity component removed, and which has been rotated to the
        same reference frame as the current yaw value.  The resulting value
        represents the current acceleration in the y-axis of the body (e.g.,
        the robot) on which the sensor is mounted.
        )pbdoc")
        .def("get_world_linear_accel_z", &AHRS::GetWorldLinearAccelZ, R"pbdoc(
        Returns the current linear acceleration in the z-axis (in G).

        World linear acceleration refers to raw acceleration data, which has
        had the gravity component removed, and which has been rotated to the
        same reference frame as the current yaw value.  The resulting value
        represents the current acceleration in the z-axis of the body (e.g.,
        the robot) on which the sensor is mounted.
        )pbdoc")
        .def("is_moving", &AHRS::IsMoving, R"pbdoc(
        Indicates if the sensor is currently detecting motion, based upon the X
        and Y-axis world linear acceleration values.

        If the sum of the absolute values of the X and Y axis exceed a "motion
        threshold", the motion state is indicated.
        )pbdoc")
        .def("is_rotating", &AHRS::IsRotating, R"pbdoc(
        Indicates if the sensor is currently detecting yaw rotation, based upon
        whether the change in yaw over the last second exceeds the "Rotation
        Threshold."

        Yaw Rotation can occur either when the sensor is rotating, or when the
        sensor is not rotating AND the current gyro calibration is
        insufficiently calibrated to yield the standard yaw drift rate.
        )pbdoc")
        .def("get_angle", &AHRS::GetAngle, R"pbdoc(
        Returns the total accumulated yaw angle (Z Axis, in degrees) reported
        by the sensor.

        Note that the angle is continuous, meaning it's range is beyond 360
        degrees.  This ensures that algorithms that wouldn't want to see a
        discontinuity in the gyro output as it sweeps past 0 on the second time
        around.

        Note that the returned yaw value will be offset by a user-specified
        offset value; this user-specified offset value is set by invoking the
        zeroYaw() method.
        )pbdoc")
        .def("get_rate", &AHRS::GetRate, R"pbdoc(
        Return the rate of rotation of the yaw (Z-axis) gyro, in degrees per
        second.

        The rate is based on the most recent reading of the yaw gyro angle.
        )pbdoc")
        .def("get_actual_update_rate", &AHRS::GetActualUpdateRate, R"pbdoc(
        Returns the navX-Model device's currently configured update rate.

        Note that the update rate that can actually be realized is a value
        evenly divisible by the navX-Model device's internal motion processor
        sample clock (200Hz).  Therefore, the rate that is returned may be
        lower than the requested sample rate.

        The actual sample rate is rounded down to the nearest integer that is
        divisible by the number of Digital Motion Processor clock ticks.  For
        instance, a request for 58 Hertz will result in an actual rate of 66Hz
        (200 / (200 / 58), using integer math.
        )pbdoc")
        .def("get_requested_update_rate", &AHRS::GetRequestedUpdateRate, R"pbdoc(
        Returns the currently requested update rate.

        Note that not every update rate can actually be realized, since the
        actual update rate must be a value evenly divisible by the navX-Model
        device's internal motion processor sample clock (200Hz).

        To determine the actual update rate, use the get_actual_update_rate()
        method.
        )pbdoc");


#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
