#include <Arduino.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>

const int dhtPin = 2;
const int dhtType = DHT11;

DHT dht(dhtPin, dhtType);
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte degree[8] = {
    0B01110,
    0B01010,
    0B01110,
    0B00000,
    0B00000,
    0B00000,
    0B00000,
    0B00000};

void setup()
{
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.print("Tempe...: ");
  lcd.setCursor(0, 1);
  lcd.print("Humid...: ");
  lcd.createChar(1, degree);
  dht.begin();
}

void loop()
{
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();

  lcd.setCursor(9, 0);
  lcd.print(round(temp));
  lcd.print(" ");
  lcd.write(1);
  lcd.print("C");

  lcd.setCursor(9, 1);
  lcd.print(round(humid));
  lcd.print(" %");
}
