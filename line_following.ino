  int vSpeed = 90;        // MAX 255
  int turn_speed = 110;    // MAX 255 
  int turn_delay = 10;
  
//L293 Connection   
  const int motorA1      = 5;  
  const int motorA2      = 4; 
  const int motorAspeed  = 9;
  const int motorB1      = 6; 
  const int motorB2      = 7; 
  const int motorBspeed  = 11;

//Sensor Connection
  const int left_sensor_pin =12;
  const int right_sensor_pin =13;

  
  
  int left_sensor_state;
  int right_sensor_state;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  Serial.begin(9600);

  delay(3000);
  
}

void loop() {
  

  


left_sensor_state = digitalRead(left_sensor_pin);
right_sensor_state = digitalRead(right_sensor_pin);

if(right_sensor_state ==0 && left_sensor_state ==1)
{
  Serial.println("turning right");
  Serial.println(right_sensor_state);
  Serial.println(left_sensor_state);


  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, turn_speed);
  
  }
if(right_sensor_state ==1 && left_sensor_state ==0)
{
  Serial.println("turning left");
  
  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, turn_speed);
  analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
  }

if(right_sensor_state ==1 && left_sensor_state ==1)
{
  Serial.println("going forward");

  digitalWrite (motorA2,HIGH);
  digitalWrite(motorA1,LOW);                       
  digitalWrite (motorB2,LOW);
  digitalWrite(motorB1,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
  
  }

if(right_sensor_state ==0 && left_sensor_state ==0)
{ 
  Serial.println("stop");
  digitalWrite (motorA2,LOW);
  digitalWrite(motorA1,LOW);                       
  digitalWrite (motorB2,LOW);
  digitalWrite(motorB1,LOW);

  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, 0);
  delay(3000);
  }

 
}
 