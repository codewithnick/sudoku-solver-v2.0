#include "stdio.h"
#include "conio.h"
#include "iostream.h"
#include "stdlib.h"
#define NAV cout<<"+---+---+---+---+---+---+---+---+---+";
#define END cout<<endl;
#define UPDATEI if(col<8){col++;}else{row++;col=0;}
#define UPDATED if(col>0){col--;}else{row--;col=8;}

//#define STOP if(getch()){break;}
void display(int *p);
//bool check(int *p); //incomplete
//void fill(int *p,int *q);//remove this
void copi(int *a, int *b);
//bool checkcell(int row,int col ,int value,int *base);
bool checkcell(int *p,int row,int col,int value);//returns 0 if a number matches
void setarray(int *p,int *r);


//BUG ..CHECKCELL IS NOT WORKING
//RECURSION IS WORKING
//BUG..CHECK FOR COPY AND ADJ
//BUG TERMINATED WHILE LOOP TOO SOON AFTER MAX CONVERSION :/
