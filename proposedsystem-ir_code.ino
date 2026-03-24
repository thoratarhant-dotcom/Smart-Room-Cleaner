#define IR_PIN 2
#define VACUUM_RELAY A1

bool readIRSensor() {
  int raw = digitalRead(IR_PIN);
  return (raw == LOW);
}

void controlVacuum(bool activate) {
  digitalWrite(VACUUM_RELAY, activate ? HIGH : LOW);
}
