#include <LiquidCrystal.h>
#include <Keypad.h>

// ==========================================
// 1. CONFIGURAÇÃO DE PINAGEM (HARDWARE)
// ==========================================
// Dica: Para ESP32, basta substituir os números abaixo pelos GPIOs correspondentes.

struct HardwarePins {
  // Pinos do Teclado Matricial
  struct {
    byte linhas[4];
    byte colunas[4];
  } keypad;

  // Pinos do Display LCD (RS, EN, D4, D5, D6, D7)
  struct {
    byte rs;
    byte en;
    byte d4;
    byte d5;
    byte d6;
    byte d7;
  } lcd;
};

// --- MAPA DE PINOS ATUAL (Arduino Uno / Nano) ---
HardwarePins pins = {
  .keypad = {
    .linhas  = { 7, 6, 5, 4 },
    .colunas = { A3, A2, A1, A0 } // Usando analógicos como digitais para poupar 0 e 1 (Serial)
  },
  .lcd = {
    .rs = 13,
    .en = 12,
    .d4 = 11,
    .d5 = 10,
    .d6 = 9,
    .d7 = 8
  }
};

/*
// --- EXEMPLO DE MAPA DE PINOS PARA ESP32 (Descomente ao migrar) ---
HardwarePins pins = {
  .keypad = {
    .linhas  = { 19, 18, 5, 17 },
    .colunas = { 16, 4, 0, 2 }
  },
  .lcd = {
    .rs = 13,
    .en = 12,
    .d4 = 14,
    .d5 = 27,
    .d6 = 26,
    .d7 = 25
  }
};
*/

// ==========================================
// 2. CONFIGURAÇÕES GERAIS
// ==========================================
const byte FILAS = 4;
const byte COLUNAS = 4;

char teclas[FILAS][COLUNAS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

// Inicialização dos periféricos com a struct
LiquidCrystal lcd(pins.lcd.rs, pins.lcd.en, pins.lcd.d4, pins.lcd.d5, pins.lcd.d6, pins.lcd.d7);

Keypad teclado = Keypad(
  makeKeymap(teclas),
  pins.keypad.linhas,
  pins.keypad.colunas,
  FILAS,
  COLUNAS
);

// ==========================================
// 3. EXECUÇÃO
// ==========================================
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("hello world!");
  
  lcd.setCursor(1, 1);
  lcd.print("Tecla: ");
}

void loop() {
  char tecla = teclado.getKey();

  if (tecla) {
    lcd.setCursor(8, 1);
    lcd.print(tecla);
  }
}