//============================================================================
// Name        : NKINV.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
#define maxN 60004
int list[maxN+1];

void init(){
	memset(list,0,maxN+1);
}
void update(int i){
	while(i<maxN){
		++list[i];
		i+=i&(-i);
	}
}
long long get(int i){
	long long sum=0;
	while(i>0){
		sum+=list[i];
		i-=i&(-i);
	}
	return sum;
}

int main() {
	int n,t,res=0;
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&t);
		res+=get(maxN)-get(t);
		update(t);
	}
	printf("%d\n",res);

}
