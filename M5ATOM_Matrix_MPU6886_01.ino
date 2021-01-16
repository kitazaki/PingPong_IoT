#include <M5Atom.h>

float gyroX, gyroY, gyroZ;  // ジャイロデータ取得　→回転(左90 0/-50/0, 右90 0/50/0)
float ax, ay, az;  // 加速度データ取得　→傾き(X/Y/Z: 正 0/0/1, 左90 1/0/0, 右90 -1/0/0, 上90 0/-1/0, 下90 0/1/0)

void setup() {
  Serial.begin(115200);
  M5.begin();
  M5.IMU.Init();
}

void loop() {
  M5.IMU.getGyroData(&gyroX, &gyroY, &gyroZ);
  M5.IMU.getAccelData(&ax, &ay, &az);

  // ジャイロデータプロット
//  Serial.printf("%7.2f,%7.2f,%7.2f\n", gyroX * M5.IMU.gRes * 1, gyroY * M5.IMU.gRes * 100, gyroZ * M5.IMU.gRes * 10);

  // 加速度データプロット
//  Serial.printf("%7.2f,%7.2f,%7.2f\n", ax , ay , az);
  Serial.printf("%7.2f,%7.2f,%7.2f\n", ax * 10, ay * 10, az);

  delay(10);
}
