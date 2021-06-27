#include <BLEDevice.h>
//#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLEService.h>
#include <BLECharacteristic.h>
#include <BLEAdvertising.h>

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
//#include <ESP32Ping.h>

void setup() {
  // Initialize the BLE environment
  
BLEDevice::init("ServerNameVisible");// Create the server

BLEServer* pServer = BLEDevice::createServer();


// Create the service
BLEService* pService = pServer->createService(SERVICE_UUID);
// Create the characteristic
BLECharacteristic* pCharacteristic =
 pService->createCharacteristic(CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);
// Set the characteristic value
pCharacteristic->setValue("Hello world");
// Start the service
pService->start();

BLEAdvertising *pAdvertising = pServer->getAdvertising();
pAdvertising->start();

  Serial.begin(9600);
  delay(1000);
  Serial.println("\n");
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  delay(1000);
  Serial.println("ble client ok");

}
