#include <stdio.h>

#include "TI_Lib.h"
#include "tft.h"

/* Funktionendeklarationen */
void tftAusgabeZahl(int zahl);
void tftAusgabeZahlen(int* zahlen, int anzahlZahlen);

/**
  * @brief Ausgabe einer Zahl auf dem TFT-Bildschirm
	*/
void tftAusgabeZahl(int zahl)
{
	char outputString[12]; // int hat maximal 12 Stellen
	sprintf(outputString, "%d", zahl);
	TFT_puts(outputString);
}

/**
  * @brief Ausgabe mehrerer Zahlen auf dem TFT-Bildschirm
  */
void tftAusgabeZahlen(int* zahlen, int anzahlZahlen) // Uebergabe des Arrays funktioniert nicht
{
	for (int i = 0; i < anzahlZahlen; i++)
	{
		int zahl = zahlen[i];
		tftAusgabeZahl(zahl);
		TFT_putc(' ');
	}
}

//EOF
