#include"header.h"
union REGS in,out;
void mop(int &xp,int &yp,int &cl)
{
   in.x.ax=3;
   int86(51,&in,&out);
   cl=out.x.bx;
   xp=out.x.cx;
   yp=out.x.dx;
}
void main()
{
int g=DETECT,m,er,x,y,clk;
initgraph(&g,&m,"c:\\turboc3\\bgi"); //Change "path to BGI directory" as per your BGI location.
er=graphresult();
if(er!=grOk)
{
printf("Error in graphic driver");
getch();
exit(0);
}
in.x.ax=1;
int86(51,&in,&out);
while(clk!=4)
{
mop(x,y,clk);
gotoxy(12,12);
printf("%d %d %d",x,y,clk);
if(clk==1)
{
clrscr();
circle(x,y,100);
}
else if(clk==2)
setcolor(x-645);
}
getch();
closegraph();
}
