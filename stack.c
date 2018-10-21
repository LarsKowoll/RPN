#include <stdio.h>
#include <errno.h>
#include "TI_Lib.h"


#define MaxAnzahl 100

/* Variablendeklarationen */
int stackpointer = 0;
int stack[MaxAnzahl];

/* Funktionendeklarationen */
void push(int);
int pop(void);
void clearStack(void);
int getAnzahlEintraege(void);
int getObersterEintrag(void);
int* getAlleEintraege(void);
void vertauscheEintraege(void);
void dupliziereOberstenEintrag(void);

/**
  * @brief Legt Wert auf den Stack.
  */
void push(int i)
{
	if (stackpointer < MaxAnzahl)
	{
		stack[stackpointer++] = i;
	}
	else
	{
		// TFT_puts("Stack ist voll");
	}
}

/**
  * @brief Nimmt obersten Eintrag vom Stack.
  */
int pop(void)
{
	if (stackpointer > 0)
	{
		stackpointer--;
		int ausgabe = stack[stackpointer];
		stack[stackpointer] = 0;
		return ausgabe;
	}
	else
	{
		// TFT_puts("Stack ist leer");
		return 0;
	}
}

/**
  * @brief Löscht alle Einträge des Stacks.
  */
void clearStack()
{
	while (stackpointer > 0)
	{
		pop();
	}
}

/**
  * @brief Gibt die Anzahl der Eintraege auf dem Stack aus.
  */
int getAnzahlEintraege(void)
{
	return stackpointer;
}

/**
  * @brief Gibt den obersten Eintrag des Stacks aus.
  */
int getObersterEintrag(void)
{
	if (stackpointer > 0)
	{
		return stack[stackpointer - 1];
	}
	// todo: else
}

/**
  * @brief Gibt alle Eintraege des Stacks aus.
  */
int* getAlleEintraege(void)
{
	return stack;
}

/**
  * @brief Dupliziert den obersten Eintrag des Stacks.
  */
void dupliziereOberstenEintrag(void)
{
	int ersterEintrag = pop();
	push(ersterEintrag);
	push(ersterEintrag);
}

/**
  * @brief Vertauscht die beiden oberen Eintraege des Stacks.
  */
void vertauscheEintraege(void)
{
	int ersterEintrag = pop();
	int zweiterEintrag = pop();
	push(ersterEintrag);
	push(zweiterEintrag);
}
// EOF