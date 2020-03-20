
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
float duration;

void SonarSetup(){
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
}

float getSonarDistance(int trigPin,int echoPin){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    return (duration/2) / 29.1; // Calculating and returning distance.
}

/**
 * Getter methods for each sonar sensor
 */

float getRightSensorDistance(){
    return getSonarDistance(trigPin1,echoPin1);
}

float getLeftSensorDistance(){
    return getSonarDistance(trigPin2,echoPin2);
}

float getFrontSensorDistance(){
    return getSonarDistance(trigPin3,echoPin3);
}

float getBackSensor1Distance(){
    return getSonarDistance(trigPin4,echoPin4);
}

float getBackSensor2Distance(){
    return getSonarDistance(trigPin5,echoPin5);
}

float getBackSensor3Distance(){
    return getSonarDistance(trigPin6,echoPin6);
}
