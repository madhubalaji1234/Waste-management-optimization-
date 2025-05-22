#define TRIG_PIN 9
#define ECHO_PIN 10
#define GREEN_LED 3
#define YELLOW_LED 4
#define RED_LED 5
#define BUZZER_PIN 6

void setup() {
  Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
      pinMode(ECHO_PIN, INPUT);
        pinMode(GREEN_LED, OUTPUT);
          pinMode(YELLOW_LED, OUTPUT);
            pinMode(RED_LED, OUTPUT);
              pinMode(BUZZER_PIN, OUTPUT);
              }

              long readUltrasonicDistance() {
                digitalWrite(TRIG_PIN, LOW);
                  delayMicroseconds(2);
                    digitalWrite(TRIG_PIN, HIGH);
                      delayMicroseconds(10);
                        digitalWrite(TRIG_PIN, LOW);
                          return pulseIn(ECHO_PIN, HIGH) * 0.034 / 2;  // Calculate distance in cm
                          }

                          void loop() {
                            long distance = readUltrasonicDistance();
                              Serial.print("Distance: ");
                                Serial.println(distance);

                                  // Check waste levels and control LEDs/buzzer
                                    if (distance < 10) { // Full bin
                                        digitalWrite(RED_LED, HIGH);
                                            digitalWrite(YELLOW_LED, LOW);
                                                digitalWrite(GREEN_LED, LOW);
                                                    digitalWrite(BUZZER_PIN, HIGH); // Turn on buzzer
                                                      } else if (distance >= 10 && distance < 20) { // Half-full bin
                                                          digitalWrite(RED_LED, LOW);
                                                              digitalWrite(YELLOW_LED, HIGH);
                                                                  digitalWrite(GREEN_LED, LOW);
                                                                      digitalWrite(BUZZER_PIN, LOW); // Turn off buzzer
                                                                        } else { // Empty bin
                                                                            digitalWrite(RED_LED, LOW);
                                                                                digitalWrite(YELLOW_LED, LOW);
                                                                                    digitalWrite(GREEN_LED, HIGH);
                                                                                        digitalWrite(BUZZER_PIN, LOW); // Turn off buzzer
                                                                                          }

                                                                                            delay(1000); // Check every second
                                                                                            }
