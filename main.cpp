#include <SPI.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN);

struct SensorData {
  float temperature;
  float pressure1;
  float pressure2;
  float altitude1;
  float altitude2;
  float ax;
  float ay;
  float az;
  float gx;
  float gy;
  float gz;
  float latitude1;
  float longitude1;
  float latitude2;
  float longitude2;
};

void setup() {
  Serial.begin(9600);

  radio.begin();
  radio.setPALevel(RF24_PA_HIGH);
  radio.openReadingPipe(1, 0xF0F0F0F0E1LL);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    SensorData data;
    radio.read(&data, sizeof(data));

    Serial.print("Temperatura: ");
    Serial.println(data.temperature);
    Serial.print("Presión 1: ");
    Serial.println(data.pressure1);
    Serial.print("Presión 2: ");
    Serial.println(data.pressure2);
    Serial.print("Altitud 1: ");
    Serial.println(data.altitude1);
    Serial.print("Altitud 2: ");
    Serial.println(data.altitude2);
    Serial.print("ax: ");
    Serial.println(data.ax);
    Serial.print("ay: ");
    Serial.println(data.ay);
    Serial.print("az: ");
    Serial.println(data.az);
    Serial.print("gx: ");
    Serial.println(data.gx);
    Serial.print("gy: ");
    Serial.println(data.gy);
    Serial.print("gz: ");
    Serial.println(data.gz);
    Serial.print("Latitud 1: ");
    Serial.println(data.latitude1);
    Serial.print("Longitud 1: ");
    Serial.println(data.longitude1);
    Serial.print("Latitud 2: ");
    Serial.println(data.latitude2);
    Serial.print("Longitud 2: ");
    Serial.println(data.longitude2);
  }
}