> **Note of Development:**  
> This hardware module is under active development. File and directory structures, naming conventions, and documentation formats may change as the design evolves.  
> 
> - **File Naming:**  
>   - Use capital letters and underscores only.  
>   - Start filenames with `unit_<filename>_v_<version>_<description>.<ext>`.  
>   - Example: `unit_mpu6050_6_axis_imu_v_1_0_0.png`
>   - Schematic: `schematic_v_<version>_<description>.<ext>` (e.g., `schematic_v_1_0_0_mpu6050_6_axis_imu.png`)
>   - Topology: `unit_topology_v_<version>_<description>.<ext>`
>   - Dimensions: `unit_dimension_v_<version>_<description>.<ext>`
> 
> - **README Structure:**  
>   - Hardware overview  
>   - Pinout and connector layout  
>   - Dimensions and topology  
>   - Functional description  
>   - Applications  
>   - References  
> 
> Please refer to the latest commit history for updates and changes.

# Hardware

<div align="center">
<a href="https://github.com/UNIT-Electronics-MX/unit_devlab_i2c_mpu6050_6_axis_imu/blob/main/hardware/unit_sch_v_1_0_0_ue129_mpu6050_imu.pdf"><img src="resources/Schematics_icon.jpg?raw=false" width="200px" alt="Schematic Diagram"><br/>Schematic</a>
</div>

The V1.0 module is identified in manufacturing records as UE0129. The
manufacturer part number is retained here for traceability and is not the
product name.


## Pinout

<div align="center">
    <a href="./unit_pinout_v_1_0_0_ue0129_mpu6050_en.pdf"><img src="./resources/unit_pinout_v_1_0_0_ue0129_mpu6050_en.png" width="500px"><br/>Pinout</a>
    <br/>
    <br/>
    <br/>


| Connection group | Signal | Direction / type | Function |
|---|---|---|---|
| `J2` | `VCC` | Power input | Module input rail; allowed range pending validation |
| `J2` | `GND` | Power | Common ground |
| `J2` | `SCL` | I2C clock | Main host-side I2C clock |
| `J2` | `SDA` | I2C data | Main host-side I2C data |
| `J2` | `INT` | Output | MPU-6050 interrupt output |
| `J5` | `AD0` | Input | MPU-6050 I2C address-selection input |
| `J5` | `CLKIN` | Input | External clock input to the MPU-6050 |
| `J5` | `FSYNC` | Input | Frame-synchronization input |
| `J5` | `ASCL` | I2C clock | Host-side connection to the auxiliary I2C clock |
| `J5` | `ASDA` | I2C data | Host-side connection to the auxiliary I2C data |

</div>

## Dimensions

<div align="center">
<a href="./resources/unit_topology_v_1_0_0_ue0129_mpu6050.png"><img src="./resources/unit_dimensions_v_1_0_0_ue0129_mpu6050.png" width="500px"><br/> Dimensions</a>
</div>

## Topology

<div align="center">

<div align="center">
<a href="./resources/unit_topology_v_1_0_0_ue0129_mpu6050.png"><img src="./resources/unit_topology_v_1_0_0_ue0129_mpu6050.png" width="500px"><br/> Topology</a>
<br/>
<br/>
<br/>


 The schematic confirms the following
functional blocks:

| Ref. | Description |
|---|---|
| `IC1` | MPU-6050 three-axis accelerometer and three-axis gyroscope |
| `U2` | AP2112K-3.3 fixed 3.3 V regulator |
| `Q1`, `Q2` | BSS138AKDW dual N-channel MOSFET arrays used for I2C level shifting |
| `J1`, `J3` | Four-position main I2C connectors (`VCC`, `GND`, `SDA`, `SCL`) |
| `J4`, `J6` | Four-position auxiliary I2C connectors (`VCC`, `GND`, `ASDA`, `ASCL`) |
| `J2`, `J5` | 1x5, 2.54 mm signal headers / castellated connections |
| `D1`, `R5` | Red power indicator and 4.7 kΩ series resistor |

