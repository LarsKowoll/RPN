#include <stdio.h>
#include <errno.h>
#include "TI_Lib.h"
#include "keypad.h"
#include "tft.h"

/* Funktionsdeklarationen */
char zeichenEinlesen();
int zifferHinzufuegen(int zahl, char eingabe);
char *strerror(int error_nr);

/**
  * @brief Liest Zeichen vom Touchpad ein.
  */
char zeichenEinlesen(){
	char touchInput = Get_Touch_Pad_Input();	
	return touchInput;
}

/**
  * @brief Fügt einer Zahl eine weitere Ziffer hinzu.
	*        Beispiel:
	*      	 int i = 2; char c = '3';
	*      	 int j = zifferHinzufuegen(i, c); -> j = 23
  */
int zifferHinzufuegen(int zahl, char eingabe) // eventuell über pop()
{
	int eingabeZahl = eingabe - '0';
	int tempZahl = zahl;
	zahl = zahl * 10 + eingabeZahl; // hinzuzufuegende Ziffer wird an die Zahl rangehaengt
	if (tempZahl > zahl){
		
		return -1;
		fprintf(stderr, "%s\n", strerror(errno));
		
	}
	else {	
	return zahl;
	}
}
