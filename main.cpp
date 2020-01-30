#include "sudoku.h"
 void main()
{
/*
int arr[9][9]={
{8,0,0,0,0,0,0,0,0},
{0,0,3,6,0,0,0,0,0},
{0,7,0,0,9,0,2,0,0},
{0,5,0,0,0,7,0,0,0},
{0,0,0,0,4,5,7,0,0},               //hardest puzzle according to wikipedia
{0,0,0,1,0,0,0,3,0},
{0,0,1,0,0,0,0,6,8},
{0,0,8,5,0,0,0,1,0},
{0,9,0,0,0,0,4,0,0}
};*/

register int arr[9][9]={
{5,3,0,0,7,0,0,0,0},
{6,0,0,1,9,5,0,0,0},
{0,9,8,0,0,0,0,6,0},
{8,0,0,0,6,0,0,0,3},
{4,0,0,8,0,3,0,0,1},                //this is a sample puzzle..change your question here
{7,0,0,0,2,0,0,0,6},
{0,6,0,0,0,0,2,8,0},
{0,0,0,4,1,9,0,0,5},
{0,0,0,0,8,0,0,7,9}
};

register int copy[9][9],adj[9][9],loc=0,row=0,col=0;
static int value;
bool forward=1;
int *p,*q,*r;
p=&arr[0][0];   //the problem
q=&copy[0][0];  //the copied array
r=&adj[0][0];   //adjency array
setarray(p,r);  //to set adjency array
copi(q,p);      //to set copied array
#define SEE clrscr();display(&arr[0][0]);//;cout<<"\n\n\n\n\n\n";display(&copy[0][0]);
/*
while(!check(p)&&getch())
{
   clrscr();
   copi(p,q);
   fill(p,q);
   display(p);
}
*/

do
   {

      label:
      //SEE
      if(*r!=0)//if position is not fixed
      {

      for(value=1;value<=10;value++)//try values in range from 1 to 10
      {

         if(value>*p)//value must be more than one already existing ..zero initially
         {
            if (checkcell(&arr[0][0],row,col,value)&&value<=9 ) //check if value is legal
            {


               *p=value;
               *q=value;
               p++;
               q++;
               r++;
               loc++;
               SEE
               //display(&arr[0][0]);
               UPDATEI
               forward=1;
               goto label;
            }
            else
            {

               if(value>9) //if no value fits in the set the current value as zero and go back to previous cell
               {

               *p=0;
               //*q=0;
               p--;
               q--;
               r--;
               loc--;
               //SEE
               forward=0;
               //display(&arr[0][0]);
               UPDATED
               goto label;
               }

            }
         }

         else  //if the value does not fit in any iteration then try with a value previously used in copied array
         {static int temp=*q;
            if(checkcell(&arr[0][0],row,col,temp)&&temp<=9 &&temp>*p)
            {


               *p=temp;
               *q=temp;
               p++;
               q++;
               r++;
               loc++;
               SEE
               //display(&arr[0][0]);
               UPDATEI
               forward=1;
               goto label;
            }
            else
            {}
         }

      }

      }
      else //if cell is fixed then ignore and move forward or backwards
      {
      if(forward)
      {
         p++;
         q++;
         r++;
         loc++;
         //SEE
         UPDATEI
      }
      else
      {
         p--;
         q--;
         r--;
         loc--;
         //SEE
         UPDATED
      }
      }
      //cout<<endl<<value;

   }
while(loc<81);
getch();
}





















