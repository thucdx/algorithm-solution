//============================================================================
// Name        : BWPOINT.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
//Cach nay , ton bo nho. Độ phức tạp: 2*nlogn+4*n.

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 100002
int white[MAX];
int black[MAX];
int cmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}
int n;
int main() {
	int m,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&white[i]);
	for(i=0;i<n;i++)
			scanf("%d",&black[i]);
	qsort(white,n, sizeof(white[0]),cmp);
	qsort(black,n, sizeof(black[0]),cmp);
	//merge lai
	m=0;i=0;j=0;
	int num=0;int prev,cur;
	bool isOk=true;
	if(white[i]<black[j]) {cur=1;i++;}
	else {cur=0;j++; }
	for(m=1;m<2*n;m++){
		prev=cur;
		if(j>=n) {cur=1; i++;}
		else
		if(i>=n) {cur=0; i++;}
		else
		if(white[i]<black[j]){
			cur=1;
			i++;
		}
		else {cur=0;j++;}
		if(isOk==true)
		{
			if(prev!=cur){num++;isOk=false;}
		}
		else isOk=true;
	}

	cout<<num<<endl;
}
