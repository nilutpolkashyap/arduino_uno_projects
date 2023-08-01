// Constants
#define COUNTS_PER_REVOLUTION 1000  // Replace with the actual counts per revolution of your encoder
#define WHEEL_RADIUS 3.5           // Replace with the actual radius of your robot's wheels in cm
#define WHEEL_CIRCUMFERENCE (2 * PI * WHEEL_RADIUS)
#define DISTANCE_BETWEEN_WHEELS 10.0  // Replace with the actual distance between your robot's wheels in cm

// Motor pins (adjust these to match your setup)
const int leftMotorEncoderPin = 2;
const int rightMotorEncoderPin = 3;

// Variables
volatile long leftEncoderCount = 0;
volatile long rightEncoderCount = 0;
float leftDistance = 0.0;
float rightDistance = 0.0;
float totalDistance = 0.0;

// Robot position variables
float x = 0.0;      // X position in cm
float y = 0.0;      // Y position in cm
float theta = 0.0;  // Orientation in radians

void setup() {
  // Set encoder pins as inputs
  pinMode(leftMotorEncoderPin, INPUT);
  pinMode(rightMotorEncoderPin, INPUT);
  
  // Attach interrupts to encoder pins
  attachInterrupt(digitalPinToInterrupt(leftMotorEncoderPin), leftEncoderISR, RISING);
  attachInterrupt(digitalPinToInterrupt(rightMotorEncoderPin), rightEncoderISR, RISING);
  
  Serial.begin(9600);
}

void loop() {
  // Calculate distance based on encoder counts
  leftDistance = (float)leftEncoderCount * (WHEEL_CIRCUMFERENCE / COUNTS_PER_REVOLUTION);
  rightDistance = (float)rightEncoderCount * (WHEEL_CIRCUMFERENCE / COUNTS_PER_REVOLUTION);
  totalDistance = (leftDistance + rightDistance) / 2.0; // Average of left and right distances
  
  // Reset encoder counts for the next iteration
  leftEncoderCount = 0;
  rightEncoderCount = 0;

  // Update the robot's position using Dead Reckoning
  float dTheta = (rightDistance - leftDistance) / DISTANCE_BETWEEN_WHEELS;
  float dX = totalDistance * cos(theta + (dTheta / 2.0));
  float dY = totalDistance * sin(theta + (dTheta / 2.0));
  
  x += dX;
  y += dY;
  theta += dTheta;

  // Normalize theta to the range [0, 2*PI]
  theta = fmod(theta, 2 * PI);

  // Print the calculated position
  Serial.print("X: ");
  Serial.print(x);
  Serial.print(" cm, Y: ");
  Serial.print(y);
  Serial.print(" cm, Theta: ");
  Serial.print(theta * (180.0 / PI));  // Convert theta to degrees for better readability
  Serial.println(" degrees");
  
  delay(1000); // Adjust the delay as needed to control how frequently the position is updated
}

// Interrupt service routines for encoder counts
void leftEncoderISR() {
  leftEncoderCount++;
}

void rightEncoderISR() {
  rightEncoderCount++;
}
