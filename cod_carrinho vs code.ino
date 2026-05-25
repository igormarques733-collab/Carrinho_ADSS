#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// Motor A
int IN1 = 18;
int IN2 = 19;

// Motor B
int IN3 = 25;
int IN4 = 26;

char comando;

void setup() {
  
  Serial.begin(115200);

  // Nome do Bluetooth
  SerialBT.begin("ESP32_ROBOT");

  // Define os pinos como saída
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  parar();

  Serial.println("Bluetooth iniciado");
}

void loop() {

  if (SerialBT.available()) {

    comando = SerialBT.read();

    Serial.print("Comando: ");
    Serial.println(comando);

    // FRENTE
    if (comando == 'F') {
      frente();
    }

    // TRÁS
    else if (comando == 'B') {
      tras();
    }

    // DIREITA
    else if (comando == 'R') {
      direita();
    }

    // ESQUERDA
    else if (comando == 'L') {
      esquerda();
    }

    // PARAR
    else if (comando == 'S') {
      parar();
    }
  }
}

// ======================
// FUNÇÕES DOS MOVIMENTOS
// ======================

void frente() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void tras() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void direita() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void esquerda() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void parar() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}