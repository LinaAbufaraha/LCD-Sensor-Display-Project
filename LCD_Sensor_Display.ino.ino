#include <LiquidCrystal.h>
#include <DHT.h>

// ==== LCD Setup ====
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// ==== Pins ====
#define DHTPIN A0         // DHT11 connected to A3
#define DHTTYPE DHT11     // We're using DHT11
#define LDR_PIN A1        // LDR connected to A1

DHT dht(DHTPIN, DHTTYPE);

// ==== 2x2 Thermometer Icon ====
byte thermoTopLeft[] = {
  B00100,
  B01110,
  B01110,
  B01110,
  B01110,
  B01110,
  B01110,
  B01110
};

byte thermoTopRight[] = {
  B00000,
  B00000,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte thermoBottomLeft[] = {
  B01110,
  B11111,
  B11111,
  B01110,
  B00100,
  B00100,
  B00100,
  B00100
};

byte thermoBottomRight[] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00000,
  B00000,
  B00000,
  B00000
};

// ==== 2x2 Light Bulb Icon ====
byte bulbTopLeft[] = {
  B00000,
  B00000,
  B00011,
  B00100,
  B01000,
  B10000,
  B10000,
  B10000
};

byte bulbTopRight[] = {
  B00000,
  B00000,
  B11000,
  B00100,
  B11010,
  B00101,
  B00101,
  B00001
};

byte bulbBottomLeft[] = {
  B10000,
  B10000,
  B01000,
  B00100,
  B00010,
  B00011,
  B00010,
  B00011
};

byte bulbBottomRight[] = {
  B00001,
  B00001,
  B00010,
  B00100,
  B01000,
  B11000,
  B01000,
  B11000
};

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  dht.begin();

  // Create all 8 custom characters
  lcd.createChar(0, thermoTopLeft);
  lcd.createChar(1, thermoTopRight);
  lcd.createChar(2, thermoBottomLeft);
  lcd.createChar(3, thermoBottomRight);
  lcd.createChar(4, bulbTopLeft);
  lcd.createChar(5, bulbTopRight);
  lcd.createChar(6, bulbBottomLeft);
  lcd.createChar(7, bulbBottomRight);

  lcd.clear();
}

void loop() {
  // === Read Temperature ===
  float temperature = dht.readTemperature();

  lcd.clear();

  // Draw Thermometer
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.setCursor(0, 1);
  lcd.write(byte(2));
  lcd.write(byte(3));

  // Print temperature
  lcd.setCursor(3, 0);
  lcd.print("Temp:");
  lcd.setCursor(3, 1);
  if (isnan(temperature)) {
    lcd.print("Error");
    Serial.println("Failed to read from DHT sensor!");
  } else {
    lcd.print(temperature, 1);
    lcd.print(" C");

    Serial.print("Temperature: ");
    Serial.print(temperature, 1);
    Serial.println(" C");
  }

  delay(2000);

  // === Read Light ===
  int lightValue = analogRead(LDR_PIN);
  float lightPercent = (lightValue / 1023.0) * 100.0;

  lcd.clear();

  // Draw Light Bulb
  lcd.setCursor(0, 0);
  lcd.write(byte(4));
  lcd.write(byte(5));
  lcd.setCursor(0, 1);
  lcd.write(byte(6));
  lcd.write(byte(7));

  // Print Light Value
  lcd.setCursor(3, 0);
  lcd.print("Light:");
  lcd.setCursor(3, 1);
  lcd.print(lightValue); // optionally add %
  lcd.print(" (");
  lcd.print(lightPercent, 0);
  lcd.print("%)");

  Serial.print("Light Level: ");
  Serial.print(lightValue);
  Serial.print(" (");
  Serial.print(lightPercent, 1);
  Serial.println("%)");

  delay(2000);
}
