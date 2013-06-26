//============================================================================
// Name        : NKNUMFRE.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
inline bool check (int a);
inline int gcd(int ,int);
int main() {
	int a,b,i,num=0;
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++)
	{
		if(check(i))num++;

	}
	cout<<num<<endl;

}
bool check(int a){
	int reverse=0;
	int b=a;
	while(b!=0){
		reverse=reverse*10+b%10;
		b=b/10;
	}
	if(a%2==0 && reverse%2==0)return false;
	if(gcd(a,reverse)!=1)return false;
	return true;
}
int gcd(int a,int b){
	int tmp;
	while(b!=0){
		tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
}
