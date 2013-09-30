#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
//#include <conio.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);
#define pb  push_back
#define INF 1000000000
#define VI vector<int>
#define VII vector<VI>
//ham
template <class T>  //so ko am
T gcd(T a, T b){if(b==0) return abs(a); else return gcd(b,a%b);}
template <class T>  
T lcm(T a, T b){ return a/gcd(a,b) *b;}

int mark[16130000];
int n;
bool isPrime(int a){
    if(a<= 1) return false;
    if(a==2) return true;
    int lim=sqrt(a)+1;
    for(int i=2;i<=lim;++i)
        if(a%i==0) return false;
    return true;
}
long long mod(long long a,long long d,long long n) //a^d mod n
{
	if(d==0) return 1;
	long long tmp =mod(a,d/2,n);
	long long rs= tmp*tmp%n;
	if(d%2==1) rs=rs*a %n;
	return rs;
}
bool isPrimeMB(long long n){ //Phep thu Miller-Rabin voi round vong , n le , lon hon 3
// Require: mod(T a, T d, T n)
    int rnd=3;
    int p[]={2,7,61};
	int s;
	int i;
	long long d,a,x;
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0) return false;
	d=n-1;
	s=0;
	while(d%2==0){
		s++;
		d/=2;
	}
	//n-1 = 2^s .d
	REP(i,1,rnd){
		a=p[i-1];
		x= mod(a,d,n);
		if(x==1 || x==n-1) continue;
		bool found=false;
		REP(r,1,s-1)
		{
			x=(x*x)%n;
			if(x==1) return false;
			if(x==n-1){
				found=true;
				break;
			}
		}
		if(!found) return false;
	}
	return true;
}
bool checkPrime(int i)
{
    if(i<=1000)
    return isPrime(i);
    else return isPrimeMB(i);
}

double EPS=1e-9;

int main()
{
    //freopen("PRIME1.IN", "rt", stdin);
    //freopen("PRIME1.OUT", "wt", stdout);
    int m,n,nTest;
    scanf("%d",&nTest);
    REP(i,1,nTest)
    {
        scanf("%d%d",&m,&n);
        int rs=0;
        if(m<=2) 
        printf("2\n");
        REP(i,m,n)
        {
            if(i%2==1)
            if(checkPrime(i))
                printf("%d\n",i);
        }    
        printf("\n");
    }
}
