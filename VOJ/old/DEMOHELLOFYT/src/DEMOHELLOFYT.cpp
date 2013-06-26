//============================================================================
// Name        : DEMOHELLOFYT.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char c[]="Hello FYT Network";
char *rs;
int main() {
	int i,j,len=37;
	/*
	rs=new char [len];
	for(i=0;i<len;++i)
		rs[i]='#';
	for(i=0;i<strlen(c);++i){
		rs[(i*i)%len]=c[i];
	}
	rs[37]='\0';
	cout<<rs<<endl;
	*/
	//char f[]="He#rl## #leoY###o####w### NT#####tk#F";
	char f[]=  "Heyrlty pleoYxrvoaweqwvnm NTBfReetkdF";
	for(i=0;i<((strlen(f)-3)>>1);++i)
		cout<<f[(i*i)%(strlen(f))];
	return 0;
}
