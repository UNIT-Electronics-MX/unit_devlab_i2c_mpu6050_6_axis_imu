## **3 Functional Overview**

### **3.1 Sensor and Main I2C Path**

The MPU-6050 provides three-axis acceleration and three-axis angular-rate
sensing with 16-bit conversion per axis and selectable full-scale ranges. Its
1024-byte FIFO can buffer sensor data. `Q1` translates the main `SCL` and `SDA` lines between the module
`VCC` domain and the sensor's regulated 3.3 V domain. `J1`, `J3`, and `J2`
provide access to the main bus.

### **3.2 Auxiliary and Control Signals**

`Q2` translates the MPU-6050 auxiliary `AUX_SCL` and `AUX_SDA` lines to the
board `ASCL` and `ASDA` connections. The board also routes `INT`, `AD0`,
`FSYNC`, and `CLKIN`. The schematic shows `R6` connected from `AD0` to ground;
the physical defaults of the solder options shown in the artwork remain
pending validation.

### **3.3 Power Section**

The schematic identifies `U2` as an AP2112K-3.3 regulator supplied from `VCC`.
Its 3.3 V output powers both MPU-6050 supply pins and the sensor-side I2C
pull-ups. The complete module input range is pending validation and must not be
derived from the regulator's component rating.

![](hardware/resources/unit_btm_v_1_0_0_i2c_mpu6050_6_axis_imu.png){width=5.4in}
