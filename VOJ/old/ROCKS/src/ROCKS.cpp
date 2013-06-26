//============================================================================
// Name        : ROCKS.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int list[(1<<15)+2];
int mu[16];
void init();
void print();
int main() {
	scanf("%d",&n);
	if(n==1) {cout<<"O\nX\nO\n";return 0;}
	init();
	print();
}
void init(){
	int i,j,t;
	mu[0]=1;
	for(i=1;i<=n;i++){
		mu[i]=mu[i-1]<<1;
		//cout<<i<<' '<<mu[i]<<endl;
	}
	list[0]=0;//00=OO
	list[1]=2;//10 =x0
	list[2]=3;//11=xx;
	list[3]=1;//01=0x;
	for(i=3;i<=n;++i){
		//danh dau i
		j=mu[i-1];
		t=mu[i-1]-1;
		while(j<=mu[i]-1){
			list[j]=mu[i-1]|list[t];
			++j;--t;
		}
	}
}
void print(){

	int i,t;
	for(i=0;i<=mu[n]-1;++i){
		for(t=n-1;t>=0;--t){
			if((list[i]&mu[t])!=0)
				printf("X");
			else printf("O");
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
		printf("O");
	printf("\n");
}

