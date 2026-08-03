## **2 Electrical Characteristics**

### **2.1 Confirmed Circuit Values**

| Symbol / parameter | Description | Value | Scope |
|---|---|---:|---|
| `VDD` | Operating supply | 2.375 to 3.46 V | MPU-6050 sensor pins |
| `VLOGIC` | Logic reference | 1.71 V to `VDD` | MPU-6050 sensor pin |
| Accelerometer range | Selectable full scale | ±2, ±4, ±8, or ±16 g | MPU-6050 sensor |
| Gyroscope range | Selectable full scale | ±250, ±500, ±1000, or ±2000 dps | MPU-6050 sensor |
| ADC word length | Per accelerometer / gyroscope axis | 16 bit | MPU-6050 sensor |
| I2C operating frequency | Fast-mode maximum | 400 kHz | MPU-6050 sensor interface |
| Six-axis current | Gyroscope + accelerometer, DMP disabled | 3.8 mA typical | MPU-6050 sensor only |
| Six-axis + DMP current | Gyroscope + accelerometer + DMP | 3.9 mA typical | MPU-6050 sensor only |
| `3V3` | Regulated output from `U2` | 3.3 V nominal | AP2112K-3.3 regulator output |
| `C1`, `C2` | Regulator input/output capacitors | 1 µF each | Individual BOM components |
| `R5` | Power-indicator series resistor | 4.7 kΩ | Individual BOM component |
| `R1`–`R4`, `R6`–`R10` | Pull-up / bias resistors | 10 kΩ each | Individual BOM components |

The allowed voltage at the module `VCC` connections, module current
consumption, host-side digital thresholds, and complete-module I2C clock limit
are **pending validation**. The sensor, regulator, connector, MOSFET, resistor,
and capacitor component ratings are not ratings for the complete module.

### **2.2 Electrical Precautions**

- Establish a common `GND` before applying power or interface signals.
- Verify the module-level `VCC` range before applying power.
- Keep host signals within validated logic levels; those limits are not yet
  documented for the complete module.
- Treat `INT` as an output from the sensor and `CLKIN`, `FSYNC`, and `AD0` as
  sensor inputs according to the released schematic.
