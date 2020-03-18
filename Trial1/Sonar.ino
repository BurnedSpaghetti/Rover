int trigPin1 = 8;
int trigPin2 = 3;
int trigPin3 = 5;
int trigPin4 = 9;
int trigPin5 = 7;
int trigPin6 = 6;

const int echoPin1 = 14;
const int echoPin2 = 15;
const int echoPin3 = 16;
const int echoPin4 = 17;
const int echoPin5 = 18;
const int echoPin6 = 19;
float duration, distance;

float RightSensor, BackSensor1, BackSensor2, BackSensor3, FrontSensor, LeftSensor;

void Sonarsetup(){
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(trigPin5, OUTPUT);
  pinMode(trigPin6, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);
  pinMode(echoPin5, INPUT);
  pinMode(echoPin6, INPUT);
  Serial.begin(9600);
}
void Ultra() {
  SonarSensor(trigPin1, echoPin1);
  RightSensor = distance;
  SonarSensor(trigPin2, echoPin2);
  LeftSensor = distance;
  SonarSensor(trigPin3, echoPin3);
  FrontSensor = distance;
  SonarSensor(trigPin4, echoPin4);
  BackSensor1 = distance;
  SonarSensor(trigPin5, echoPin5);
  BackSensor2 = distance;
  SonarSensor(trigPin6, echoPin6);
  BackSensor3 = distance;

  Serial.print(LeftSensor);
  Serial.print(" - ");
  Serial.print(FrontSensor);
  Serial.print(" - ");
  Serial.print(RightSensor);
  Serial.print(" - ");
  Serial.print(BackSensor1);
  Serial.print(" - ");
  Serial.print(BackSensor2);
  Serial.print(" - ");
  Serial.println(BackSensor3);
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

}
