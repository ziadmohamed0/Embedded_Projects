#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <MPU6050.h>

Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver(0x40); 
MPU6050 mpu; 

#define BASE_CHANNEL     0  
#define SHOULDER_CHANNEL 1 
#define ELBOW_CHANNEL    2 
#define WRIST_CHANNEL    3 
#define GRIP_CHANNEL     4  

#define IR_PIN D5

#define SDA_PIN D1  
#define SCL_PIN D2  

#define SERVOMIN  150  
#define SERVOMAX  600  

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN); 

  pca.begin();
  pca.setPWMFreq(50);

  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }

  pinMode(IR_PIN, INPUT);
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  float roll = atan2(ay, az) * 180 / PI;
  float pitch = atan2(-ax, sqrt(ay * ay + az * az)) * 180 / PI;

  int pwmBase = map(roll, -90, 90, SERVOMIN, SERVOMAX);    
  int pwmShoulder = map(pitch, -90, 90, SERVOMIN, SERVOMAX); 
  int pwmElbow = map(-pitch, -90, 90, SERVOMIN, SERVOMAX);   
  int pwmWrist = map(roll, -90, 90, SERVOMIN, SERVOMAX);   

  pca.setPWM(BASE_CHANNEL, 0, constrain(pwmBase, SERVOMIN, SERVOMAX));
  pca.setPWM(SHOULDER_CHANNEL, 0, constrain(pwmShoulder, SERVOMIN, SERVOMAX));
  pca.setPWM(ELBOW_CHANNEL, 0, constrain(pwmElbow, SERVOMIN, SERVOMAX));
  pca.setPWM(WRIST_CHANNEL, 0, constrain(pwmWrist, SERVOMIN, SERVOMAX));

  int irValue = digitalRead(IR_PIN);
  if (irValue == LOW) { 
    pca.setPWM(GRIP_CHANNEL, 0, SERVOMIN); 
  } else {
    pca.setPWM(GRIP_CHANNEL, 0, SERVOMAX); 
  }

  Serial.print("Roll: "); Serial.print(roll);
  Serial.print(" | Pitch: "); Serial.println(pitch);

  delay(50); 
}
