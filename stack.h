#ifndef STACK_H
#define	STACK_H

#ifdef	__cplusplus
extern "C" {
#endif
	
void push(int i);
int pop(void);
void clearStack(void);
int getAnzahlEintraege(void);
int getObersterEintrag(void);
int* getAlleEintraege(void);
void vertauscheEintraege(void);
void dupliziereOberstenEintrag(void);



#ifdef	__cplusplus
}
#endif

#endif	/* STACK_H */
