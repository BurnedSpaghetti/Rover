/**
 * Turn Control Functions
 */

// Measurments in inches
const float velocity = 100; //still in reserch as to what vel is best for paint
const float swingRadius = 25;
const float distanceBetweenWheels = 15;
const float axleToPaintNozzleDsitance;

//float velocityInner = velocity *(1 - (distanceBetweenWheels / (2 * swingRadius)));
//float velocityOuter = velocity *(1 + (distanceBetweenWheels / (2 * swingRadius)));

// Velocity for the inner wheel of turning curve
float getVelocityForInner(){
  return velocity *(1 - (distanceBetweenWheels / (2 * swingRadius)));
}

// Velocity for the outer wheel of turning curve
float getVelocityForOuter(){
  return velocity *(1 + (distanceBetweenWheels / (2 * swingRadius)));
}


void turnToHeading(float heading, Adafruit_StepperMotor motorInner, int motorOuter){
  String turnDirection;
  int rotationDistance = (int)(heading - getCurrentHeading() + 540) % 360 - 180; // constants are temp, put according Compass resolution later
    
  // Also put conditon to no not overstep paint
  
  if(rotationDistance > 0){ 
     turnDirection = "BACKWARD";
  }
  else{
    turnDirection = "FORWARD";
  }

  Serial.print("From heading ");
  Serial.print(getCurrentHeading());
  Serial.print(" to -> ");
  Serial.print(heading);
  Serial.println(" turning " + turnDirection + "s");

  while(getCurrentHeading() != heading){
    // set motor speeds
    
  }
  
}
