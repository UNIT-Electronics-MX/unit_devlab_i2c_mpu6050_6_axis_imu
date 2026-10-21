## **4 Connectors and Pinout**

The released pinout drawing shows the top and bottom board views and the
connector signal labels. Confirm connector orientation on the physical board
before assigning numeric pin positions or connecting a cable.

![UE0129 pinout, top and bottom views.](hardware/resources/unit_pinout_v_1_0_0_ue0129_mpu6050_en.png){width=5.0in}

### **4.1 Main Interface Edge (`J2`)**

| Board label | Direction / type | Function |
|---|---|---|
| `VCC` | Power input | Module input rail; allowed range pending validation |
| `GND` | Power | Common ground |
| `SCL` | I2C clock | Main host-side I2C clock |
| `SDA` | I2C data | Main host-side I2C data |
| `INT` | Output | MPU-6050 interrupt signal |

### **4.2 Auxiliary and Control Edge (`J5`)**

| Board label | Direction / type | Function |
|---|---|---|
| `AD0` | Input | MPU-6050 I2C address-selection input |
| `CLKIN` | Input | External clock input to the MPU-6050 |
| `FSYNC` | Input | Frame-synchronization input |
| `ASCL` | I2C clock | Host-side auxiliary I2C clock |
| `ASDA` | I2C data | Host-side auxiliary I2C data |

### **4.3 Four-Position Connectors**

| Reference | Signals | Bus |
|---|---|---|
| `J1`, `J3` | `VCC`, `GND`, `SDA`, `SCL` | Main I2C |
| `J4`, `J6` | `VCC`, `GND`, `ASDA`, `ASCL` | Auxiliary I2C |

The BOM identifies all four as JST `SM04B-SRSS-TB(LF)(SN)` connectors. The
artwork labels them `QWIIC`, but connector orientation, numeric pin numbering,
and cable compatibility must be verified before assembly or connection.

### **4.4 Solder Options**

The bottom artwork identifies options for `FSYNC`, `CLKIN`, and `AD0`. Their
default copper states and intended operating configurations are pending
validation.
