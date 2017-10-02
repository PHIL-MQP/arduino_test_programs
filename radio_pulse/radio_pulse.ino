const unsigned int TX = 11;
const unsigned int RX = 10;

void setup() {
  Serial.begin(9600);
  pinMode(TX, OUTPUT);
  pinMode(RX, INPUT_PULLUP);
}

unsigned long t = millis();
bool receiving = false;
bool sending = false;
const int pause_ms = 100;
const int pulse_width = 10;
unsigned long x = millis();

void loop() {
  if (!sending && millis() - t > pause_ms) {
    digitalWrite(TX, HIGH);
    sending = true;
  }
  else if (millis() - t > pause_ms + pulse_width) {
    t = millis();
    sending = false;
    digitalWrite(TX, LOW);
  }
}
