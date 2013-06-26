#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool checkPrime(long long a)
{
    if(a<=1 ) return false;
    if(a<=3) return true;
    if(a%2==0) return false;
    int lim=sqrt(a)+1;
    for(int i=3;i<=lim;i+=2)
    {
        if(a%i==0) return false;    
    }
    return true;
}

long long phi(long long n){
    long long result=1;
    long long mu;
    int i=2;
    while(i<=n)
    {
        if(n%i==0)
        {
            mu=1;
            result*=(i-1);
            mu=1;
            while(n%i==0)
            {
                mu*=i;
                n/=i;
            }    
            result*=(mu/i);
        }
        i++;
        //if(i>n) break;
    }
    return result;
}
int main()
{
    freopen("ANS.OUT","wt", stdout);
    long long n=123456;
    //cout<<checkPrime(11)<<endl;
    cout<<phi(n);
        
}
