#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    long long n;
    long long rs;
    scanf("%lld",&n);
    rs=(n-1)*(n-2)*(n-3);
    rs/=6;
    for(int i=3;i<=n/2;++i)
    {
        rs-=(i-2)*(i-1)*2;    
    }
    printf("%d",rs);
}
