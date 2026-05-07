#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int ldrPin = 7;
int led1 = 2;
int led2 = 3;

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void loop() {
  int state = digitalRead(ldrPin);
  display.clearDisplay();
  display.setCursor(0, 20);

  if (state == HIGH) {
    // Dark environment - turn LEDs ON
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    display.println("LED ON");
  } else {
    // Bright environment - turn LEDs OFF
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    display.println("LED OFF");
  }

  display.display();
  delay(300);
}
