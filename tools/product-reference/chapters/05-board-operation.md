## **5 Board Operation**

The DevLab MPU-6050 module can be integrated into Arduino-compatible
development boards through the I²C communication interface. Before running any
application, install the
[DevLab_MPU6050 library](https://github.com/UNIT-Electronics-MX/unit_devlab_mpu6050_library)
from the Arduino Library Manager or download it from the official GitHub
repository.

### **Hardware Interface**

**I²C Connection**

Connect the module to the host board using the main I²C interface, available
through the `J2` header or the `J1`/`J3` QWIIC connectors:

| Module signal | Description | Host connection |
| --- | --- | --- |
| `VCC` | Power supply | Host supply (approved range pending validation) |
| `GND` | Ground | Host ground |
| `SDA` | I²C data | Host SDA pin |
| `SCL` | I²C clock | Host SCL pin |

The `INT` pin is optional and is only needed for interrupt-driven
applications. Host GPIO numbers belong to the controller, not the module. The
example below uses GPIO 6 for SDA and GPIO 7 for SCL on an ESP32 board(you can modify for your specific board):

```cpp
#define SDA_PIN 6
#define SCL_PIN 7
```

**Default I²C Address**

| Device | Address |
| --- | --- |
| MPU-6050 | `0x68` |

The module's default 7-bit I²C address is `0x68`. The sensor datasheet assigns
`0x68` when `AD0` is low and `0x69` when it is high.

### **Example Operation**

After `begin()`, the library applies the following configuration:

| Parameter | Resulting value |
| --- | --- |
| Clock source | PLL with X-axis gyroscope reference |
| Sample rate divider | 7 |
| Digital low-pass filter | Configuration 6 |
| Gyroscope full scale | ±500 °/s |
| Accelerometer full scale | ±8 g |
| I²C clock | 400 kHz |

### **Basic Operation**

The sensor reads three groups of values:

| Value | Description |
| --- | --- |
| Accelerometer | Raw 16-bit acceleration for each axis (`accX`, `accY`, `accZ`) |
| Gyroscope | Raw 16-bit angular rate for each axis (`gyrX`, `gyrY`, `gyrZ`) |
| Temperature | Internal die temperature, in °C (`temperatureC`) |

The accelerometer and gyroscope values are raw counts; their scale depends on
the selected full-scale range.

1. Connect the module to the microcontroller using the I²C interface.
2. Open the Arduino IDE.
3. Install the DevLab_MPU6050 library.
4. Open the `BasicRead` example sketch provided with the library.
5. Select the correct board and serial port.
6. Compile and upload the example.
7. Open the Serial Monitor to display the accelerometer, gyroscope, and
   temperature measurements.

During `begin()`, the library verifies communication by reading the
`WHO_AM_I` register (expected value `0x68`), wakes the sensor, and applies the
default configuration. If initialization fails, check the wiring, the supply,
and the I²C address.

Developers can modify the example code to configure:

- Accelerometer measurement range
- Gyroscope measurement range
- Digital low-pass filter
- Sample rate
- Clock source
- Interrupt generation

### **Example Code**

Use the `BasicRead` example included with the library, or copy the
following sketch into a new sketch:

```cpp
#include <DevLab_MPU6050.h>

#define SDA_PIN 6
#define SCL_PIN 7
#define MPU6050_ADDR 0x68

DevLab_MPU6050 imu(Wire, MPU6050_ADDR);

SensorData data;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Inicializando MPU6050...");

  if (!imu.begin(SDA_PIN, SCL_PIN, 400000)) {
    Serial.println("ERROR: MPU6050 no encontrado.");
    while (1) {
      delay(1000);
    }
  }

  Serial.println("MPU6050 inicializado correctamente.");
}

void loop() {
  if (imu.readData(data)) {
    Serial.print("aX = ");
    Serial.print(data.accX / 4096.0f);
    Serial.print(" | aY = ");
    Serial.print(data.accY / 4096.0f);
    Serial.print(" | aZ = ");
    Serial.print(data.accZ / 4096.0f);

    Serial.print(" | temp = ");
    Serial.print(data.temperatureC, 2);

    Serial.print(" | gX = ");
    Serial.print(data.gyrX);
    Serial.print(" | gY = ");
    Serial.print(data.gyrY);
    Serial.print(" | gZ = ");
    Serial.println(data.gyrZ);
  } else {
    Serial.println("ERROR: fallo en la lectura del MPU6050.");
  }

  delay(1000);
}

```

Module-level I²C clock validation and the approved `VCC` range remain pending
testing.
