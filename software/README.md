# Getting Started

The software in this directory is experimental and has not yet completed
module-level validation.

## Prerequisites

- A host controller with an Arduino-compatible `Wire` implementation
- The `DevLab_MPU6050` library that provides `DevLab_MPU6050.h`
- A validated power connection and common ground between host and module

The library source and installation package are not included in this
repository. Install the approved library release before compiling the example.

## Connections

Connect the host I2C bus to the module signals labeled `SDA` and `SCL`, and
connect a common `GND`. The allowed module `VCC` range remains pending
validation; confirm it before applying power.

GPIO 12 and GPIO 22 in the example are host-controller assignments. They are
not pin numbers for the DevLab module and may need to be changed for the chosen
controller.

## Experimental Arduino Example

The [basic DevLab_MPU6050 example](https://github.com/UNIT-Electronics-MX/unit_devlab_i2c_mpu6050_6_axis_imu/blob/main/software/examples/arduino/devlab_mpu6050_basic/devlab_mpu6050_basic.ino)
uses sensor address `0x68` and requests a 400 kHz I2C clock. The MPU-6050
datasheet supports 400 kHz Fast-mode operation, but the complete module and
example still require validation together.

## Support

Report issues through the [project repository](https://github.com/UNIT-Electronics-MX/unit_devlab_i2c_mpu6050_6_axis_imu/issues).
