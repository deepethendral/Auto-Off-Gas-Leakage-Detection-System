#include <Servo.h>

// Pin Definitions
const int gasSensorPin = A0; // MQ-2 sensor connected to analog pin A0
const int buzzerPin = 8;     // Buzzer connected to digital pin 8
const int fanPin = 7;        // MOSFET (Fan control) connected to digital pin 7
const int threshold = 500;   // Gas level threshold for detection
Servo servoMotor;            // Servo motor

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Setup pin modes
  pinMode(gasSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(fanPin, OUTPUT);

  // Attach the servo motor to pin 9
  servoMotor.attach(9);
  servoMotor.write(90); // Set servo to initial position (open gas regulator)

  // Initial states
  digitalWrite(buzzerPin, LOW); // Turn off buzzer
  digitalWrite(fanPin, LOW);    // Turn off fan
}

void loop() {
  // Read the gas sensor value
  int gasLevel = analogRead(gasSensorPin);
  Serial.print("Gas level: ");
  Serial.println(gasLevel); // Print gas level for debugging

  // Check if gas level exceeds the threshold (indicating a leak/fire)
  if (gasLevel > threshold) {
    Serial.println("Gas leak detected! Activating fan and buzzer.");  // Debug message
    digitalWrite(buzzerPin, HIGH);  // Turn on the buzzer
    digitalWrite(fanPin, HIGH);     // Turn on the fan
    servoMotor.write(0);            // Turn off the gas regulator (move servo to 0 degrees)

    delay(5000); // Keep the system on for 5 seconds before checking again
  } else {
    Serial.println("No gas leak detected.");  // Debug message
    digitalWrite(buzzerPin, LOW);   // Turn off the buzzer
    digitalWrite(fanPin, LOW);      // Turn off the fan
    servoMotor.write(90);           // Keep the gas regulator open (servo at 90 degrees)
  }

  delay(5000); // Wait for 5 seconds before next sensor reading
}
