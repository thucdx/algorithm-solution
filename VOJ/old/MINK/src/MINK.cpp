//============================================================================
// Name        : MINK.cpp
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
deque <int> q;
int n,k;
void push(int i){
	//them vao cuoi, tat ca cac phan tu lon hon se bi loai
	while(!q.empty() && (list[q.back()]>=list[i])) q.pop_back();
	q.push_back(i);
}
void pop(int i){
	//Xoa tat cac cac phan tu tu head cua stack toi nhung phan tu nho hon hoac bang list[i]
	while(!q.empty() && (q.front()<=i)) q.pop_front();
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
		push(i);
	}
	printf("%d ",list[q.front()]);
	for(i=k+1;i<=n;++i){
		pop(i-k);
		push(i);
		printf("%d ",list[q.front()]);
	}
	printf("\n");
}
int main() {
	freopen("" , "rt", stdin);
	freopen("", "wt", stdout);
	int nTest;
	scanf("%d",&nTest);
	while(nTest>0){
		input();
		process();
		nTest--;
	}
}
