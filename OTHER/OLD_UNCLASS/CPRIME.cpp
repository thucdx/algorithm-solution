#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <conio.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;++i)
#define GO(i,n) for(int i=0;i<=n;i++)
#define BACK(i,b) for(int i=b;i>=0;--i
#define MAX 100000000
int d=20000;
bool isPrime[MAX+5];
int pi[100005];
int main()
{
    //freopen("PRIME.IN","rt", stdin);
    freopen("CPRIME.OUT", "wt", stdout);
    //Eratov
    memset(isPrime,true, sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;
    int lim=sqrt((double)MAX)+1;
    REP(i,2,lim)
    {
        if(isPrime[i])
        {
            int j=i*i;
            while(j<=MAX){
                isPrime[j]=false;
                j+=i;
            }    
        }    
    }
    int nPrime=0;
    REP(i,1,MAX){
        if(isPrime[i])
        {
            ++nPrime;
        }
        if(i%d==0)
        {
            pi[i/d]=nPrime;    
        }
    }
    cout<<endl;
    REP(i,0,MAX/d)
    {
       //cout<<"Nho hon "<<d*i<<" co"<<pi[i]<<" snt"<<endl;
       cout<<pi[i]<<",";
    }
}
