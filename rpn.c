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
	if ('0' <= eingabe && eingabe <= '9')
	{
		int eingabeZahl = eingabe - '0';
		push(eingabeZahl); //pop() * 10 + 
	}
	else if (eingabe == '+')
	{
		push(add());
	}
	else if (eingabe == '-')
	{
		push(sub());
	}
	else if (eingabe == '*')
	{
		push(mul());
	}
	else if (eingabe == '/')
	{
		push(div());
	}
	else if (eingabe == 'p')
	{
		push(div());
	}
	else if (eingabe == 'f')
	{
		push(div());
	}
	else if (eingabe == 'c')
	{
		push(div());
	}
	else if (eingabe == 'd')
	{
		push(div());
	}
	else if (eingabe == 'r')
	{
		push(div());
	}
}
	
	
		
	
	