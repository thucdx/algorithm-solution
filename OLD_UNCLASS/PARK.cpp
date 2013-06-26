#include <iostream>
using namespace std;

int c[10005];
int main()
{
    int n;
    int a;
    freopen("input.txt","rt", stdin);
    freopen("output.txt","wt", stdout);
    
    cin>>n;
    for(int i=1;i<=n;i++)
    {
     cin>>a;
     c[a%10000]++;       
    }
    int val=0;
    for(int i=0;i<=10004;i++)
    {
     if(c[i]>0)
     {
      val+=100;
      if(c[i]>5) val+=c[i]-5;              
     }
    }
    cout<<val<<endl;    
}
