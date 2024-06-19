#include <LiquidCrystal.h>
int tempPin = 0;
int buttonApin = 6;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(buttonApin, INPUT_PULLUP);
}
void loop()
{
  int tempReading = analogRead(tempPin);
  // This is OK
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
  float tempC = tempK - 273.15;            // Convert Kelvin to Celcius
  float tempF = (tempC * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
  if (digitalRead(buttonApin) == LOW) {
    lcd.setCursor(0, 0);
    lcd.print("Temp         F  ");
    lcd.setCursor(6, 0);
    lcd.print(tempF); // Display Temperature in F
    Serial.println("temperature in fahrenheit");
    Serial.println(tempF); //print to serial monitor
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print("Temp         C  ");
    lcd.setCursor(6, 0);
    lcd.print(tempC); // Display Temperature in C
    Serial.println("temperature in celcius");
    Serial.println(tempC); //print to serial monitor
  }
  delay(500);
}