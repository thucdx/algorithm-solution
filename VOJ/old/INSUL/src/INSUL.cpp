//============================================================================
// Name        : INSUL.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
#include <algorithm>

int n;
int list[100005];
int cmp(const void *a, const void *b){
	return(*(int*)a -*(int *)b);
}
int main() {
	int i,j,result=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&list[i]);
		result+=list[i];
	}
	//qsort(list,n,cmp);
	qsort(list,n,sizeof(list[0]),cmp);
	j=n-1;
	i=0;
	while(i<=j){
		result+=(list[j]-list[i]);
		++i;
		--j;
	}
	cout<<result<<endl;
}
