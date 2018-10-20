#include <stdio.h>

#include "TI_Lib.h"
#include "tft.h"
#include "keypad.h"

/* Variablendeklarationen */

/* Funktionsdeklarationen */
char zeichenEinlesen();

int zifferHinzufuegen(int zahl, char eingabe);


char zeichenEinlesen(){
	char touchInput = Get_Touch_Pad_Input();	
	return touchInput;
}

int zifferHinzufuegen(int zahl, char eingabe) // eventuell über pop()
{
	int eingabeZahl = eingabe - '0';
	zahl = zahl * 10 + eingabeZahl; // hinzuzufuegende Ziffer wird an die Zahl rangehaengt
	
	// Ausgabe der Zahl auf dem TFT (für debug)
	char outputString[12];
	sprintf(outputString, "%d", zahl);
	TFT_cls();
	TFT_puts(outputString);
	
	return zahl;
}