void display(int *p)
{
   for(int i=0;i<9;i++)
   {
      NAV
      cout<<endl<<'|';
      for (int j=0;j<9;j++)
      {
         cout<<" "<<*p<<" |";
         p++;

      }
      END
      if(*p==0)
         {
         	break;
         }

   }
   NAV
   for (int i=0;i<10;i++)
   {END}
}
void copi(int*a, int*b)
{
  for(int i=0;i<81;i++)
  {
      *a=*b;
      a++;
      b++;
  }
}
/*
bool checkcell(int row,int col ,int value,int *base)
{  //value is random number
   //current is current value in memory location
   //loc is number of cell
   //returns 0 if numbers match
   //currow is the value of the cell in columns to be checked
   //curcol is the value of the cell in row to be checked
   static int loc=(row*10+col)-row,locrow,loccol;
   static int *current,*currow,*curcol;
   current=base+loc;

   for (int i=0;i<9;i++)
      {
         locrow=(i*10+col)-i;
         loccol=(row*10+i)-row;
         currow=base+locrow;
         curcol=base+loccol;
         if(value==*current || value==*currow || value==*curcol)//check
         {
               return 0;
         }
      }
  return 1;
}
*/
bool checkcell(int *p,int row,int col,int value)
{
   static int arr[9][9];
   for (int i=0;i<9;i++)
   {
       for (int j=0;j<9;j++)
       {
         arr[i][j]=*p;
         p++;
         //SEE

         //cout<<"row is"<<row<<" col is"<<col;
       }
   }



   if(row<3 && col<3)
      {
         //matrix1
         for(int x=0;x<3;x++)
         {
            for(int y=0;y<3;y++)
            {
               if(arr[x][y]==value)
               {
                  return 0;
               }
            }
         }
      }
   if(row<3 && col>=3 && col<6)
      {
         //matrix2
         for(int x=0;x<3;x++)
         {
            for(int y=3;y<6;y++)
            {
               if(arr[x][y]==value)
               {
                  return 0;
               }
            }
         }
      }
   if(row<3 && col>=6 && col<9)
      {
         //matrix3
         for(int x=0;x<3;x++)
         {
            for(int y=6;y<9;y++)
            {
               if(arr[x][y]==value)
               {
                  return 0;
               }
            }
         }
      }

   if(row>=3&&row<6&&col<3)
      {
         for(int x=3;x<6;x++)
         {
            for(int y=0;y<3;y++)
            {
               if(arr[x][y]==value)
               {
                  return 0;
               }
            }
         }
         //matrix4
      }
   if(row>=3&&row<6&&col>=3&&col<6)
      {
         //matrix5
         for(int x=3;x<6;x++)
         {
            for(int y=3;y<6;y++)
            {
               if(arr[x][y]==value)
               {
                  return 0;
               }
            }
         }
      }
   if(row>=3&&row<6&&col>=6&&col<9)
      {  
         //matrix6
         for(int x=3;x<6;x++)
         {
            for(int y=6;y<9;y++)
            {
               if(arr[x][y]==value)
               {
                  return 0;
               }
            }
         }
      }

   if(row>=6&&row<9&&col<3)
      {  
         //matrix7
         for(int x=6;x<9;x++)
         {
            for(int y=0;y<3;y++)
            {
               if(arr[x][y]==value)
               {
                  return 0;
               }
            }
         }
      }

   if(row>=6&&row<9&&col>=3&&col<6)
      {
         //matrix8
         for(int x=6;x<9;x++)
         {
            for(int y=3;y<6;y++)
            {
               if(arr[x][y]==value)
               {
                  return 0;
               }
            }
         }
      }
   if(row>=6&&row<9&&col>=6&&col<9)
      {
         //matrix9
         for(int x=6;x<9;x++)
         {
            for(int y=6;y<9;y++)
            {
               if(arr[x][y]==value)
               {
                  return 0;
               }
            }
         }
      }

 for(int x=0;x<9;x++)
   {
      if((arr[row][x]==value  )||( arr[x][col]==value))
      {
         return 0;
      }
   }



   return 1;
}






void setarray(int *p,int *r)
{
   for (int i =0;i<81;i++)
      {
         if (*p!=0)
         {
            *r=0;
         }
         else
         {
            *r=1;
         }

         p++;
         r++;
      }

}

