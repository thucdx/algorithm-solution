#include <iostream>
#include <algorithm>
using namespace std;
int mod(int n, int mu, int remain);
int main()
{
    freopen("ANS.OUT","wt", stdout);
    int mu=16000000;
    int n=3;
    int remain=1000000000;
    cout<<mod(n,mu,remain);
}
int mod(int n, int mu, int remain)
{
    if(mu==1) return n%remain;
    if(mu==0) return 1;
    int temp=mod(n,mu/2, remain);
    long long val=((long long )temp * temp)%remain;
    if(mu%2==1) val=((long long)val*n)%remain;
    return val;
}
