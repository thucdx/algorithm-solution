#include <iostream>
using namespace std;
#include <algorithm>
#define REP(i,a,b) for(int i=a;i<=b;i++)
int main()
{
    freopen("IN.IN","rt", stdin);
    freopen("OUT.OUT", "wt", stdout);
    int list[100],n;
    scanf("%d",&n);
    REP(i,1,n)
    {
        scanf("%d",&list[i]);    
    }    
    do
    {
        REP(i,1,n) cout<<list[i]<<" ";
        cout<<endl;    
    } while(next_permutation(list+1,list+n+1));
}
