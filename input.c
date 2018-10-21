#include <stdio.h>
#include <errno.h>
#include "TI_Lib.h"
#include "keypad.h"

/* Funktionsdeklarationen */
char zeichenEinlesen();
int zifferHinzufuegen(int zahl, char eingabe);

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
<<<<<<< HEAD
	int tempZahl = zahl;
	zahl = zahl * 10 + eingabeZahl; // hinzuzufuegende Ziffer wird an die Zahl rangehaengt
	if (tempZahl > zahl){
		return -1;
	}
	else {	
	return zahl;
	}
=======
	zahl = zahl * 10 + eingabeZahl; // hinzuzufuegende Ziffer wird an die Zahl rangehaengt
	return zahl;
>>>>>>> dcdc507d3a97b47713538f1499f79ce4b50eb97f
}
