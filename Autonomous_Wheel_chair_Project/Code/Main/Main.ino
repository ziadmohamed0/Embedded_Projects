/**
 * @file Main.c
 * @author Zzard 
 * @brief 
 * @version 0.1
 * @date 2024-05-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/*********** Driver Motors(l298) Pins ***********/
#define IN_1 13
#define IN_2 12
#define IN_3 11
#define IN_4 10

/*********** Rooms Buttons Pins ***********/
#define button_A 9
#define button_B 8
#define button_C 7

/*********** Rooms Buzzer Pin ***********/
#define Buzzer	6

/*********** Rooms Ultrasonic Pins ***********/
#define Echo 5
#define Triger 4

/*********** Rooms Functions Prototypes ***********/
void X_ray(void);
void pharmacy(void);
void laboratory(void);

/*********** Motors Moves Functions Prototypes ***********/
void Motor_Forward(void);
void Motor_Reverse(void);
void Motor_Right(void);
void Motor_Left(void);
void Motor_Stop(void);

/*********** setUp Function ***********/
void setup(void) 
{
  Serial.begin(9600);
  
  pinMode(Buzzer, OUTPUT);

  pinMode(button_A,INPUT);
  pinMode(button_B,INPUT);
  pinMode(button_C,INPUT);
  
  pinMode(IN_1,OUTPUT);
  pinMode(IN_2,OUTPUT);
  pinMode(IN_3,OUTPUT);
  pinMode(IN_4,OUTPUT);

  pinMode(Triger,OUTPUT);
  pinMode(Echo,INPUT);

}

/*********** loop Function ***********/
void loop(void) 
{
  /*********** Buttons Local Variables ***********/
  int Button_1 = digitalRead(button_A); // X-Ray Room
  int Button_2 = digitalRead(button_B); // pharmacy Room
  int Button_3 = digitalRead(button_C); // laboratory Room

  /*********** Ultrasonic Local Variables ***********/
  int Distance = 0; // Distance equation
  int Duration = 0; // Data From Echo Pin

  /*********** Ultrasonic Initialization ***********/
  digitalWrite(Triger, LOW);
  delay(2);
  digitalWrite(Triger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Triger, LOW);

  /*********** Calc Distance ***********/
  Duration = pulseIn(Echo, HIGH); // get Data From Echo Pin

  Distance = Duration / 57.14;  // Distance equation
  
  if(Distance >= 4)
  {    
    digitalWrite(Buzzer, LOW); 

    /*********** X-Ray Room ***********/
    if(Button_1 == HIGH)
    {
      X_ray();
      Serial.println(" => You Are In X_ray Room.");
      Serial.println("================================");
    }

    /*********** pharmacy Room ***********/
    if(Button_2 == HIGH)
    {
      pharmacy();
      Serial.println(" => You Are In pharmacy Room.");
      Serial.println("================================");    
    }

    /*********** laboratory Room ***********/
    if(Button_3 == HIGH)
    {
      laboratory();
      Serial.println(" => You Are In laboratory Room.");
      Serial.println("================================");      
    }
  }

  else
  {
    Motor_Stop();
    digitalWrite(Buzzer, HIGH);
    Serial.println("* Some thing Wrong!!!!"); 
    Serial.println("=======================");      
  }

  Serial.print("Distance : ");
  Serial.println(Distance);
  Serial.println("******************");   
  delay(250);
}


/*********** Rooms Functions Prototypes ***********/

/**
 * @brief : Chair Move To X_ray From Zero point.
 * @Param : Void
 */
void X_ray(void)
{
  Motor_Forward();
  delay(2000);
  Motor_Stop();
  delay(200);

  Motor_Left();
  delay(500);
  Motor_Stop();
  delay(200);

  Motor_Forward();
  delay(1000);
  Motor_Stop();
  delay(200);

  Motor_Right();
  delay(500);
  Motor_Stop();
  delay(200);
}

/**
 * @brief : Chair Move To pharmacy From Zero point.
 * @Param : Void
 */
void pharmacy(void)
{
  Motor_Forward();
  delay(4000);
  Motor_Stop();
  delay(200);

  Motor_Left();
  delay(500);
  Motor_Stop();
  delay(200);

  Motor_Forward();
  delay(1000);
  Motor_Stop();
  delay(200);

  Motor_Right();
  delay(500);
  Motor_Stop();
  delay(200);
}

/**
 * @brief : Chair Move To laboratory From Zero point.
 * @Param : Void
 */
void laboratory(void)
{
  Motor_Forward();
  delay(6000);
  Motor_Stop();
  delay(200);

  Motor_Left();
  delay(500);
  Motor_Stop();
  delay(200);

  Motor_Forward();
  delay(1000);
  Motor_Stop();
  delay(200);
  
  Motor_Right();
  delay(500);
  Motor_Stop();
  delay(200);
}





/*********** Motors Moves Functions Definitions ***********/

/**
 * @brief : Motor Move Forward
 * @Param : Void
 */
void Motor_Forward(void)
{
  digitalWrite(IN_1,HIGH);
  digitalWrite(IN_2,LOW);
  digitalWrite(IN_3,LOW);
  digitalWrite(IN_4,HIGH);
}

/**
 * @brief : Motor Move Reverse
 * @Param : Void
 */
void Motor_Reverse(void)
{
  digitalWrite(IN_1,LOW);
  digitalWrite(IN_2,LOW);
  digitalWrite(IN_3,LOW);
  digitalWrite(IN_4,LOW);  
}

/**
 * @brief : Motor Move Right
 * @Param : Void
 */
void Motor_Right(void)
{
  digitalWrite(IN_1,HIGH);
  digitalWrite(IN_2,LOW);
  digitalWrite(IN_3,LOW);
  digitalWrite(IN_4,LOW);    
}

/**
 * @brief : Motor Move Left
 * @Param : Void
 */
void Motor_Left(void)
{
  digitalWrite(IN_1,LOW);
  digitalWrite(IN_2,LOW);
  digitalWrite(IN_3,HIGH);
  digitalWrite(IN_4,LOW);    
}

/**
 * @brief : Motor Stop
 * @Param : Void
 */
void Motor_Stop(void)
{
  digitalWrite(IN_1,LOW);
  digitalWrite(IN_2,LOW);
  digitalWrite(IN_3,LOW);
  digitalWrite(IN_4,LOW);   
}