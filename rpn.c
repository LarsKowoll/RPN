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

void berechne(char eingabe)
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
	}
}
	
	
		
	
	