#include <MPU6050_tockn.h>
#include <Wire.h>
#include <LiquidCrystal.h>
//taarif LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

MPU6050 mpu6050(Wire);

long timer = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
   lcd.begin(16, 2);
   lcd.print("x:");
   lcd.setCursor(8,0);
   lcd.print("y:");
   lcd.setCursor(5,1);
   lcd.print("z:");
   
}

void loop() {
  mpu6050.update();
//HAR 1 SANIE DATA BEHET MIDE
  if(millis() - timer > 1000){
    //DATA MRBOOT BE GYROSCOPE
    Serial.print("gyroX : ");Serial.print(mpu6050.getGyroX());
    Serial.print("	gyroY : ");Serial.print(mpu6050.getGyroY());
    Serial.print("	gyroZ : ");Serial.println(mpu6050.getGyroZ());
  //DATA MARBOT BE SHETAB
    Serial.print("accAngleX : ");Serial.print(mpu6050.getAccAngleX());
    Serial.print("	accAngleY : ");Serial.println(mpu6050.getAccAngleY());
  //DATA MARBOOT BE ZAVIE GYROSCOPE 
    Serial.print("gyroAngleX : ");Serial.print(mpu6050.getGyroAngleX());
    Serial.print("	gyroAngleY : ");Serial.print(mpu6050.getGyroAngleY());
    Serial.print("	gyroAngleZ : ");Serial.println(mpu6050.getGyroAngleZ());
    //maqadir zir dar LCD namayesh dde mishe KE MARBOOT BE ZAVIE MISHE 
    Serial.print("angleX : ");Serial.print(mpu6050.getAngleX());
    Serial.print("	angleY : ");Serial.print(mpu6050.getAngleY());
    Serial.print("	angleZ : ");Serial.println(mpu6050.getAngleZ());

    timer = millis();
    //MARBOOT BE NAMAYESH DATA DAR 
    lcd.setCursor(2,0);
    String strx = String(mpu6050.getAngleX());
    lcd.print(strx.substring(0,5));
    lcd.setCursor(10,0);
    String stry = String(mpu6050.getAngleY());
    lcd.print(stry.substring(0,5));
    lcd.setCursor(7,1);
    String strz = String(mpu6050.getAngleZ());
    lcd.print(strz.substring(0,5));
  }

} 
