//============================================================================
// Name        : PERMUTATION.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
#define max 1000000
int pos[max];
float val[max];
int main() {
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&pos[i]);
	for(i=1;i<=n;i++)
			scanf("%f",&val[pos[i]]);
	for(i=1;i<=n;i++)
		cout<<val[i]<<' ';

	return 0;
}
