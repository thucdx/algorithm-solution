#include <iostream>
#include <conio.h>
using namespace std;
void find(int a,int b, int*u,int*v);
int gcd(int a,int b);
int main()
{
 int a1,b1,a2,b2;
 cin>>a1>>b1>>a2>>b2;
 int u,v;
 int d=gcd(a1,a2);
 find(a1,-a2,&u,&v);
 u=(b2-b1)/d *u;
 v=(b2-b1)/d *v;
 while(u<0 || v<0)
 {
  u=u+a2;
  v=v+a1;         
 }
 cout<<u<<" "<<v<<endl;
 getch();
 return 0;
}
int gcd(int a,int b)
{
 if(a<0) a=-a;
 if(b<0) b=-b;
 int r;
 while(b!=0)
 {
  r=a%b;
  a=b;
  b=r;            
 }
 return a;    
}
void find(int m, int n, int *u, int *v)
{
  int a,b,q,r;
  int  xa,ya,xb,yb,xt,yt;
  a=m;
  b=n;
  xa=1;
  ya=0;
  xb=0;
  yb=1;
  do
  {
   q=a/b;
   r=a%b;
   a=b;
   b=r;
   xt=xa;
   yt=ya;
   xa=xb;
   ya=yb;
   xb=xt-q*xb;
   yb=yt-q*yb;
  }       
  while(b!=0);
  *u=xa;
  *v=ya;
}
