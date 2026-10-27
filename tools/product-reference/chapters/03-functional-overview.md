## **3 Functional Overview**

### **3.1 Block Diagram**

The block diagram shows the main functional blocks of the MPU-6050 and the
signals available on the module.

![MPU-6050 block diagram.](hardware/resources/unit_block_diagram_v_1_0_0_ue0129_mpu6050.png){width=6.3in}

### **3.2 Sensor and Main I2C Path**

The MPU-6050 provides three-axis acceleration and three-axis angular-rate
sensing with 16-bit conversion per axis and selectable full-scale ranges. Its
1024-byte FIFO can buffer sensor data. `Q1` translates the main `SCL` and `SDA` lines between the module
`VCC` domain and the sensor's regulated 3.3 V domain. `J1`, `J3`, and `J2`
provide access to the main bus.

### **3.3 Auxiliary and Control Signals**

`Q2` translates the MPU-6050 auxiliary `AUX_SCL` and `AUX_SDA` lines to the
board `ASCL` and `ASDA` connections. The board also routes `INT`, `AD0`,
`FSYNC`, and `CLKIN`. The schematic shows `R6` connected from `AD0` to ground;
the physical defaults of the solder options shown in the artwork remain
pending validation.

### **3.4 Power Section**

The schematic identifies `U2` as an AP2112K-3.3 regulator supplied from `VCC`.
Its 3.3 V output powers both MPU-6050 supply pins and the sensor-side I2C
pull-ups. The complete module input range is pending validation and must not be
derived from the regulator's component rating.

![Bottom view of the UE0129 module, artwork V1.1.](hardware/resources/unit_btm_v_1_1_0_ue0129_mpu6050_3d.png){width=5.4in}

### **3.5 Communication Interfaces**

The MPU-6050 supports a single digital communication interface, I²C, providing
connectivity with microcontrollers and embedded systems.

**I²C Interface**

- Standard Mode and Fast Mode
- Clock frequency up to 400 kHz
- Two selectable 7-bit I²C addresses: `0x68` and `0x69`
- I²C address selection through the `AD0` pin

The device supports two selectable 7-bit I²C addresses through the `AD0` pin:
when `AD0` is low, the address is `0x68`; when `AD0` is high, the address is
`0x69`. On the DevLab module, `AD0` is routed to the `J5` connector and has a
10 kΩ resistor (`R6`) to ground. The physical default of the `AD0` solder
option remains pending validation, so confirm the address on the board before
use.


### **3.6 Library Features**

The [DevLab_MPU6050 library](https://github.com/UNIT-Electronics-MX/unit_devlab_mpu6050_library)
for Arduino-compatible boards communicates with the sensor through direct I²C
register access. It is tested on ESP32 and compatible with other
Arduino-compatible boards. The following table summarizes the sensor
functions available through the library.

| Function | Library call | Description |
| --- | --- | --- |
| Initialization | `begin(sda, scl, clock)` | Starts I²C on custom pins (400 kHz by default), verifies `WHO_AM_I`, wakes the sensor, and applies the default configuration. |
| Data acquisition | `readData(data)` | Reads raw 16-bit accelerometer and gyroscope values for X, Y, and Z in a single 14-byte burst, plus the temperature in °C. |
| Accelerometer range | `setAccelScale(scale)` | Selects ±2 g, ±4 g, ±8 g, or ±16 g (values 0 to 3). |
| Gyroscope range | `setGyroScale(scale)` | Selects ±250, ±500, ±1000, or ±2000 °/s (values 0 to 3). |
| Digital low-pass filter | `setDLPF(setting)` | Selects the DLPF configuration in the `CONFIG` register (values 0 to 6). |
| Sample rate | `sampleRateDiv(div)` | Sets the sample rate divider (`SMPLRT_DIV`). |
| Clock source | `setClkSource(source)` | Selects the clock source in `PWR_MGMT_1` (values 0 to 7). |
| Device identification | `WhoAmI()` | Returns the `WHO_AM_I` register value. |
| Interrupt pin | `setIntPinCfg(cfg)` | Configures `INT` polarity, output type, latch, clear-on-read, `FSYNC`, and I²C bypass. |
| Interrupt sources | `enableInterrupt()`, `disableInterrupt()` | Enables or disables data ready, I²C master, FIFO overflow, and motion interrupts. |
| Interrupt status | `interruptStatus()` | Reads `INT_STATUS` to identify which source fired. |

The I²C address is passed to the library constructor and is not detected
automatically. Use `MPU6050_ADDRESS_AD0_LOW` (`0x68`) or
`MPU6050_ADDRESS_AD0_HIGH` (`0x69`) according to the `AD0` level. The
`WHO_AM_I` check in `begin()` expects `0x68` regardless of the selected address.

**Default configuration applied by `begin()`**

| Parameter | Default value |
| --- | --- |
| Clock source | PLL with X-axis gyroscope reference |
| Sample rate divider | 7 |
| Digital low-pass filter | Configuration 6 |
| Gyroscope range | ±500 °/s |
| Accelerometer range | ±8 g |

Use the configuration functions above to change these values after calling
`begin()`.

**Example sketches**

- `BasicRead` and `MPU6050_BasicRead`: read acceleration, angular rate, and temperature and print them over the serial port.
- `I2CIdentify`: initializes the sensor and reads the `WHO_AM_I` register.
- `MPU6050_ConfigSweep`: sweeps every combination of accelerometer range, gyroscope range, and DLPF setting and prints one reading per combination as CSV, useful for characterizing each setting.
- `basic_Interrupt` and `MPU6050_Interrupt`: enable the data-ready interrupt on the `INT` pin and count the interrupts it generates.

### **3.7 Board Topology**

The released topology drawing locates the sensor, regulator, level shifters,
connectors, and solder options on the top and bottom sides of the board.

![Top and bottom board topology.](hardware/resources/unit_topology_v_1_0_0_ue0129_mpu6050.png){width=6.3in}

### **3.8 Electrical Schematic**

The image below is rendered from the released V1.0 schematic. Use the
[original schematic PDF](https://github.com/UNIT-Electronics-MX/unit_devlab_i2c_mpu6050_6_axis_imu/blob/main/hardware/unit_sch_v_1_0_0_ue129_mpu6050_imu.pdf)
to inspect small component and net labels at full resolution.

![V1.0 electrical schematic.](hardware/resources/unit_sch_v_1_0_0_ue129_mpu6050_imu.png){width=6.3in}
