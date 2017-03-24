#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
union REGS in,out;
int top1=-1;int top2=-1;int top3=-1;
int *s1,*s2,*s3;
int x1=110;int x2=310; int x3=510;
int y1=400;int y2=400;int y3=400;
int callmouse();
void mouseposi(int &xpos,int &ypos, int &click);
void push1(int);
void push2(int);
void push3(int);
int pop1();
int pop2();
int pop3();
void createdisk(int,int,int);
void hanoi(int,char,char,char);

int callmouse()
{
in.x.ax=1;
int86(51,&in,&out);
return 1;
}

void mouseposi(int &xpos,int &ypos,int &click)
{
click=0;
while(click!=1)
{
in.x.ax=3;
int86(51,&in,&out);
click=out.x.bx;
xpos=out.x.cx;
ypos=out.x.dx;
}
}
int main()
{ int n,i,x,y,click;
printf("ENTER THE NUMBER OF DISKS - ");
scanf("%d",&n);
s1=(int *)malloc(n*sizeof(int));
s2=(int *)malloc(n*sizeof(int));
s3=(int *)malloc(n*sizeof(int));
clrscr();
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"c:\\TurboC3\\BGI");
setcolor(YELLOW);
rectangle(150,150,250,250);
setcolor(RED);
rectangle(350,150,450,250);
setcolor(YELLOW);
outtextxy(170,200,"COMPUTER");
setcolor(RED);
outtextxy(370,200,"MANUAL");
setcolor(WHITE);
callmouse();
mouseposi(x,y,click);
if(x>150 && x<250 && y>150 && y<250)
{
cleardevice();
setcolor(RED);
rectangle(100,400,120,200);
setcolor(BROWN);
rectangle(300,400,320,200);
setcolor(GREEN);
rectangle(500,400,520,200);
for(i=0;i<n;i++)
{
push1(n-i);
}
hanoi(n,'a','c','b');
//cleardevice();

}
else if(x>350 && x<450 && y>150 && y<250)
{
cleardevice();
setcolor(RED);
rectangle(100,400,120,200);
setcolor(BROWN);
rectangle(300,400,320,200);
setcolor(GREEN);
rectangle(500,400,520,200);
for(i=0;i<n;i++)
push1(n-i);
int po=0;
while (po==0)
{
int j,k,l,m;

callmouse();
mouseposi(j,k,l);
if(j>100 && j<120 && k<400 && k>200)
{
m=pop1();
int p,q,r;
callmouse();
delay(400);
mouseposi(p,q,r);
if(p>300 && p<320 && q<400 && q>200)
{
if(top2==-1 || m<s2[top2])
push2(m);
else
push1(m);
}
else if(p>500 && p<520 && q<400 && q>200)
{ if(top3==-1 || m<s3[top3])
push3(m);
else
push1(m);
}
else
push1(m);
}
else if(j>300&& j<320 && k<400 && k>200)
{  int p,q,r;
m=pop2();
callmouse();
delay(400);
mouseposi(p,q,r);
if(p>100 && p<120 && q<400 && q>200)
{ if(top1==-1 || m<s1[top1])
push1(m);
else
push2(m);
}
else if(p>500 && p<520 && q<400 && q>200)
{ if(top3==-1 || m<s3[top3])
push3(m);
else
push2(m);
}
else
push2(m);
}
else if(j>500 && j<520 && k<400 && k>200)
{ int p,q,r;
m=pop3();
callmouse();
delay(400);
mouseposi(p,q,r);
if(p>100 && p<120 && q<400 && q>200)
{ if(top1==-1 || m<s1[top1])
push1(m);
else
push3(m);
}
else if(p>300 && p<320 && q<400 && q>200)
{
if(top2==-1 || m<s2[top2])
push2(m);
else
push3(m);
}
else
push3(m);
}
if(top3==n-1)
po=1;
else
po=0;
}

}
getch();
closegraph();
return 0;
}
int style=4;
void createdisk(int n,int x,int y)
{
setfillstyle(4,1);
bar(x-n*15,y,x+n*15,y-10);
}

