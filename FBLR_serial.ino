// Motor A connections
int M1A1 = 2;      // Motor A input 1
int M1A2 = 3;      // Motor A input 2
int EN_A = 9;      // Enable A (PWM)

// Motor B connections
int M2B1 = 4;      // Motor B input 1
int M2B2 = 5;      // Motor B input 2
int EN_B = 10;     // Enable B (PWM)

void setup() {
  // Motor pin setup
  pinMode(M1A1, OUTPUT);
  pinMode(M1A2, OUTPUT);
  pinMode(M2B1, OUTPUT);
  pinMode(M2B2, OUTPUT);
  pinMode(EN_A, OUTPUT);
  pinMode(EN_B, OUTPUT);

  // Start Serial Monitor
  Serial.begin(9600);
  Serial.println("Motor driver ready...");
  Serial.println("Send F/B/L/R/S to control motors");

  stopMotors();
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();  // read the incoming character

    switch (command) {
      case 'F':
      case 'f':
        forward();
        break;

      case 'B':
      case 'b':
        backward();
        break;

      case 'L':
      case 'l':
        left();
        break;

      case 'R':
      case 'r':
        right();
        break;

      case 'S':
      case 's':
        stopMotors();
        break;

      default:
         break;
    }
  }
}

// ---- Functions ----

void forward() {
  Serial.println("Moving Forward");
  digitalWrite(M1A1, LOW);
  digitalWrite(M1A2, HIGH);
  digitalWrite(M2B1, LOW);
  digitalWrite(M2B2, HIGH);
  analogWrite(EN_A, 200);  // Speed 0-255
  analogWrite(EN_B, 200);
}

void backward() {
  Serial.println("Moving Backward");
  digitalWrite(M1A1, HIGH);
  digitalWrite(M1A2, LOW);
  digitalWrite(M2B1, HIGH);
  digitalWrite(M2B2, LOW);
  analogWrite(EN_A, 200);
  analogWrite(EN_B, 200);
}

void left() {
  Serial.println("Turning Left");
  digitalWrite(M1A1, HIGH);
  digitalWrite(M1A2, LOW);
  digitalWrite(M2B1, LOW);
  digitalWrite(M2B2, HIGH);
  analogWrite(EN_A, 200);
  analogWrite(EN_B, 200);
}

void right() {
  Serial.println("Turning Right");
  digitalWrite(M1A1, LOW);
  digitalWrite(M1A2, HIGH);
  digitalWrite(M2B1, HIGH);
  digitalWrite(M2B2, LOW);
  analogWrite(EN_A, 200);
  analogWrite(EN_B, 200);
}

void stopMotors() {
  Serial.println("Stopping Motors");
  digitalWrite(M1A1, LOW);
  digitalWrite(M1A2, LOW);
  digitalWrite(M2B1, LOW);
  digitalWrite(M2B2, LOW);
}
