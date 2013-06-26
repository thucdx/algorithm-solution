#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000
struct node
{
  int val;
  int pos;       
}t[MAX];
bool f[MAX];
int n=0;

int compare(const void *a, const void *b)
{
 node *ia=(node *)a;
 node *ib=(node *)b;
 return (ib->val - ia->val);   
}

void initial()
{
 int i;
 for(i=0;i<n;i++)
  f[i]=true;
}
void input()
{
      int i,j;
      cin>>n;
      for(i=0;i<n;i++)
      {
       cin>>t[i].val;
       t[i].pos=i;                
      }
}
void display()
{
 int i;
 for(i=0;i<n;i++)
 {
  cout<<t[i].val<<':'<<t[i].pos<<" ";                
 }     
}
void process()
{    
     qsort(t,n,sizeof(node),compare);
     //display();
     int step=0;
     int tmp=0;
     int i=0;
     for(i=n-1;i>=0;i--)
     {
      if(f[t[i].pos]==true){
               step++;
               f[t[i].pos]=false;
               tmp=t[i].pos;
               //cout<<"\nTuoi tai:"<<tmp;
               if(tmp>0) f[tmp-1]=false; //cout<<'-'<<tmp-1<<"bi xoa!";}
               if(tmp<n-1) f[tmp+1]=false;//cout<<'-'<<tmp+1<<"bi xoa!"; }     
      }                
     }
     cout<<step<<endl;
}
int main()
{
 input();
 initial();
 process();  
}
