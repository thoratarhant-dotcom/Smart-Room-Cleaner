#define MOISTURE_PIN A0
#define MOISTURE_THRESHOLD 500

bool readMoistureSensor() {
  int raw = analogRead(MOISTURE_PIN);
  return (raw >= MOISTURE_THRESHOLD);
}
