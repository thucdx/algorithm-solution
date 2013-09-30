#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;++i)
#define GO(i,n) for(int i=0;i<=n;i++)
#define BACK(i,b) for(int i=b;i>=0;--i
#define MAX 100000000
int main()
{
    //freopen("PRIME.IN","rt", stdin);
    freopen("LIS.IN", "wt", stdout);
    srand(time(NULL));
    int n=30000;
    //int low=1000000;
    cout<<n<<endl;
    REP(i,1,n)
    {
       cout<<rand()%(100000000)<<endl;    
    }
//    cout<<0<<endl;
    
}
