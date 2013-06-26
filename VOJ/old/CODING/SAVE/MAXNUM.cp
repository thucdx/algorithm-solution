#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;

int n,p;
inline int powOfP(int q); //so mu cua so nguyen to q trong n!
void calc();
inline int powInN(int q,int n);
inline bool isPrime(int n);
int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	cin>>n>>p;
	calc();


}
int powOfP(int q){
	int result=0;
	int mu=q;
	while(mu<n){
		result+=n/mu;
		mu*=q;
	}
	return result;
}
bool isPrime(int n)
{
	int i;
	if(n<=3) return true; //chi tinh n>1
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0)
			return false;
	}
	return true;

}
int powInN(int q,int n)
{
	int result=0;
	while(n%q==0){
		result++;
		n/=q;
	}
	return result;
}
void calc()
{
	int i,m=30000,tmp;
	for(i=2;i<=p;i++){
		if(p%i==0){//i la uoc cua p
			if(isPrime(i)){
				tmp=powOfP(i)/powInN(i,p);
				if(tmp<m) m=tmp;
			}
		}
	}
	cout<<m<<endl;
}
