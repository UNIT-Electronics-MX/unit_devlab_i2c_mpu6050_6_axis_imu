#include <Wire.h>

#define MPU6050_ADDR 0x68   // Dirección típica. Si AD0 está en HIGH puede ser 0x69

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Cambia estos pines si usas ESP32/RP2040 con pines específicos
  //Wire.begin(); 
  // Ejemplo ESP32/RP2040:
   Wire.begin(1, 6); // SDA, SCL

  Serial.println("Prueba rápida MPU6050");

  // Despertar MPU6050
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B);   // PWR_MGMT_1
  Wire.write(0x00);   // Wake up
  if (Wire.endTransmission() == 0) {
    Serial.println("MPU6050 encontrado y despertado.");
  } else {
    Serial.println("No se detecta MPU6050. Revisa conexión/dirección.");
    while (1);
  }

  // Leer WHO_AM_I
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x75);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 1);

  if (Wire.available()) {
    byte whoami = Wire.read();
    Serial.print("WHO_AM_I: 0x");
    Serial.println(whoami, HEX);
  }
}

void loop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  int16_t tempRaw;

  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B); // Registro inicial ACCEL_XOUT_H
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 14);

  if (Wire.available() == 14) {
    ax = Wire.read() << 8 | Wire.read();
    ay = Wire.read() << 8 | Wire.read();
    az = Wire.read() << 8 | Wire.read();

    tempRaw = Wire.read() << 8 | Wire.read();

    gx = Wire.read() << 8 | Wire.read();
    gy = Wire.read() << 8 | Wire.read();
    gz = Wire.read() << 8 | Wire.read();

    float ax_g = ax / 16384.0;
    float ay_g = ay / 16384.0;
    float az_g = az / 16384.0;

    float gx_dps = gx / 131.0;
    float gy_dps = gy / 131.0;
    float gz_dps = gz / 131.0;

    float tempC = tempRaw / 340.0 + 36.53;

    Serial.println("------ MPU6050 ------");
    Serial.print("ACC g  X: "); Serial.print(ax_g, 3);
    Serial.print(" Y: "); Serial.print(ay_g, 3);
    Serial.print(" Z: "); Serial.println(az_g, 3);

    Serial.print("GYRO °/s X: "); Serial.print(gx_dps, 2);
    Serial.print(" Y: "); Serial.print(gy_dps, 2);
    Serial.print(" Z: "); Serial.println(gz_dps, 2);

    Serial.print("Temp: ");
    Serial.print(tempC, 2);
    Serial.println(" °C");
  } else {
    Serial.println("Error leyendo datos del MPU6050");
  }

  delay(500);
}