const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin1 = 11;
const int buzzerPin2 = 12; 
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin1, OUTPUT);
  pinMode(buzzerPin2, OUTPUT);
  pinMode(buzzerPin3, OUTPUT);
  pinMode(buzzerPin4, OUTPUT);
  for (int i = 0; i < 2; i++) {
    digitalWrite(buzzerPin1, HIGH);
    digitalWrite(buzzerPin2, HIGH);
    delay(100);
    digitalWrite(buzzerPin1, LOW);
    digitalWrite(buzzerPin2, LOW);
    delay(100);
  }
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance <= 50) {
    analogWrite(buzzerPin1, map(distance, 0, 50, 255, 0));
    if (distance <= 23) {
      analogWrite(buzzerPin2, 255);
    } else {
      digitalWrite(buzzerPin2, LOW);
    }
  } else {
    digitalWrite(buzzerPin1, LOW);
    digitalWrite(buzzerPin2, LOW);
  }
  delay(100);
}