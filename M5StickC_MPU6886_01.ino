#include <M5StickC.h>

float gyroX, gyroY, gyroZ;  // ジャイロデータ取得　→回転(左90 0/-50/0, 右90 0/50/0)
float ax, ay, az;  // 加速度データ取得　→傾き(X/Y/Z: 正 0/0/1, 左90 1/0/0, 右90 -1/0/0, 上90 0/-1/0, 下90 0/1/0)

void setup() {
  Serial.begin(115200);
  M5.begin();
  M5.MPU6886.Init();
}

void loop() {
  M5.MPU6886.getGyroData(&gyroX, &gyroY, &gyroZ);
  M5.MPU6886.getAccelData(&ax, &ay, &az);
  M5.Lcd.setCursor(0, 30);

  // ジャイロデータプロット
  M5.Lcd.printf("X:%7.2f\nY:%7.2f\nZ:%7.2f mg\n\n", gyroX * M5.MPU6886.gRes * 10, gyroY * M5.MPU6886.gRes * 10, gyroZ * M5.MPU6886.gRes * 10);
//  Serial.printf("%7.2f,%7.2f,%7.2f\n", gyroX * M5.MPU6886.gRes, gyroY * M5.MPU6886.gRes, gyroZ * M5.MPU6886.gRes);
  Serial.printf("%7.2f,%7.2f,%7.2f\n", gyroX * M5.MPU6886.gRes * 1, gyroY * M5.MPU6886.gRes * 100, gyroZ * M5.MPU6886.gRes * 10);

  // 加速度データプロット
  M5.Lcd.printf("X:%7.2f\nY:%7.2f\nZ:%7.2f mg", ax * 10 , ay * 10, az );
//  Serial.printf("%7.2f,%7.2f,%7.2f\n", ax , ay , az);
//  Serial.printf("%7.2f,%7.2f,%7.2f\n", ax * 10, ay * 10, az);

  delay(10);
}
