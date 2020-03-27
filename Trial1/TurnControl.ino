/**
 * Turn Control Functions
 */

// Measurments in inches
const float velocity = 100;
const float swingRadius = 25;
const float distanceBetweenWheels = 15;
const float axleToPaintNozzleDsitance;

//float velocityInner = velocity *(1 - (distanceBetweenWheels / (2 * swingRadius)));
//float velocityOuter = velocity *(1 + (distanceBetweenWheels / (2 * swingRadius)));

float getVelocityInner(){
  return velocity *(1 - (distanceBetweenWheels / (2 * swingRadius)));
}

float getVelocityOuter(){
  return velocity *(1 + (distanceBetweenWheels / (2 * swingRadius)));
}



// add correction distance to travel
