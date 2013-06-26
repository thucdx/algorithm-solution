#include <iostream>
#include <cstring>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;++i)

#define MAX 60000
int nNum[60005];
void update(int i);
long long get(int i);
int n;
int main()
{       
      freopen("input.txt", "rt", stdin);
      freopen("output.txt", "wt", stdout);
      int t;
      long long rs=0;
      cin>>n;
      FOR(i,1,n)
      {
        cin>>t;
        rs+=get(MAX)-get(t);
        cout<<i<<" "<<rs<<endl;
        update(t);
      }  
      cout<<rs;
}
void update(int i)
{
    while(i<=MAX)
    {
        ++nNum[i];
        i+=i&(-i);
    }    
}
long long get(int i)
{
    long long rs=0;
    while(i>0)
    {
        rs+=nNum[i];
        i-=i&(-i);
    }    
    return rs;
}
