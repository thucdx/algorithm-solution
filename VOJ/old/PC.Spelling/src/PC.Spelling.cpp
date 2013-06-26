//============================================================================
// Name        : Spelling.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
string l[257];
void init();
int main() {
	init();
	int i,nTest,j;
	char s[10000];
	cin>>nTest;
	while(getchar()!='\n');
	for(i=1;i<=nTest;++i){
		gets(s);
		cout<<"Case #"<<i<<": ";
		cout<<l[s[0]];
		for(j=1;j<strlen(s);j++){
			if(l[s[j]][0]==l[s[j-1]][0])
				cout<<" ";
			cout<<l[s[j]];
		}
		cout<<endl;
	}
}
void init(){
	l['a']="2";
	l['b']="22";
	l['c']="222";

	l['d']="3";
	l['e']="33";
	l['f']="333";

	l['g']="4";
	l['h']="44";
	l['i']="444";

	l['j']="5";
	l['k']="55";
	l['l']="555";

	l['m']="6";
	l['n']="66";
	l['o']="666";

	l['p']="7";
	l['q']="77";
	l['r']="777";
	l['s']="7777";

	l['t']="8";
	l['u']="88";
	l['v']="888";

	l['w']="9";
	l['x']="99";
	l['y']="999";
	l['z']="9999";
	l[' ']="0";
}
