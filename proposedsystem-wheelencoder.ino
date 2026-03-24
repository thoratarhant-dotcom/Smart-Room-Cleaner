#define WHEEL_RADIUS_CM 3.25
#define WHEELBASE_CM 14.0
#define PPR 20

volatile long leftPulses = 0;
volatile long rightPulses = 0;
long lastLeftPulses = 0;
long lastRightPulses = 0;

float posX = 0.0;
float posY = 0.0;
float theta = 0.0;

void updateOdometry() {
  noInterrupts();
  long curL = leftPulses;
  long curR = rightPulses;
  interrupts();

  long dNL = curL - lastLeftPulses;
  long dNR = curR - lastRightPulses;
  lastLeftPulses = curL;
  lastRightPulses = curR;

  if (dNL==0 && dNR==0) return;

  float dSL = WHEEL_RADIUS_CM * (2.0 * PI * dNL / PPR);
  float dSR = WHEEL_RADIUS_CM * (2.0 * PI * dNR / PPR);

  float dS = (dSR + dSL) / 2.0;
  float dTheta = (dSR - dSL) / WHEELBASE_CM;

  posX += dS * cos(theta + dTheta / 2.0);
  posY += dS * sin(theta + dTheta / 2.0);
  theta += dTheta;
}
