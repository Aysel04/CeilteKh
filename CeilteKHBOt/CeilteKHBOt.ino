const int trigPin = 9;    
const int echoPin = 10;   
const int motor1Pin1 = 3; 
const int motor1Pin2 = 4; 
const int motor2Pin1 = 5; 
const int motor2Pin2 = 6; 
const int enable1Pin = 7; 
const int enable2Pin = 8; 

long duration;
int distance;

void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  Serial.begin(9600);
}

long getDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

void moveForward() {
  digitalWrite(enable1Pin, HIGH);
  digitalWrite(enable2Pin, HIGH);
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void stop() {
  digitalWrite(enable1Pin, LOW);
  digitalWrite(enable2Pin, LOW);
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

void turnRight() {
  digitalWrite(enable1Pin, HIGH);
  digitalWrite(enable2Pin, HIGH);
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void loop() {
  distance = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 20) { 
    stop();
    delay(1000); 
    turnRight();
    delay(1000); 
  } else {
    moveForward();
  }

  delay(100); 
} 