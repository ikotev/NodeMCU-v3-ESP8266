//#include <Wire.h>
//#include <SPI.h>
//#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)
#define BME280_ADDRESS (0x76)

Adafruit_BME280 bme;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	Serial.println("BME280 test");	

	Wire.begin(0, 2); // D3, D4
	Wire.setClock(100000);

	if (!bme.begin(BME280_ADDRESS)) {
		Serial.println("Could not find a valid BME280 sensor, check wiring!");
		while (1);
	}	
}

// the loop function runs over and over again until power down or reset
void loop() {
	printValues();
	delay(10000);
}

void printValues() {
	Serial.print("Temperature = ");
	Serial.print(bme.readTemperature());
	Serial.println(" *C");

	Serial.print("Pressure = ");

	Serial.print(bme.readPressure() / 100.0F);
	Serial.println(" hPa");

	Serial.print("Approx. Altitude = ");
	Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
	Serial.println(" m");

	Serial.print("Humidity = ");
	Serial.print(bme.readHumidity());
	Serial.println(" %");

	Serial.println();
}