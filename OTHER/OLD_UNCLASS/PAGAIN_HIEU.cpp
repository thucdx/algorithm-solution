#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

bool isPrime(int n) {
	if (n<2) return false; // optional
	for (int i=2; i*i<=n; ++i) if (n%i==0) return false;
	return true;
}

unsigned long long power(unsigned long long a, unsigned long long d,unsigned long long n)
{
    if(d==1) return a%n;
    else 
    {
         unsigned long long k = power(a,d/2,n);
         if(d%2==0) return k*k%n;
         else return ((k*k)%n*a)%n;
    }
}
bool rabinMiller(unsigned long long n, int k) {
	if (n<=50) return isPrime(n);
	unsigned long long d=n-1, s=0;
	while (d%2==0) {++s; d/=2;}
	for (int i=1; i<=k; ++i) {
		unsigned long long a = rand()%(n-2)+2;
		unsigned long long x = power(a,d,n);
		if (x == 1 || x == n-1) continue;
		for (int r=1; r<s; ++r) {
			x=(unsigned long long)(x*x) % n;
			if (x==1) return false;
			if (x==n-1) break;
		}
		if (x!=n-1) return false;
	}
	return true;
}


int main()
{
    int test;
    freopen("PAGAIN.IN","rt", stdin);
    freopen("PAGAIN.OUT","wt", stdout);    
    unsigned long long n;
    scanf("%d",&test);
    for(int i = 1;i<=test;i++)
    {
        scanf("%lld",&n);
        n--;
        while(true)
        {
            if(rabinMiller(n,20))
            {
                printf("%lld\n",n);
                break;
            }
            n--;
        }
    }
   // getch();
}

