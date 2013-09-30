#include <iostream>
using namespace std;
#include <cmath>
int a,b;
bool isPrime(int n);
bool isOk(int n);
int main()
{   
    freopen("input.txt","rt", stdin);
    freopen("output.txt","wt", stdout);
   
    int nNum=0;
    int so;
    cin>>a>>b;
    int m,n,p ;//mnpnm
    for(m=1;m<=9;m++)
    for(n=0;n<=9;n++)
    for(p=0;p<=9;p++)
    {
     so=m*10000+n*1000+p*100+n*10+m;
     if(a<=so && so<=b && isPrime(so))
     {
          nNum++;
     }
    }
    cout<<nNum<<endl;
}
bool isPrime(int n)
{
     if(n%2==0) return false;
     int i;
     int lim=sqrt(n)+1;
     for(i=3;i<=lim;i++)
                        if(n%i==0) return false;
     return true;
}
