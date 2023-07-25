#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<process.h>
float g2=0,g3=0;
int g1=0;
void box()
{
for(g1=0;g1<10;g1++)
{
 if(g1==0 || g1==3 ||g1==6||g1==9)
 {
 setcolor(14);
 line(215,100+g2,430,100+g2); //horizontal
 line(215+g3,100,215+g3,392); //vertical
 line(215,100+g2+1,430,100+g2+1); //horizontal
 line(215+g3+1,100,215+g3+1,392); //vertical
 setcolor(15);
 }
 else
 {
 line(215,100+g2,430,100+g2); //horizontal
 line(215+g3,100,215+g3,392); //vertical
 }
 g2=g2+32.44;
 g3=g3+23.88;
}
}
void main()
{
int gdriver=DETECT,gmode=DETECT;
initgraph(&gdriver,&gmode,"C://TURBOC3//BGI");
cleardevice();
box();
g1=0;
g2=g3=0;
char ch=0;
int a[9][9];int k[10][9][9];
float g2=0,g3=0;
int f=0;int n1=0,n2=0;int w=0;int e=0,test=-
2,test2=0,p=0,sum=0,u=0,q1=0,q2=0,l=0,u1=1,h=0,o1=0,o2=0,j1=0,j2=0;
//*****************INITIALISATION***********************
for(int z=0;z<10;z++)
{
 for(int q=0;q<9;q++)
 {
 for(int y=0;y<9;y++)
 {
 k[z][q][y]=1;
 a[q][y]=0;
 }
 }
}
gotoxy(26,2);
cout<<"**Hey,Welcome to SUDOKU SOLVER**";
gotoxy(21,4);
cout<<"Please,Put your question to the given boxex.";
gotoxy(25,5);
cout<<"Note:At the place of empty press 0.";
//*****************INPUT********************************
for(int i=0;i<9;i++)
{
 for(int j=0;j<9;j++)
 {
 gotoxy(29+n1,8+n2);
 cin>>a[i][j];
 n1=n1+3;
 if(a[i][j]==11) //condition for removing from the compilation
 exit(0);
 }
 n2=n2+2;n1=0;
}
n1=n2=0;
cleardevice();
//*************************************************
for(int c=1;c<10;c++) //solving the problem
{
//*******************CHECKING**********************
for(int l=0;l<9;l++)
{
 for(int m=0;m<9;m++)
 {
 if(a[l][m]==0)
 {
 for(int h=0;h<9;h++) //CONDITION OF RAW CHECKING
 { if(a[l][h]==c)
k[c][l][m]=0;
 }
 for(int d=0;d<9;d++) //CONDITION OF COULUMN CHECKING
 { if(a[d][m]==c)
k[c][l][m]=0;
 }
 if(l<=2 && m<=2) //CHECKING OF 1st BLOCK
 {
 for(w=0;w<=2;w++)
 {
 for(e=0;e<=2;e++)
 {
if(a[w][e]==c)
k[c][l][m]=0;
 }
 }
 }
 if(l<=2 && (m>=3 && m<=5)) //CHECKING OF 2nd BLOCK
 {
 for(w=0;w<=2;w++)
 {
 for(e=3;e<=5;e++)
 {
if(a[w][e]==c)
k[c][l][m]=0;
 }
 }
 }
 if(l<=2 && (m>=6 && m<=8)) //CHECKING OF 3rd BLOCK
 {
 for(w=0;w<=2;w++)
 {
 for(e=6;e<=8;e++)
 {
if(a[w][e]==c)
k[c][l][m]=0;
 }
 }
 }
 if((l>=3 && l<=5) && m<=2) //CHECKING OF 4th BLOCK
 {
 for(w=3;w<=5;w++)
 {
 for(e=0;e<=2;e++)
 {
if(a[w][e]==c)
k[c][l][m]=0;
 }
 }
 }
 if((l>=3 && l<=5) && (m>=3 && m<=5)) //CHECKING OF 5th BLOCK
 {
 for(w=3;w<=5;w++)
 {
 for(e=3;e<=5;e++)
 {
if(a[w][e]==c)
k[c][l][m]=0;
 }
 }
 }
 if((l>=3 && l<=5) && (m>=6 && m<=8)) //CHECKING OF 6th BLOCK
 {
 for(w=3;w<=5;w++)
 {
 for(e=6;e<=8;e++)
 {
if(a[w][e]==c)
k[c][l][m]=0;
 }
 }
 }
 if((l>=6 && l<=8) && m<=2) //CHECKING OF 7th BLOCK
 {
 for(w=6;w<=8;w++)
 {
 for(e=0;e<=2;e++)
 {
if(a[w][e]==c)
k[c][l][m]=0;
 }
 }
 }
 if((l>=6 && l<=8) && (m>=3 && m<=5)) //CHECKING OF 8th BLOCK
 {
 for(w=6;w<=8;w++)
 {
 for(e=3;e<=5;e++)
 {
if(a[w][e]==c)
k[c][l][m]=0;
 }
 }
 }
 if((l>=6 && l<=8) && (m>=6 && m<=8)) //CHECKING OF 9th BLOCK
 {
 for(w=6;w<=8;w++)
 {
 for(e=6;e<=8;e++)
 {
if(a[w][e]==c)
k[c][l][m]=0;
 }
 }
 }
 }
 else
 k[c][l][m]=0;
 }
}
//*********************************************
for(int c1=0;c1<9;c1++)
{
 for(int c2=0;c2<9;c2++)
 {
 if(k[c][c1][c2]==1)
 {
 for(int v1=0;v1<9;v1++) //CONDITION OF RAW CHECKING
 { if(k[c][c1][v1]==1)
test++;
 }
 for(int v2=0;v2<9;v2++) //CONDITION OF COULUMN CHECKING
 { if(k[c][v2][c2]==1)
test++;
 }
 if(c1<=2 && c2<=2) //CHECKING OF 1st BLOCK
 {
 for(w=0;w<=2;w++)
 {
 for(e=0;e<=2;e++)
 {
if(k[c][w][e]==1)
test++;
 }
 }
 }
 if(c1<=2 && (c2>=3 && c2<=5)) //CHECKING OF 2nd BLOCK
 {
 for(w=0;w<=2;w++)
 {
 for(e=3;e<=5;e++)
 {
if(k[c][w][e]==1)
test++;
 }
 }
 }
 if(c1<=2 && (c2>=6 && c2<=8)) //CHECKING OF 3rd BLOCK
 {
 for(w=0;w<=2;w++)
 {
 for(e=6;e<=8;e++)
 {
if(k[c][w][e]==1)
test++;
 }
 }
 }
 if((c1>=3 && c1<=5) && c2<=2) //CHECKING OF 4th BLOCK
 {
 for(w=3;w<=5;w++)
 {
 for(e=0;e<=2;e++)
 {
if(k[c][w][e]==1)
test++;
 }
 }
 }
 if((c1>=3 && c1<=5) && (c2>=3 && c2<=5)) //CHECKING OF 5th BLOCK
 {
 for(w=3;w<=5;w++)
 {
 for(e=3;e<=5;e++)
 {
if(k[c][w][e]==1)
test++;
 }
 }
 }
 if((c1>=3 && c1<=5) && (c2>=6 && c2<=8)) //CHECKING OF 6th BLOCK
 {
 for(w=3;w<=5;w++)
 {
 for(e=6;e<=8;e++)
 {
if(k[c][w][e]==1)
test++;
 }
 }
 }
 if((c1>=6 && c1<=8) && c2<=2) //CHECKING OF 7th BLOCK
 {
 for(w=6;w<=8;w++)
 {
 for(e=0;e<=2;e++)
 {
if(k[c][w][e]==1)
test++;
 }
 }
 }
 if((c1>=6 && c1<=8) && (c2>=3 && c2<=5)) //CHECKING OF 8th BLOCK
 {
 for(w=6;w<=8;w++)
 {
 for(e=3;e<=5;e++)
 {
if(k[c][w][e]==1)
test++;
 }
 }
 }
 if((c1>=6 && c1<=8) && (c2>=6 && c2<=8)) //CHECKING OF 9th BLOCK
 {
 for(w=6;w<=8;w++)
 {
 for(e=6;e<=8;e++)
 {
if(k[c][w][e]==1)
test++;
 }
 }
 }
 if(test<=1)
 a[c1][c2]=c;
 test=-2;
 }
 }
}
//********************************************************
for(q1=0;q1<9;q1++) //row checking only for one empty
{
 for(q2=0;q2<9;q2++)
 { //there is problem in sum variable
 sum=sum+a[q1][q2]; //focus on sum
 if(a[q1][q2]==0) //sum of block will be in the end of the loop
 { //think about test2++ or ++test2
 test2++;
 p=q2;
 }
 }
 if(test2==1)
 {
 u=45-sum;
 a[q1][p]=u;
 }
 u=0;
 p=0;
 sum=0;
 test2=0;
 o1=0;
 o2=0;
 j1=0;
 j2=0;
}
for(q2=0;q2<9;q2++) //column checking only for one empty
{
 for(q1=0;q1<9;q1++)
 {
 sum=sum+a[q1][q2];
 if(a[q1][q2]==0)
 {
 test2++;
 p=q1;
 }
 }
 if(test2==1)
 {
 u=45-sum;
 a[p][q2]=u;
 }
 u=0;
 p=0;
 sum=0;
 test2=0;
}
for(q1=0;q1<=2;q1++) //1st block checking only for one empty
{
 for(q2=0;q2<=2;q2++)
 {
 sum=sum+a[q1][q2];
 if(a[q1][q2]==0)
 {
 test2++;
 l=q1;
 p=q2;
 }
 }
}
if(test2==1)
 {
 u=45-sum;
 a[l][p]=u;
 }
 u=0;
 l=0;
 p=0;
 sum=0;
 test2=0;
for(q1=0;q1<=2;q1++) //2nd block checking only for one empty
{
 for(q2=3;q2<=5;q2++)
 {
 sum=sum+a[q1][q2];
 if(a[q1][q2]==0)
 {
 test2++;
 l=q1;
 p=q2;
 }
 }
}
if(test2==1)
 {
 u=45-sum;
 a[l][p]=u;
 }
 u=0;
 l=0;
 p=0;
 sum=0;
 test2=0;
for(q1=0;q1<=2;q1++) //3rd block checking only for one empty
{
 for(q2=6;q2<=8;q2++)
 {
 sum=sum+a[q1][q2];
 if(a[q1][q2]==0)
 {
 test2++;
 l=q1;
 p=q2;
 }
 }
}
if(test2==1)
 {
 u=45-sum;
 a[l][p]=u;
 }
 u=0;
 l=0;
 p=0;
 sum=0;
 test2=0;
for(q1=3;q1<=5;q1++) //4th block checking only for one empty
{
 for(q2=0;q2<=2;q2++)
 {
 sum=sum+a[q1][q2];
 if(a[q1][q2]==0)
 {
 test2++;
 l=q1;
 p=q2;
 }
 }
}
if(test2==1)
 {
 u=45-sum;
 a[l][p]=u;
 }
 u=0;
 l=0;
 p=0;
 sum=0;
 test2=0;
for(q1=3;q1<=5;q1++) //5th block checking only for one empty
{
 for(q2=3;q2<=5;q2++)
 {
 sum=sum+a[q1][q2];
 if(a[q1][q2]==0)
 {
 test2++;
 l=q1;
 p=q2;
 }
 }
}
if(test2==1)
 {
 u=45-sum;
 a[l][p]=u;
 }
 u=0;
 l=0;
 p=0;
 sum=0;
 test2=0;
for(q1=3;q1<=5;q1++) //6th block checking only for one empty
{
 for(q2=6;q2<=8;q2++)
 {
 sum=sum+a[q1][q2];
 if(a[q1][q2]==0)
 {
 test2++;
 l=q1;
 p=q2;
 }
 }
}
if(test2==1)
 {
 u=45-sum;
 a[l][p]=u;
 }
 u=0;
 l=0;
 p=0;
 sum=0;
 test2=0;
for(q1=6;q1<=8;q1++) //7th block checking only for one empty
{
 for(q2=0;q2<=2;q2++)
 {
 sum=sum+a[q1][q2];
 if(a[q1][q2]==0)
 {
 test2++;
 l=q1;
 p=q2;
 }
 }
}
if(test2==1)
 {
 u=45-sum;
 a[l][p]=u;
 }
 u=0;
 l=0;
 p=0;
 sum=0;
 test2=0;
for(q1=6;q1<=8;q1++) //8th block checking only for one empty
{
 for(q2=3;q2<=5;q2++)
 {
 sum=sum+a[q1][q2];
 if(a[q1][q2]==0)
 {
 test2++;
 l=q1;
 p=q2;
 }
 }
}
if(test2==1)
 {
 u=45-sum;
 a[l][p]=u;
 }
 u=0;
 l=0;
 p=0;
 sum=0;
 test2=0;
for(q1=6;q1<=8;q1++) //9th block checking only for one empty
{
 for(q2=6;q2<=8;q2++)
 {
 sum=sum+a[q1][q2];
 if(a[q1][q2]==0)
 {
 test2++;
 l=q1;
 p=q2;
 }
 }
}
if(test2==1)
 {
 u=45-sum;
 a[l][p]=u;
 }
 u=0;
 l=0;
 p=0;
 sum=0;
 test2=0;
if(c==9)
{
 for(int i1=0;i1<9;i1++)
 {
 for(int i2=0;i2<9;i2++)
 {
 if(a[i1][i2]==0)
 c=1;
 }
 }
}
}
box();
for(int r1=0;r1<9;r1++)
{
for(int r2=0;r2<9;r2++)
{
 gotoxy(27,4);
 cout<<"**Here's the solved SUDOKU**";
 gotoxy(29+n1,8+n2);
 cout<<a[r1][r2];
 n1=n1+3;
 }
 n2=n2+2;n1=0;
}
getch();
cleardevice();
gotoxy(36,15);
cout<<"Thank you";
getch();
}