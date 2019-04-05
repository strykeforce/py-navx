#!/usr/bin/env python3

import time
from py_navx import AHRS

print("\npy_navx demo...\nType CTRL-C to stop demo\n")

ahrs = AHRS("/dev/ttyACM0")

print("  Pitch |  Roll   |   Yaw   | TimeStamp")
while True:
    print(
        "{:7.2f} | {:7.2f} | {:7.2f} | {:10}".format(
            ahrs.get_pitch(),
            ahrs.get_roll(),
            ahrs.get_yaw(),
            ahrs.get_last_sensor_timestamp(),
        ),
        end="\r",
        flush=True,
    )
    time.sleep(0.1)
