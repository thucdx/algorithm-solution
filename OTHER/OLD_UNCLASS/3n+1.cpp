#include <iostream>
using namespace std;

#define MAX 100000000
#define f(i,a,b)\
for(int i=(int)a;i<=(int) b;i++)


bool flag[MAX];
int rs[MAX];
bool trace[MAX];
int m,n;
bool ar=false;
void input();
void process();
void initial();
void calc(int, int);
int main()
{
 initial();
 process();
 while(cin>>m>>n)
 {
  if(m<n) 
          ar=true;
  else {
       int tmp;
       tmp=m;
       m=n;
       n=tmp;
       ar=false;
       }
  calc(m,n);
  }
 return 0;
}
void initial()
{
 for(int i=1;i<=MAX;i++)
 {
  flag[i]=false;
  rs[i]=0;          
 }
 flag[1]=true;
 flag[2]=true;
 flag[4]=true;
 rs[1]=1;   
 rs[2]=2;
 rs[4]=3;
}
void input()
{
  cin>>m>>n; 
  if(m<n) 
          ar=true;
  else {
       int tmp;
       tmp=m;
       m=n;
       n=tmp;
       ar=false;
       }
}
void process()
{ 
 int max=0;
 int i=0;
 int j,step;
 for(i=2;i<=10000;i++)
 {
     if(!flag[i]) //i chua duoc tinh
     {   
         if(((i-4)%6==0) && flag[(i-1)/3])
                       rs[i]=rs[(i-1)/3]-1;         
         else
         {   
             j=i;
             step=0;
             do{
                if(j%2==0) {
                           j=j/2;
                           if(j<=MAX)
                           trace[step]=false;
                }
                else {
                     j=3*j+1;
                     if(j<=MAX)
                     trace[step]=true;
                     }
                
                step++;        
             }
             while(!flag[j]);
             rs[i]=rs[j]+step;
             
             //truy vet lai. sua lai gia tri.
             /*
             step--;
             while(step>=0)
             {
              if(trace[step]==true)
                 {
                  rs[(j-1)/3]=rs[j]+1;
                  j=(j-1)/3;
                  flag[j]=true;
                 }
             else
                 {
                  rs[2*j]=rs[j]+1;  
                  j=2*j;  
                  flag[j]=true;
                 }
             step--;
             }
               
             */
         }
         flag[i]=true; //i da tinh duoc;
         
     }
    
     if(max<rs[i]) max=rs[i];
 }     
}
void calc(int m, int n)
{
 int max=0;
 int i;
 for(i=m;i<=n;i++)
 if(max<rs[i]) max=rs[i];    
 if(ar)
  cout<<m<<" "<<n<<" "<<max<<endl;
 else cout<<n<<" "<<m<<" "<<max<<endl;
}
