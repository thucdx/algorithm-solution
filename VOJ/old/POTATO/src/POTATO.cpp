//============================================================================
// Name        : POTATO.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <string.h>
#include <stdio.h>
int main() {
	char c[11];
	int n,remain;
	do{
		scanf("%s",c);
		if(strcmp(c,"[END]")==0) break;
		while(getchar()!='\n');
		scanf("%d",&n);
		remain=n%5;
		if(remain==0||remain==2) cout<<"Hanoko"<<endl;
		else cout<<"Taro"<<endl;
	} while(true);
}
