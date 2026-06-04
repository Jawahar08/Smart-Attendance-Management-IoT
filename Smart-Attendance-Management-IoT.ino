#include <WiFi.h>
#include <HTTPClient.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 5
#define RST_PIN 4

#define LED_PIN 26
#define BUZZER 25

bool useLED = false;
bool useBuzzer = false;

MFRC522 mfrc522(SS_PIN, RST_PIN);
const char* ssid = "cheta laptop";
const char* password = "cheta@005";
String serverName = "https://script.google.com/macros/s/AKfycbywR9ag0mnVQwTGu0hYdIKRkualu7-aNTP0-oo_aX3RnrlATxGtFeC3OOS8s6GXISkAgA/exec";
String validUID = "DF 72 A8 16";

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  SPI.begin();
  mfrc522.PCD_Init();

  WiFi.begin(ssid, password);
  Serial.print("Connecting WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");
  Serial.println("Scan RFID card...");
}


void beep() {
  if (!useBuzzer) return;

  digitalWrite(BUZZER, HIGH);
  delay(200);
  digitalWrite(BUZZER, LOW);
}

void sendToGoogle(String name, String status) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String url = serverName + "?name=" + name + "&status=" + status;
    http.begin(url);
    http.GET();
    http.end();
  }
}

void loop() {

  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  String uid = "";
 for (byte i = 0; i < mfrc522.uid.size; i++) {
  if (mfrc522.uid.uidByte[i] < 0x10) uid += "0"; 
  uid += String(mfrc522.uid.uidByte[i], HEX);
  if (i != mfrc522.uid.size - 1) uid += " ";
}

  uid.toUpperCase();

  Serial.print("UID: ");
  Serial.println(uid);

  beep(); 
if (uid == validUID) {
  Serial.println("Access Granted");

  if (useLED) digitalWrite(LED_PIN, HIGH);

  sendToGoogle("23BEC7275", "Present");

  delay(3000);

  if (useLED) digitalWrite(LED_PIN, LOW);
}

  delay(2000);
  mfrc522.PICC_HaltA();
}