/*#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;
inline bool isPrime(int n);
#define f(n) for(int i=1;i<=n;i++)
int main()
{
	int nTest,n;
	cin>>nTest;
	for(int i=1;i<=nTest;i++){
		cin>>n;
		int result=0;
		for(int j=2;j<=n;j++){
			if(isPrime(j)){
				if(isPrime(2*n-j))
				{
					result++;
					cout<<j<<' '<<2*n-j<<endl;
				}
			}
		}
		cout<<result<<endl;

	}
}
bool isPrime(int n){
	if(n==1) return false;
	if(n==2) return true;
	if (n%2==0) return false;
	int i;
	int lim=sqrt(n)+1;
	for(i=3;i<=lim;i++)
		if(n%i==0)return false;
	return true;

}
*/

#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;
//int G[1000500];
int F[1000500];
int prime[1000005];
int countPrime[1000005];
bool isPrime[1000005];
int nPrime;
void makePrime();
void makeG();
void makeF();
void count();
int count(int n);
int main() {
	int nTest,n,i,j;
	makePrime();
	//makeG();
	count();
	//makeF();
	cin>>nTest;
	for(int i=1;i<=nTest;i++)
	{
		cin>>n;
		int result=0;
		for(j=1;j<=nPrime;++j){
			result+=count((n<<1)-prime[j]);
		}
		cout<<"before:"<<result<<' '<<n<<endl;
		if(isPrime[n])
		{
			result=(result+1)/2;
		}
		else result/=2;
		cout<<result<<endl;
		//cout<<F[n]<<endl;
	}
}
int count(int n){
	if (n<=1) return 0;
	return countPrime[n];
}
void count(){
	int i;
	countPrime[0]=0;
	countPrime[2]=1;
	for(i=3;i<=1000005;i++)
		countPrime[i]=countPrime[i-1]+isPrime[i];
}
void makePrime()
{
	memset(isPrime,1,sizeof(isPrime));
	nPrime=0;
	int i,j;
	for(i=2;i<=1000000;++i){
		if(isPrime[i]){
			++nPrime;
			prime[nPrime]=i;
			j=i<<1;
			while(j<=1000000){
				isPrime[j]=false;
				j+=i;
			}
		}
	}
}
/*
void makeG(){
	int i,j;
	for(i=1;i<=nPrime;++i)
	{
		for(j=i;prime[j]<=1000000-prime[i];++j){
				++G[prime[i]+prime[j]];
		}

	}
}
void makeF()
{
	F[2]=1;
	for(int i=3;i<=500000;++i){
		F[i]=F[i-1]+G[i<<1];
	}
}
*/

