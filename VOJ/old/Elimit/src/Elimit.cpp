//============================================================================
// Name        : Elimit.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <sstream>
int main() {
	int i;
	string s[1000];
	string sss,a;
	stringstream ss;
	i=0;
	while(ss<<sss){
		if(sss=="END") break;
		ss>>a;
		i++;
		ss>>s[i];
		ss.clear();
		cout<<s[i];
	}
	for(int j=1;j<=i;j++)
		cout<<s[j]<<endl;
}
