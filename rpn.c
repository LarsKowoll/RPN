#include <stdio.h>
#include <errno.h>
#include "TI_Lib.h"
#include "stack.h"
#include "tft.h"

//http://www.virtsync.com/c-error-codes-include-errno

/* Funktionendeklarationen */
int add(void);
int sub(void);
int mul(void);
int div(void);
char *strerror(int error_nr);

/** @brief Nimmt zwei Werte vom Stack, addiert sie und legt
  *        das Ergebnis wieder auf dem Stack ab.
	* @return -1, wenn nur ein Wert auf dem Stack liegt und die
	*             Addition somit nicht möglich ist;
	*         0 sonst.
  */
int add(void)
{
  if (getAnzahlEintraege() >= 2)
	{
		int summand2 = pop();
		int summand1 = pop();
		int summe = summand1+ summand2;
/**
* Prüfung auf Overflow, wenn zwei postive Zahlen addiert werden kann das Ergebnis nicht negativ sein.
*/		
			if (summand2 > 0 && summand1 > 0) {
				if (summe < 0) {
					fprintf(stderr, "%s\n", strerror(34));
					return -1;
				}
			}
/**
* Prüfung auf Overflow, wenn zwei negative Zahlen addiert werden kann das Ergebnis nicht positiv sein.
*/					
			if (summand2 < 0 && summand1 < 0) {
				if (summe > 0) {
					fprintf(stderr, "%s\n", strerror(34));
					return -1;
				}
			}
		push(summe);
		return 0;
	}
	else
	{
		fprintf(stderr, "%s\n", strerror(34));
		return -1;
	}
}

/**
  * @brief Nimmt zwei Werte vom Stack, subtrahiert den ersten (oberen) Wert
  *        vom zweiten und legt das Ergebnis wieder auf dem Stack ab.
	* @return -1, wenn nur ein Wert auf dem Stack liegt und die
	*             Subtraktion somit nicht möglich ist;
	*         0 sonst.
  */
int sub(void)
{
	if (getAnzahlEintraege() >= 2)
	{
		int subtrahend = pop();
		int minuend = pop();
		int differenz = minuend - subtrahend;

/**
* Prüfung auf Overflow, wenn eine postive Zahl von einer negativen Zahl subrtahiert wird kann das Ergebnis nicht negativ sein
*/		
		if (minuend > 0 && subtrahend < 0) {
				if (differenz < 0) {
					fprintf(stderr, "%s\n", strerror(34));
					return -1;
				}
			}
/**
* Prüfung auf Overflow, wenn eine negative Zahl von einer postiven Zahl subrtahiert wird kann das Ergebnis nicht positiv sein
*/					
			if (minuend < 0 && subtrahend > 0) {
				if (differenz > 0) {
					fprintf(stderr, "%s\n", strerror(34));
					return -1;
				}
			}
		push(differenz);
		return 0;
	}
	else
	{
		return -1;
	}
}

/**
  * @brief Nimmt zwei Werte vom Stack, multipliziert sie
  *        und legt das Ergebnis wieder auf dem Stack ab.
	* @return -1, wenn nur ein Wert auf dem Stack liegt und die
	*             Multiplikation somit nicht möglich ist;
	*         0 sonst.
  */
int mul(void)
{
	if (getAnzahlEintraege() >= 2)
	{
		int faktor2 = pop();
		int faktor1 = pop();
		int produkt = faktor1 * faktor2;
		
		/**
* Prüfung auf Overflow. Bei Multiplikation mit zwei negativen Zahlen oder zwei postiven Zahlen muss das Ergebnis positiv sein. (Ausnahme 0)
*/		
		if ((faktor1 > 0 && faktor2 > 0) || (faktor1 < 0 && faktor2 < 0)) {
				if (produkt < 0) {
					fprintf(stderr, "%s\n", strerror(34));
					return -1;
				}
				else if (produkt > 0) {
					if ((produkt < faktor1) || (produkt < faktor2)){ //Das Produkt muss größer sein, als die einzelene Faktoren (Ausnahme 0)
					fprintf(stderr, "%s\n", strerror(34));
					return -1;
				}
			}
		}
/**
* Prüfung auf Overflow. Bei Multiplikation mit einer negativen und positiven Zahl muss das Ergbnis negativ sein.
*/					
		if ((faktor1 < 0 && faktor2 > 0) || (faktor1 < 0 && faktor2 > 0)) {
				if (produkt > 0) {
					fprintf(stderr, "%s\n", strerror(errno));
					return -1;
				}
				else if (produkt < 0) {
					if ((produkt > faktor1) || (produkt > faktor2)){ //Das Produkt muss kleiner sein, als die einzelene Faktoren (Ausnahme 0)
					fprintf(stderr, "%s\n", strerror(34));
					return -1;
				}
			}
		}
		push(produkt);
		return 0;
		
	}
	else
	{
		return -1;
	}
}


/**
  * @brief Nimmt zwei Werte vom Stack, teilt den zweiten Wert
	*        durch den ersten (ganzzahlige Division) und legt
  *        das Ergebnis wieder auf dem Stack ab
	* @return -1, wenn nur ein Wert auf dem Stack liegt und die
	*             Division somit nicht möglich ist oder, wenn
  *             versucht wurde, durch 0 zu teilen;
	*         0 sonst.
  */
int div(void){
	if (getAnzahlEintraege() >= 2) // zwei verschiedene if-Bedingungen, damit der Fehlerfall noch konkretisiert werden kann
	{
		if (getObersterEintrag() != 0)
		{
			int divisor = pop();
			int dividend = pop();
			int quotient = dividend / divisor;
			push(quotient);
			return 0;
		}	
	}
	return -1;
}
