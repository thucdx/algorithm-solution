//============================================================================
// Name        : CHEAT.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
#define max 100005
int prev[max+1],next[max+1];

int main() {
	int n,i,val,last=0;
	bool isCheater=false;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		prev[i]=i-1;
		next[i]=i+1;
	}

	for(i=1;i<=n;++i){
		scanf("%d",&val);
		if(val!=prev[last]&& val<last) {
			isCheater=true;
			break;
		}
		prev[next[val]]=prev[val];
		next[prev[val]]=next[val];
		last=val;
	}
	if(isCheater) cout<<"YES\n";
	else cout<<"NO\n";

}
