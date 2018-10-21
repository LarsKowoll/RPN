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
#include "output.h"
#include "rpn.h"

/* Funktionsdeklarationen */
int main(void);
void analysiereZeichen(char zeichen);

/**
  * @brief  Main program;
  *         Liest wiederholt ein Zeichen vom TFT-Touch-KeyPad ein.
  */
int main(void) {
  // Initialisierung
  Init_TI_Board();  
  Make_Touch_Pad();
	
  char zeichen;
	
	while(1) // super loop
	{
		zeichen = zeichenEinlesen();
		analysiereZeichen(zeichen);
	}
}

/**
  * @brief Analysiert das eingelesene Zeichen.
  */
void analysiereZeichen(char zeichen)
{
	// static int zahl;
	static char letzteEingabe;
	
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
		case '9': /* Wenn die letzte Eingabe eine Zahl war, wird die Ziffer zur Zahl
			        hinzugefügt und dann auf den Stack gelegt. */
							if ((letzteEingabe >= '0') && (letzteEingabe <= '9'))
							{
								int zahl = zifferHinzufuegen(pop(), zeichen);
								push(zahl);
							}
							else
							{
								push(zeichen - '0');
							}
							break;
		case ' ': 
							break;
		case '+': add();
							break;
		case '-': sub();
							break;
		case '*': mul();
							break;
		case '/': div();
							break;
		case 'p': // druckt den obersten Wert des Stacks aus
							TFT_cls();
							tftAusgabeZahl(getObersterEintrag());
							break;
		case 'f': // druckt den gesamten Stack aus
							TFT_cls();
							tftAusgabeZahlen(getAlleEintraege(), getAnzahlEintraege());
							break;
		case 'c': // löscht alle Einträge des Stacks
							clearStack();
							break;
		case 'd': // dupliziert den obersten Eintrag
							dupliziereOberstenEintrag();
							break;
		case 'r': // vertauscht die Reihenfolge der beiden oberen Einträge des Stacks
							vertauscheEintraege();
							break;	
	}
	
	letzteEingabe = zeichen;
}
 
// EOF
