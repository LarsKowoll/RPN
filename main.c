
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
  char sum = 0;
	
while(1)
{
	sum = einlesen();
	berechne(sum);
}
		
	


 
}
// EOF
// EOF
