//============================================================================
// Name        : 2.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <stdio.h>
using namespace std;
#define max 1000
int list[max+1];
int credit,nItem;

int main() {
	int i,j,nTest,m,n;
	cin>>nTest;
	for(i=1;i<=nTest;++i){
		cin>>credit>>nItem;
		for(j=1;j<=nItem;++j)
			cin>>list[j];
		//Tinh toan.
		for(m=1;m<nItem;++m)
			for(n=m+1;n<=nItem;++n)
			{
				if(list[m]+list[n]==credit){
					cout<<"Case #"<<i<<": "<<m<<" "<<n<<endl;
				}
			}
	}
}
