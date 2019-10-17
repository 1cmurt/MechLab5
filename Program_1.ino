#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *myMotorV = AFMS.getStepper(200, 2);
Adafruit_StepperMotor *myMotorR = AFMS.getStepper(200, 1);


void setup() {
  Serial.begin(9600);   

  AFMS.begin();  // create with the default frequency 1.6KHz
  
  myMotorV->setSpeed(10);  // 10 rpm   
}

void loop() {
  Serial.println("Single coil steps");
  myMotor->step(100, FORWARD, SINGLE); 
  myMotor->step(100, BACKWARD, SINGLE); 

  Serial.println("Double coil steps");
  myMotor->step(100, FORWARD, DOUBLE); 
  myMotor->step(100, BACKWARD, DOUBLE);
  
  Serial.println("Interleave coil steps");
  myMotor->step(100, FORWARD, INTERLEAVE); 
  myMotor->step(100, BACKWARD, INTERLEAVE); 
  
  Serial.println("Microstep steps");
  myMotor->step(50, FORWARD, MICROSTEP); 
  myMotor->step(50, BACKWARD, MICROSTEP);
}
