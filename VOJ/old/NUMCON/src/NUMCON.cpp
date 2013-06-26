//============================================================================
// Name        : NUMCON.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <algorithm>
#include <string.h>
#include <stdio.h>
struct num{
	string real;
	string mix;
}list[1000];
int n;
int cmp(const void *a, const void *b){
	num *na=(num*)a;
	num *nb=(num*)b;
	return -((na->mix).compare(nb->mix));
}
void input();
void print();
int main() {
	input();
	print();
}
void input(){
	int i;
	n=0;
	while(cin>>list[n].real){
		if(list[n].real=="END") break;
		list[n].mix=list[n].real;
		char c=list[n].real[0];
		for(i=list[n].real.length();i<=101;i++)
			list[n].mix+=c;
		list[n].mix[i]+='\0';
		//cout<<list[n].mix<<'\n'<<list[n].real;
		n++;
		}
	//cout<<n<<endl;
}
void print(){
	qsort(list,n,sizeof(list[0]),cmp);
	for(int i=0;i<n;i++)
		cout<<list[i].real;
	cout<<endl;

}
