//============================================================================
// Name        : WORDCNT.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int m=0;
int i,j;
int nTest;
int main() {
	char c;
	int prev=-1,cur=0,len=1;
	scanf("%d",&nTest);
	while(getchar()!='\n'); //xoa bo nho.
	for(i=1;i<nTest;i++){
		prev=-1; cur=0;len=0;
		m=0;
		while((c=getchar())!='\n'){
		if(c==' '){
			//Sang tu moi.
			if(cur==prev) len++;
			else //cur !-prev
			{
				if(len>m) m=len;
				len=1;
			}
			prev=cur;cur=0;
		}
		else{ //c la kitu
				cur++;
			}
		}
		cout<<m<<endl;
	}
	prev=-1; cur=0;len=0;
	m=0;
	while(true){
	if(scanf("%c",&c)!=1) break;
	if(c==' '){
		//Sang tu moi.
		if(cur==prev) len++;
		else //cur !-prev
		{
			if(len>m) m=len;
			len=1;
		}
		prev=cur;cur=0;
	}
	else{ //c la kitu
			cur++;
		}
	}
	cout<<m<<endl;

}
