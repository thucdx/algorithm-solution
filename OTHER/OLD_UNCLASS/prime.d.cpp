#include <cstdio>
#include <iostream>
#include <conio.h>
using namespace std;

bool isPrime(int n)
{
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 ) return false;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0) return false;    
    }    
    return true;
}
int main()
{
    for(int i=1;i<=100;i++)
    {
        if(isPrime(i)) cout<<i<<endl;    
    }
    getch();
    
}
