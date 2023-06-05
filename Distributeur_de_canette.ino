// ***************************************************
//  Programme : Distributeur_de_canette.ino
//  Auteur : Abdellah Ajaji 6ème A Electronique INRACI
//  Hardware : Arduino Uno + Nextion + Lsc230 + TCRT5000
//  Date : 2022-2023
//  Sips 6
// ***************************************************
// ******************** LIBRAIRIES *******************
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#include <Servo.h>
//*********** DEFINITION DES CONSTANTES **************
#define NEOPIXEL_PIN  8
#define LED   13   // initialisation des pattes
#define BP_A  9
#define BP_B  6
#define BP_C  5
#define SERVOMOTEUR 11
#define S0 6
#define S1 7
#define S2 8
#define S3 9
#define sensorOut 10
#define RX_PIN 0
#define TX_PIN 1
#define BAUDRATE 9600
#define pinIRD  8
#define pinIRd  A0
#define pinIRa  A0
#define pinLED  9
bool colorFind = false;
//******* DEFINITION DES VARIABLES GLOBALES **********
int frequencyRed = 0;
int frequencyGreen = 0;
int frequencyBlue = 0;
int IRvalueA = 0;
int IRvalueD = 0;
int pos = 0;
int ledRed = A0;
int ledYellow = A1;
int ledBlue = A2;
//************ DEFINITION DES OBJETS *****************
SoftwareSerial nexSerial(RX_PIN, TX_PIN);
Servo myservo;
//****************************************************
//*************** INITIALISATION *********************
//****************************************************
void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(pinIRd, INPUT);
  pinMode(pinIRa, INPUT);
  pinMode(pinLED, OUTPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  myservo.attach(9);
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  nexSerial.begin(BAUDRATE);
  Serial.begin(9600);
}

//****************************************************
//*************** BOUCLE INFINIE *********************
//****************************************************
void loop() {
  IRvalueA = analogRead(pinIRa);
  IRvalueD = digitalRead(pinIRd);
  Serial.print("Analog Reading=");
  Serial.print(IRvalueA);
  Serial.print("\t Digital Reading=");
  Serial.println(IRvalueD);
  getFrequency();

  if (!colorFind) {
    checkColor();
  }
  if (( IRvalueA < 100)) {
    Serial.print("ju");
  }
  delay(100);
}

void getFrequency() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequencyRed = pulseIn(sensorOut, LOW);
  Serial.print("Rouge = ");
  Serial.print(frequencyRed);
  Serial.print("  ");


  delay(100);
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequencyGreen = pulseIn(sensorOut, LOW);
  Serial.print("Verte= ");
  Serial.print(frequencyGreen);
  Serial.print("  ");


  delay(100);
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequencyBlue = pulseIn(sensorOut, LOW);
  Serial.print("Bleu= ");
  Serial.print(frequencyBlue);
  Serial.println("  ");
  delay(100);
}
void checkColor() {
  if ((frequencyRed < 70 && frequencyRed > 95)
      && (frequencyGreen < 240 && frequencyGreen > 265)
      && (frequencyBlue < 200 && frequencyBlue > 220)) {
    colorFind = true;
    Serial.print("rouge----------------------------------------------------");

  } else if ((frequencyRed < 45 && frequencyRed > 25)
             && (frequencyGreen < 60 && frequencyGreen > 40)
             && (frequencyBlue < 85 && frequencyBlue > 65)) {
    colorFind = true;
    Serial.print("jaune ");
  } else if ((frequencyRed < 90 && frequencyRed > 70)
             && (frequencyGreen < 95 && frequencyGreen > 75)
             && (frequencyBlue < 60 && frequencyBlue > 40)) {
    colorFind = true;
    Serial.print("bleu");
  }
}




/*void checkColor() {

  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequencyRed = pulseIn(sensorOut, LOW);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequencyGreen = pulseIn(sensorOut, LOW);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequencyBlue = recherchebleu();

  if ((frequencyRed < 45 && frequencyRed > 25)
      && (frequencyGreen < 105 && frequencyGreen > 85)
      && (frequencyBlue < 75 && frequencyBlue > 55)) {
    digitalWrite(ledRed, HIGH);
    colorFind = true;
    Serial.print("rouge= ");

  }

  if ((frequencyRed < 45 && frequencyRed > 25)
      && (frequencyGreen < 60 && frequencyGreen > 40)
      && (frequencyBlue < 85 && frequencyBlue > 65)) {
    digitalWrite(ledYellow, HIGH);
    colorFind = true;
    Serial.print("vert= ");
  }
  if ((frequencyRed < 90 && frequencyRed > 70)
      && (frequencyGreen < 95 && frequencyGreen > 75)
      && (frequencyBlue < 60 && frequencyBlue > 40)) {
    digitalWrite(ledBlue, HIGH);
    colorFind = true;
    Serial.print("bleu=");
  }
  }
  int rechercherouge(void) {
  frequencyRed = pulseIn(sensorOut, LOW);
  return frequencyRed;
  }
  int recherchevert(void) {
  frequencyGreen = pulseIn(sensorOut, LOW);
  return frequencyGreen;
  }
  int recherchebleu(void) {
  frequencyBlue = pulseIn(sensorOut, LOW);
  return frequencyBlue;
  }*/
/*void getFrequency() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequencyRed = pulseIn(sensorOut, LOW);
  Serial.print("Rouge = ");
  Serial.print(frequencyRed);
  Serial.print("  ");


  delay(100);
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequencyGreen = pulseIn(sensorOut, LOW);
  Serial.print("Verte= ");
  Serial.print(frequencyGreen);
  Serial.print("  ");


  delay(100);
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequencyBlue = pulseIn(sensorOut, LOW);
  Serial.print("Bleu= ");
  Serial.print(frequencyBlue);
  Serial.println("  ");
  delay(100);
  }
*/