## Pin & Connector Layout

| Connector | Signals shown by schematic | Notes |
|---|---|---|
| `J1`, `J3` | `VCC`, `GND`, `SDA`, `SCL` | Main I2C bus; 4-position JST SR-series parts in the BOM |
| `J4`, `J6` | `VCC`, `GND`, `ASDA`, `ASCL` | Auxiliary I2C bus; 4-position JST SR-series parts in the BOM |
| `J2` | `VCC`, `GND`, `SCL`, `SDA`, `INT` | Main interface edge |
| `J5` | `AD0`, `CLKIN`, `FSYNC`, `ASCL`, `ASDA` | Configuration and auxiliary interface edge |

The board artwork labels the four JST connectors as `QWIIC`, but cable and
ecosystem compatibility have not been validated. The BOM lists one four-pin,
1 mm-pitch harness as `Wire`; package contents remain pending confirmation.

## Functional Description

`U2` generates the 3.3 V rail used by the MPU-6050. `Q1` translates the main
`SCL` and `SDA` lines between the `VCC` and 3.3 V domains; `Q2` performs the
same function for `ASCL` and `ASDA`. The MPU-6050 exposes acceleration and
angular-rate data through its main I2C interface. Its interrupt, address
selection, frame-synchronization, external-clock, and auxiliary I2C signals
are routed to board connections.

The schematic shows a 10 kΩ resistor (`R6`) from `AD0` to ground and board
artwork shows solder options for `AD0`, `FSYNC`, and `CLKIN`. The physical
defaults and intended solder-option operation are pending validation.

The BOM also confirms 1 µF regulator capacitors (`C1`, `C2`), a 2.2 nF
capacitor (`C3`), a 100 nF capacitor (`C4`), 10 nF capacitors (`C5`, `C6`),
nine 10 kΩ resistors, and the red indicator LED. Component ratings are not
module-level electrical ratings.

The MPU-6050 product specification documents selectable accelerometer ranges
of ±2 g, ±4 g, ±8 g, and ±16 g; selectable gyroscope ranges of ±250,
±500, ±1000, and ±2000 dps; and 16-bit conversion for each axis. It also
specifies a maximum 400 kHz I2C clock for the sensor. These are sensor
characteristics, not independently validated limits for the complete module.

## Applications

- Evaluation of three-axis acceleration and three-axis angular rate
- Motion-sensing prototypes
- I2C sensor integration and educational experiments
- Experiments with interrupt, synchronization, and auxiliary-sensor signals

# References

- [Repository](https://github.com/UNIT-Electronics-MX/unit_devlab_i2c_mpu6050_6_axis_imu)
- [MPU-6000 and MPU-6050 Product Specification, Revision 3.4](https://github.com/UNIT-Electronics-MX/unit_devlab_i2c_mpu6050_6_axis_imu/blob/main/hardware/resources/external/mpu-6050_datasheet_v3%204.pdf)
- [Schematic Diagram](https://github.com/UNIT-Electronics-MX/unit_devlab_i2c_mpu6050_6_axis_imu/blob/main/hardware/unit_sch_v_1_0_0_ue129_mpu6050_imu.pdf)
- [Manufacturing BOM](https://github.com/UNIT-Electronics-MX/unit_devlab_i2c_mpu6050_6_axis_imu/blob/main/hardware/resources/UNIT-0129-%20MPU6050-20260803T164655Z-1-001/UNIT-0129-%20MPU6050/Fabricacion/BOM/UE0129-BOM-MPU6050-001-T.xlsx)
- [Experimental DevLab_MPU6050 example](https://github.com/UNIT-Electronics-MX/unit_devlab_i2c_mpu6050_6_axis_imu/blob/main/software/examples/arduino/devlab_mpu6050_basic/devlab_mpu6050_basic.ino)

The sensor datasheet values above apply to the MPU-6050 component. The
module-level electrical limits remain pending board validation.
