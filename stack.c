#include <stdio.h>

#include "TI_Lib.h"
#include "tft.h"
#include "keypad.h"

#define MaxAnzahl 100

void push(int);
int pop(void);

int stackpointer = 0;
int stack[MaxAnzahl];

void push(int i)
{
	if (stackpointer < MaxAnzahl)
	{
		stack[stackpointer++] = i;
	}
	
	else
	{
		TFT_puts("Stack ist voll");
	}
}

int pop(void)
{
	if (stackpointer > 0)
	{
		
		return stack[stackpointer--];
	}
	
	else
	{
		TFT_puts("Stack ist leer");
		return -1;
	}
}
// EOF