#include <iostream>
using namespace std;
#include <algorithm>

int cmp(const void * a, const void *b);
bool flag[100];
int n;
int T;
float list[100];
void initial();
void input();
void process();
void delPart(double start,double end);
int stop=0;
bool isEmpty();
int main()
{
 cin>>T;
 for(int i=1;i<=T;i++)
 {
  initial();       
  input();
  cout<<"Case #"<<i<<":\n";
  process();
 }    
 
}

int cmp( const void* a, const void *b)
{
 float rs=*(float*)a - *(float*) b ;
 if(rs>0) return 1;
 else if(rs<0) return -1;
 else return 0;
}
bool isEmpty()
{
 for(int i=0;i<n;i++)
 if(!flag[i]) return false;
 return true; 
}
void initial()
{
 for(int i=0;i<=100;i++)
         flag[i]=false;     
}
void input()
{
 int i;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  scanf("%f",&list[i]);     
  //cout<<list[i];
}
}
void process()
{
 qsort(list,n,sizeof(float),cmp);
 delPart(0,1);   
 for(int i=0;i<n;i++)
 {
  if(!flag[i] ) cout<<list[i]<<endl;               
 }  
}
void delPart(double start, double end)
{
     if( isEmpty()) return;
     if(end-start<=0.000001) return;
     //stop++;
     //del [start+(end-start)/3, start+2*(end-start)/3]; 
     int i;
     //cout<<"S-E"<<start<<' '<<end<<"OK!"<<endl;
     //if(stop%30==0) getch();
     double headDel=start+(end-start)/3, tailDel=start+2*(end-start)/3;
     for(i=0;i<n;i++)
     {
      if(!flag[i])
      {
       if(headDel<= list[i] && list[i]<= tailDel)
       {
        cout<<list[i]<<endl;
        flag[i]=true;
       }            
      }                
     }
     delPart(start,headDel);
     delPart(tailDel,end);
     
}
