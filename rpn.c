#include <stdio.h>

#include "TI_Lib.h"
#include "stack.h"

/* Funktionendeklarationen */
int add(void);
int sub(void);
int mul(void);
int div(void);

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
		int summe = pop() + pop();
		push(summe);
		return 0;
	}
	else
	{
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
		int produkt = pop() * pop();
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
int div(void)
{
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
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
}
