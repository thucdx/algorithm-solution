//============================================================================
// Name        : NKLETTER.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	string a,b;
	int la,lb,maxL=0;
	cin>>a>>b;
	la=a.length();
	lb=b.length();
	int i,j,k;
	for(i=la-1;i>=0;--i){
		if(la-i>lb) break;
		j=0;k=i;
		while(a[k]==b[j] &&(k<la)){
			++k;++j;
		}
		if(k==la) maxL=la-i;

	}
	printf("%d\n",la+lb-maxL);

}
