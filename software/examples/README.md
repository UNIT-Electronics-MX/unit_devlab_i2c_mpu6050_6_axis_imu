# Software Examples

Examples in this directory are experimental until they have been tested with
the released DevLab I2C MPU-6050 6-Axis IMU Module.

## Arduino

- [DevLab_MPU6050 basic readout](https://github.com/UNIT-Electronics-MX/unit_devlab_i2c_mpu6050_6_axis_imu/blob/main/software/examples/arduino/devlab_mpu6050_basic/devlab_mpu6050_basic.ino): initializes the sensor and prints acceleration, die temperature, and angular-rate data.

The example requires the external `DevLab_MPU6050` library. Its approved
source and installation instructions have not yet been added to this
repository.

## Existing Test Files

The files under `test/` and `mp/` are retained as development material. They
are not validated getting-started examples.

Host GPIO assignments shown in any example belong to the controller and are
not module pin numbers.
