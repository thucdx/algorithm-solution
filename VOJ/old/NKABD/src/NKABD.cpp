//============================================================================
// Name        : NKABD.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
#include <cstring>
#include <math.h>
bool prime[100003];
void setPrime();
bool divisor[100003];
bool check(int n);
int main() {
	int num=0;
	int l,r,i;
	setPrime();
	scanf("%d%d",&l,&r);
	for(i=l;i<=r;i++)
	{
		if(check(i)) {
			num++;
			//cout<<i<<endl;
		}

	}
	printf("%d\n",num);
}
void setPrime(){
	int i,j,c;
	int limit=100001;
	memset(prime,1,limit);
		prime[0]=0;
		prime[1]=0;
		for(i=2;i*i<=limit;i++){
			if(prime[i]){
				//if(i<=100) cout<<i<<' ';
				j=i;
				while(j*i<=limit){
					prime[j*i]=false;
					j++;
				}
			}
		}
		//cout<<endl;
		/*
	memset(prime,1,100001);
	cout<<"Xong memset"<<endl;
	prime[0]=0;
	prime[1]=0;
	cout<<"Xong memset"<<endl;
	for(i=2;i<=100001;i++){
		if(prime[i]){
			c=i*i;
			while(c<=100001)
			{
				prime[c]=0;
				c+=i;
			}
		}
	}*/
}
bool check(int n){
	int i,tmp;
	int sum=1;
	if(n%2!=0)return false;
	int limit=sqrt((double)n)+1;
	memset(divisor,1,100001);
	for(i=2;i<=limit;i++){
		if(prime[i]&& (n%i==0)){
			tmp=i;
			while(tmp<n){
				if(n%tmp==0&& divisor[tmp])
				{
						sum+=tmp;
						cout<<tmp<<endl;
						divisor[tmp]=false;
				}
				tmp+=i;
			}
			}
		}
	if(sum>n)return true;
	else return false;
}
/*
bool check(int n){
	int i;
	int sum=1;
	int limit=n/2;
	if(n%2==1) return false;
	for(i=2;i<=limit;i++)
		if(n%i==0) sum+=i;
	if(sum>n) return true;
	return false;
}

*/
