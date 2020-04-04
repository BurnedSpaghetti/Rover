/**
 * Turn Control Functions
 */

// Measurments in inches, not fully finalized yet
const float velocity = 10; //Temporary, still in reserch as to what vel is best, maybe will use RPMs 
const float swingRadius = 9.8;
const float distanceBetweenWheels = 7.1;
const float axleMiddleToPaintNozzleDsitance;


// Velocity for the inner wheel of turning curve
float getVelocityForInner(){
  return velocity *(1 - (distanceBetweenWheels / (2 * swingRadius)));
}

// Velocity for the outer wheel of turning curve
float getVelocityForOuter(){
  return velocity *(1 + (distanceBetweenWheels / (2 * swingRadius)));
}


void turnToHeading(float heading, int motorInner, int motorOuter){
  int turnDirection;
  // Calculating shortest semicicle of rotation distance 
  int rotationDistance = (int)(heading - getCurrentHeading() + 540) % 360 - 180; // constants are temp, put according Compass resolution later
    
  // Also put conditon to not run over paint
  if(rotationDistance > 0){ 
     turnDirection = -1; // Backward
  }
  else{
    turnDirection = 1; // Forward
  }

  Serial.print("Turning from heading ");
  Serial.print(getCurrentHeading());
  Serial.print(" to -> ");
  Serial.println(heading);

  m[motorInner] -> setSpeed(getVelocityForInner());
  m[motorOuter] -> setSpeed(getVelocityForOuter());
  
  Serial.print("Inner motor speed: ");
  Serial.println(getVelocityForInner());
  Serial.print("Outer motor speed: ");
  Serial.println(getVelocityForOuter());
  
  while(getCurrentHeading() != heading){
    onestep(motorInner, turnDirection);
    onestep(motorOuter, turnDirection);
  }
  
}
