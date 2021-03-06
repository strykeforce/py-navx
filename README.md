# py-navx

Adaptation of [kauailabs/navxmxp](https://github.com/kauailabs/navxmxp) by way of [FRC900/navXTimeSync](https://github.com/FRC900/navXTimeSync) for
use with Python 3 on Raspberry Pi vision co-processor.

## Preparing the FRCVision Raspberry Pi

Install prerequisite software:

```
sudo apt install git cmake python3-dev
```

Give user `pi` access to the serial port:

```
sudo usermod -a -G dialout pi
```

## Installation

Download and install the latest version of `py-navx`:

```
git clone --recursive https://github.com/strykeforce/py-navx.git
sudo pip3 install ./py-navx
```

## Example

On Linux, the serial port to the navX should be `/dev/ttyACM0`.

```python
from py_navx import AHRS

ahrs = AHRS("/dev/ttyACM0")
timestamp = ahrs.get_last_sensor_timestamp()

print("timestamp = {}".format(timestamp))
```

## License

The MIT license.

Original navX source code is Copyright (c) 2015 Kauai Labs, Inc. and is under the MIT license.
