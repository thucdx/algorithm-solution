//============================================================================
// Name        : C11SEQ_BIT.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
#define max 100005
long long s[max];
long long n,L,R,i,j,t[max],result=0;
void update(int i);
long long get(long long i);
void input();
int main() {
	input();

	for(i=n;i>=1;--i)
	{
		update(s[i]);
		result+=get(R+s[i-1])-get(L-1+s[i-1]);
	}
	cout<<result<<endl;
}
void input(){
	cin>>n>>L>>R;
	s[0]=0;
	for(i=1;i<=n;++i){
		cin>>s[i];
		s[i]+=s[i-1];
		t[i]=0;
	}
}
void update(int i){

	while(i<=max){
		t[i]++;
		i+=i&(-i);
	}
}
long long get(long long i){
	long long rs=0;
	while(i>0){
		rs+=t[i];
		i-=i&(-i);
	}
	return rs;
}
