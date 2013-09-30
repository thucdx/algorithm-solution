#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
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
#define VVI vector<VI>
vector<int> prime;
int f[11005];
int cul[11005];
set<int> sum;
multiset<int> tk;
void init();
bool isPrime(int a);
long long mod(long long, long long, long long);
bool isPrimeMB(long long);
int main()
{
    //freopen("MRPIME1.IN",  "rt", stdin);
    //freopen("MPRIME1.OUT", "wt", stdout);
    init();
    int val;
    do
    {
        scanf("%d",&val);
        //cout<<"n= "<<val<<endl;
        if(val==0) break;
        printf("%d\n",f[val]);    
    }while(true);
}
void init()
{
    int cnt=0;
    prime.push_back(2);
    int s=2;
    sum.insert(2);
    sum.insert(0);
    cul[0]=2;
    for(int i=3;i<=11000;i+=2)
    {
        if(isPrimeMB(i))
        {   
            cnt++;
            cul[cnt]=cul[cnt-1]+i;
        }
    }
    REP(i,0,cnt-1)
    {
        if(cul[i]<=11000) 
            f[cul[i]]++;
        else break;
    }
    REP(i,1,cnt-1)
    REP(j,i,cnt-1)
    {
        //tk.insert(cul[j]-cul[i-1]);
        int k=cul[j]-cul[i-1];
        if(k<=11000) 
            f[k]++;
        else break;
    }
}
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
	int s;
	int i;
	long long d,a,x;
	int rnd=3;
	int p[]={2,7,61};
    if(n<=1000)
        return isPrime(n);
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
	//srand(time(NULL));
	REP(i,1,rnd){
		//a=rand()%(n-3)+2;
		a=p[i-1];
		//a=p[i-1];
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
    
