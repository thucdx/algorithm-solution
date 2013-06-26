//============================================================================
// Name        : GSS.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
#define max 15005
int c[15005];
void update(int i,int val){
	while(i<=max){
		c[i]+=val;
		i+=i&(-i);
	}
}
int  get(int i){
	int sum=0;
	while(i>0){
		sum+=c[i];
		i-=i&(-i);
	}
	return sum;
}
void init(){
	for(int i=0;i<=max-1;++i)
		c[i]=0;
}
int main() {
	int n,a,m,x,y;
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a);
		update(i,a);
	}
	scanf("%d",&m); //number of question
	for(int i=1;i<=m;++i){
		scanf("%d %d",&x,&y);
		printf("%d\n",get(y)-get(x-1));
	}

}
