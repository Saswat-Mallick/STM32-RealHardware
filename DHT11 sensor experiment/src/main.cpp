#include <Arduino.h>
#include <DHT.h>

#define DHTPIN PA2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
HardwareSerial mySerial(PA10, PA9); // RX, TX

void setup() {
  mySerial.begin(9600);
  delay(2000);
  dht.begin();
  mySerial.println("DHT11 Test Starting...");
}

void loop() {
  delay(2000); // DHT11 needs ~2 sec between readings

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    mySerial.println("Failed to read from DHT11!");
    return;
  }

  mySerial.print("Temperature: ");
  mySerial.print(temperature);
  mySerial.print(" C  |  Humidity: ");
  mySerial.print(humidity);
  mySerial.println(" %");
}