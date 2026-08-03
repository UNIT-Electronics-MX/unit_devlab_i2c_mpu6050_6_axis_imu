## **5 Board Operation**

The `DevLab_MPU6050` firmware under `software/examples/arduino/` is
experimental and is intentionally not reproduced here as a validated example.
It configures host GPIO 12 as SDA, host GPIO 22 as SCL, sensor address `0x68`,
and a 400 kHz I2C clock. The GPIO values are controller assignments, not module
pin numbers, and the complete setup remains pending validation.

For initial bench evaluation:

1. Inspect the board and confirm the intended connector orientation.
2. Verify the module `VCC` range from an approved test record before applying
   power.
3. Connect module and host grounds.
4. Connect the host I2C clock and data lines to `SCL` and `SDA`.
5. Verify the `AD0` configuration against the physical board. The sensor
   datasheet assigns 7-bit address `0x68` when `AD0` is low and `0x69` when it
   is high.
6. Confirm communication and sensor configuration with test equipment before
   relying on measurement data.

Host GPIO numbers belong to the controller, not the module. Module-level I2C
clock validation, board-default address, configuration sequences, and example
firmware are pending testing.
