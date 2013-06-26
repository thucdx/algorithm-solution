//============================================================================
// Name        : MINK_(tU.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <deque>
#include <stdio.h>
using namespace std;
int list[17005];
int n,k;
int top=-1,bot=0;
int stack[17005];
int pos[17005];
bool isEmpty(){
	return (top<bot);
}
void push(int i){
	while(!isEmpty() && (stack[top]>=list[i])) --top;
	++top;
	stack[top]=list[i];
	pos[top]=i;
}
void pop(int i){
	while(!isEmpty()&&(pos[bot]<=i)) ++bot;
}
void input(){
	int i;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;++i){
		scanf("%d",&list[i]);
	}
}
void process(){
	int i;
	for(i=1;i<=k;++i){
		//push(i);
		while(!isEmpty() && (stack[top]>=list[i])) --top;
			++top;
			stack[top]=list[i];
			pos[top]=i;
	}
	printf("%d ",stack[bot]);
	for(i=k+1;i<=n;++i){
		//pop(i-k);
		//push(i);
		while(!isEmpty()&&(pos[bot]<=i)) ++bot;
		while(!isEmpty() && (stack[top]>=list[i])) --top;
					++top;
					stack[top]=list[i];
					pos[top]=i;
		printf("%d ",stack[bot]);
	}
	printf("\n");
}
int main() {
	/*
	freopen("" , "rt", stdin);
	freopen("", "wt", stdout);
	*/
	int nTest;
	scanf("%d",&nTest);
	while(nTest>0){
		input();
		process();
		nTest--;
	}
}
