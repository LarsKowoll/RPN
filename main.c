
/**
  * @brief  Main program
  * @param  None
  */
#include <stdio.h>

#include "TI_Lib.h"
#include "tft.h"
#include "keypad.h"
#include "stack.h"
#include "input.h"
#include "rpn.h"
#include "main.h"

/* Funktionsdeklarationen */
int getDigit(char c, int* value);
int main(void);
void analysiereZeichen(char zeichen);

/**
  * @brief  Konvertiert das uebergebe Zeichen in einen Ganzzahlwert
  *
  * @param  c Das zu konvertierende Zeichen  *
  * @param  value Beinhaltet bei erfolgreicher Konvertierung die vom Zeichen dargestellte Zahl
  *
  * @return Fehlercode; 0 wenn Zeichen erfolgreich konvertiert werden konnte, ansonsten -1
  */
int getDigit(char c, int* value) {
  if (c < '0' || c > '9') {
    // Es handelt sich um keine Ziffer
    return -1;
  }

  // Berechnung des Versatzes zwischen dem Ziffern-Zeichen 'c' und des Null-Ziffern-Zeichens.
  *value = c - '0';
  return 0;
}

/**
  * @brief  Main program;
  *         Liest wiederholt ein Zeichen vom TFT-Touch-KeyPad ein.
  *         Handelte es sich um eine Ziffer, dann wird diese zu einer 
  *         laufenden Summe addiert und ausgegeben.
  */
int main(void) {
  // Initialisierung
  Init_TI_Board();  
  Make_Touch_Pad();  
  char zeichen = 0;
	
	while(1) // super loop
	{
		zeichen = zeichenEinlesen();
		analysiereZeichen(zeichen);
	}
}

void analysiereZeichen(char zeichen)
{
	static int zahl;
	char outputString[12];
	
	switch(zeichen)
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': zahl = zifferHinzufuegen(zahl, zeichen);
							break;
		case ' ': push(zahl); // Zahl ist vorbei
							zahl = 0;
							TFT_cls();
							break;
		case '+':
		case '-':
		case '*':
		case '/': berechne(zeichen);
							break;
		case 'p': sprintf(outputString, "%d", pop());
							TFT_cls();
							TFT_puts(outputString);
							break;
		case 'f': // druckt den gesamten Stack aus
								break;
		case 'c': // löscht alle Einträge des Stacks
								break;
		case 'd': // dupliziert den obersten Eintrag
								break;
		case 'r': // vertauscht die Reihenfolge der beiden obersten Einträge des Stacks
								break;
	}	
}
 
// EOF
// EOF
