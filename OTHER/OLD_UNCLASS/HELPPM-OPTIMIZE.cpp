#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif
#include <iostream>
using namespace std;
#define max 501
int m,n,k;
int st[max][max];
int L[max][max];
int xa=-2,xb,ya,yb;
int minS=3000;
int sub[max];

void input();
void process();
void sseq(int i,int j);
int main()
{
 input();
 process();  
}
void input()
{
    scanf("%d %d %d",&m,&n,&k);
    int i,j;
    for(i=0;i<m;++i)
    for(j=0;j<n;++j)
    scanf("%d",&st[i][j]);
}
void process()
{
  int i,j,t;
 //initial;     
 for(i=0;i<m;i++)
 {  
    L[i][0]=st[i][0];       
      
    for(j=1;j<n;++j)
    {
      L[i][j]=L[i][j-1]+st[i][j];               
    }
    
 }
 
 //Duyet tim
 //Tim 2 cot
 for(i=0;i<n;++i)
 for(j=i;j<n;++j)
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
      for(i=0;i<m;++i)
      {       
				sub[i]=L[i][c2]-L[i][c1]+st[i][c1];
      }
      int sum=0;
      j=0;
	  
     for(i=0;i<m;++i)
     {	  
		  if(i>0)
			sum=sum-sub[i-1];
          while(j<m && sum<k)
          {
           sum=sum+sub[j];  
           j++;       
          }
          if(sum>=k){
                     if((j-i)*(c2-c1+1)<minS)
                     { 
                      minS=(j-i)*(c2-c1+1);
                      xa=i;ya=c1;
                      xb=j-1;yb=c2;            
                     }
                     
          }                
          else  break;
     }
           
      
}




