#include <stdio.h>

#include "TI_Lib.h"
#include "tft.h"
#include "keypad.h"
#include "stack.h"

int add(void);
int sub(void);
int mul(void);
int div(void);

int add(){
        return pop() + pop();
}
 
int sub(){
        return pop() - pop();
}
 
int mul(){
        return pop() * pop();
}
 
int div(){
        return pop() / pop();
}

void berechne(char eingabe) // nach main verschieben
{
	if (('0' <= eingabe) && (eingabe <= '9'))
	{
		int eingabeZahl = eingabe - '0';
		push(eingabeZahl); //pop() * 10 + 
	}
	else
	{
		switch (eingabe)
		{
			case '+': push(add()); // nimmt zwei Werte vom Stack, addiert sie und legt das Ergebnis wieder auf dem Stack ab
								break;
			case '-': push(sub()); // nimmt zwei Werte vom Stack, subtrahiert den ersten (oberen) Wert vom zweiten und legt das Ergenis wieder auf dem Stack ab
								break;
			case '*': push(mul()); // nimmt zwei Werte vom Stack, multipliziert sie und legt das Ergebnis wieder auf dem Stack ab
								break;
			case '/': push(div()); // nimmt zwei Werte vom Stack, teilt den zweiten Wert durch den ersten (ganzzahlige Division) und legt das Ergebnis wieder auf dem Stack ab
								break;
			case 'p': TFT_putc(pop()); // gibt den obersten Wert des Stacks aus
								break;
			case 'f': // druckt den gesamten Stack aus
								break;
			case 'c': // löscht alle Einträge des Stacks
								break;
			case 'd': // dupliziert den obersten Eintrag
								break;
			case 'r': // vertauscht die Reihenfolge der beiden obersten Einträge des Stacks
								break;
			case ' ': // Zahl ist vorbei
								break;
		}
	}
	
//	if(0 == 0){} // debug
//	else if (eingabe == '+')
//	{
//		push(add());
//	}
//	else if (eingabe == '-')
//	{
//		push(sub());
//	}
//	else if (eingabe == '*')
//	{
//		push(mul());
//	}
//	else if (eingabe == '/')
//	{
//		push(div());
//	}
//	else if (eingabe == 'p')
//	{
//		push(div());
//	}
//	else if (eingabe == 'f')
//	{
//		push(div());
//	}
//	else if (eingabe == 'c')
//	{
//		push(div());
//	}
//	else if (eingabe == 'd')
//	{
//		push(div());
//	}
//	else if (eingabe == 'r')
//	{
//		push(div());
//	}
}
	
	
		
	
	