void push1(int n)
{
top1=top1+1;
s1[top1]=n;
delay(1500);
createdisk(n,x1,y1);

delay(1500);
y1=y1-10;
}

void push2(int n)
{
top2=top2+1;
s2[top2]=n;
delay(1500);
createdisk(n,x2,y2);
delay(1500);
y2=y2-10;
}

void push3(int n)
{
top3=top3+1;
s3[top3]=n;
delay(1500);
createdisk(n,x3,y3);
delay(1500);
y3=y3-10;
}


int pop1()
{ int i;
int data=s1[top1];
top1=top1-1;
cleardevice();
setcolor(RED);
rectangle(100,400,120,200);
setcolor(BROWN);
rectangle(300,400,320,200);
setcolor(GREEN);
rectangle(500,400,520,200);
y1=400; y2=400;
y3=400;
for(i=0;i<=top1;i++)
{
setfillstyle(4,1);
bar(x1-s1[i]*15,y1,x1+s1[i]*15,y1-10);
y1=y1-10;
}
for(i=0;i<=top2;i++)
{
setfillstyle(4,1);
bar(x2-s2[i]*15,y2,x2+s2[i]*15,y2-10);
y2=y2-10;
}
for(i=0;i<=top3;i++)
{
setfillstyle(4,1);
bar(x3-s3[i]*15,y3,x3+s3[i]*15,y3-10);
y3=y3-10;
}
return data;
}

int pop2()
{
int i;
int data=s2[top2];
top2=top2-1;
cleardevice();
setcolor(RED);
rectangle(100,400,120,200);
setcolor(BROWN);
rectangle(300,400,320,200);
setcolor(GREEN);
rectangle(500,400,520,200);
y1=400; y2=400;
y3=400;
for(i=0;i<=top1;i++)
{
setfillstyle(4,1);
bar(x1-s1[i]*15,y1,x1+s1[i]*15,y1-10);
y1=y1-10;
}
for(i=0;i<=top2;i++)
{
setfillstyle(4,1);
bar(x2-s2[i]*15,y2,x2+s2[i]*15,y2-10);
y2=y2-10;
}
for(i=0;i<=top3;i++)
{
setfillstyle(4,1);
bar(x3-s3[i]*15,y3,x3+s3[i]*15,y3-10);
y3=y3-10;
}
return data;
}

int pop3()
{ int i;
int data=s3[top3];
top3=top3-1;
cleardevice();
setcolor(RED);
rectangle(100,400,120,200);
setcolor(BROWN);
rectangle(300,400,320,200);
setcolor(GREEN);
rectangle(500,400,520,200);
y1=400; y2=400;
y3=400;
for(i=0;i<=top1;i++)
{
setfillstyle(4,1);
bar(x1-s1[i]*15,y1,x1+s1[i]*15,y1-10);
y1=y1-10;
}
for(i=0;i<=top2;i++)
{
setfillstyle(4,1);
bar(x2-s2[i]*15,y2,x2+s2[i]*15,y2-10);
y2=y2-10;
}
for(i=0;i<=top3;i++)
{

setfillstyle(4,1);

bar(x3-s3[i]*15,y3,x3+s3[i]*15,y3-10);
y3=y3-10;
}
return data;
}
void hanoi(int n,char f,char t,char a)
{
int data;
if(n==1)
{
if(f=='a')
{ data=pop1();
if(t=='b')
push2(data);
else
push3(data);
}
else if(f=='b')
{
data=pop2();
if(t=='a')
push1(data);
else
push3(data);
}
else if(f=='c')
{
data=pop3();
if(t=='a')
push1(data);
else
push2(data);
}
return;
}
hanoi(n-1,f,a,t);
if(f=='a')
{
data=pop1();
if(t=='b')
push2(data);
else
push3(data);
}
else if(f=='b')
{
data=pop2();
if(t=='a')
push1(data);
else
push3(data);
}
else if(f=='c')
{
data=pop3();
if(t=='a')
push1(data);
else
push2(data);
}

hanoi(n-1,a,t,f);
}
