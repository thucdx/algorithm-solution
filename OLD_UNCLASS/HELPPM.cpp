#include <iostream>
#include <conio.h>
using namespace std;
#define max 505
int m,n,k;
int st[max][max];
int f[max][max][max];
int xa=-2,xb,ya,yb;
int minS=3000;
int sub[max];
int sum[max];

void input();
void process();
void sseq(int i,int j);
int main()
{
 input();
 process();
 getch();
 return 0;    
}
void input()
{
    cin>>m>>n>>k;
    int i,j;
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    cin>>st[i][j];
}
void process()
{
  int i,j,t;
  int L[max],R[max]; //l[i] la tong cac so st[0]+...st[i-1]; r[i]: st[i+1]+..+st[n-1];
  
 //initial;     
 for(i=0;i<m;i++)
 {  
    L[0]=0;       
    R[n-1]=st[i][n-1];      
    for(j=1;j<n;j++)
    {
      L[j]=L[j-1]+st[i][j-1];               
    }
    for(j=n-2;j>=0;j--)
    {
     R[j]=R[j+1]+st[i][j];                   
    }
    for(j=0;j<n;j++)
    for(t=j;t<n;t++)
    {
     f[i][j][t]=R[0]-L[j]-R[t]+st[i][t];
    } 
 }
 
 //Duyet tim
 //Tim 2 cot
 for(i=0;i<n;i++)
 for(j=i;j<n;j++)
 {
    sseq(i,j);             
 }
 if(xa==-2) cout<<"-1"<<endl;
 else
 {
 cout<<minS<<endl;
 cout<<xa+1<<' '<<ya+1<<' '<<xb+1<<' '<<yb+1<<endl;
 }
 
}
void sseq(int c1,int c2)
{
      int i,j;
      int shortest=m;
      //cout<<endl;
      //cout<<c1<<"!"<<c2<<'!'<<endl;
      for(i=0;i<m;i++)
      {
            sub[i]=f[i][c1][c2];    
            //cout<<i<<' '<<sub[i]<<' '<<endl;
      }
      int sum=0;
      j=0;
     for(i=0;i<m;i++)
     {
          while(j<m && sum<k)
          {
           sum=sum+sub[j];  
           j++;
                 
          }
          if(sum>=k){
                     if((j-i)*(c2-c1+1)<minS)
                     { //cap nhat
                      minS=(j-i)*(c2-c1+1);
                      xa=i;ya=c1;
                      xb=j-1;yb=c2;            
                     }
                     j=i+1;
                     sum=0;
          }                
          else  break;
     }
      /*
      //Tim day con ngan nhat co tong lon hon k.
      //khoi tao mang sum[], sum[i]:a[0]+..+a[i]
      sum[0]=sub[0];
      for(i=1;i<m;i++)
            sum[i]=sum[i-1]+sub[i];
      if(sum[m-1]<k) return;
      
      for(i=0;i<m;i++)
      {
       //tim do
       int tmp=sum[m-1]-sum[i]+sub[i];
       if(tmp <k) break;
       
       else
       {   tmp=sum[i]-sub[i]+k;
           //tim tmp trong list sub[][i,m-1];
           int head=i,tail=m-1;
           int nxt;
           //chat nhi phan
           do
           {
              nxt=(head+tail)/2;
              if(sum[nxt]<tmp) head=nxt;
              else
                 tail=nxt;
              //cout<<"head,tail   "<<head<<' '<<tail;
           } 
           while(head+1<tail);
           if(sum[head]==sum[tail])
           tail=head;
           while(tail>i && sum[tail-1]==sum[tail])
           tail--;
           //tail chinh la gia tri can tim
           if((tail-i+1)*(c2-c1+1) <minS)
           {
            minS=(tail-i+1)*(c2-c1+1);
            xa=i;ya=c1;
            xb=tail;yb=c2; 
            //cout<<"MIN!!!!"<<i<<' '<<tail<<' '<<c1<<' '<<c2;                   
           }
       } 
       */                
      
}

