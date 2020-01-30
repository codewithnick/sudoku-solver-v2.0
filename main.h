#include "stdio.h"
#include "conio.h"
#include "iostream.h"
#include "stdlib.h"
#define NAV cout<<"+---+---+---+---+---+---+---+---+---+";
#define END cout<<endl;
#define UPDATEI if(col<8){col++;}else{row++;col=0;}
#define UPDATED if(col>0){col--;}else{row--;col=8;}
#define SEE clrscr();display(&arr[0][0]);cout<<endl<<loc;