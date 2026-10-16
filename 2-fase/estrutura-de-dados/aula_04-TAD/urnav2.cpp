
#include <LiquidCrystal.h>
#include <Keypad.h>

const byte FILAS = 4;
const byte COLUNAS = 4;

const char teclas[FILAS][COLUNAS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
 struct tecladoPinos {
  byte fila[FILAS];
  byte coluna[COLUNAS];
} 

tecladoPinos pinoskeyPad = {
  fila : {7, 6, 5, 4},
  coluna : {3, 2, 1, 0}
 }


LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

Keypad teclado = Keypad(
  makeKeymap(teclas),
  pinoskeyPad.fila,
  pinoskeyPad.coluna,
  FILAS,
  COLUNAS
);

void setup()
{
  lcd.begin(16, 2); // Set up the number of columns and rows on the LCD.
	lcd.setCursor(2, 0);
  // Print a message to the LCD.
  lcd.print("hello world!");

}

void loop()
{
  	lcd.setCursor(1, 1);

char tecla = teclado.getKey();

  if (tecla)
  {
    lcd.print(tecla);
  }
}