#include <iostream>
#include <cstdio>
#define REP(i,a,b) for(int i=a;i<=b;++i)

using namespace std;

int  phi(int n);
bool isPrime(int n);
int main()
{
    freopen("output.txt", "wt", stdout);
    REP(i,3,30)
    {
        cout<<i<<" "<<phi(i)<<endl;    
    } 
}
bool isPrime(int n)
{
    if(n<=1) return false;
    if(n<=3) return true;
        
}
int phi(int n)
{
    if(n<=1) return 0;
    if(n==2) return 1;
    int j=2;
    int result=n;
    while(j<=n)
    {    
        if(n%j==0)
        {
            result= result/j * (j-1);
            while(n%j==0)
                n/=j;    
        }
        j++;
    }
    return result;
}
