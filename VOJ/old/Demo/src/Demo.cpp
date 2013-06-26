//============================================================================
// Name        : Demo.cpp
// Author      : ThucDX
// Version     :
// Copyright   : Demo
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
#include <cstring>
//#include <stdio.h>
#include <bitset>
#define limit 1000000
#define f(a,b) for(int i=(int )a; i<= (int)b;i++)
bool isPrime[limit+1];
int stringToInt(string a){
	stringstream ss;
	ss<<a;
	int n;
	ss>>n;
	return n;
}
string intToString(int n){
	stringstream ss;
	ss<<n;
	string rs;
	ss>>rs;
	return rs;
}
vector <int > v;
	int z,p,q,r;
	int a[1817];

#include <stdio.h>
int main(){int i=1224;while((--i)>=0) printf("VNOI");}
	/*
	// create a bitset that is 8 bits long
	 bitset<8> bs;
	 // display that bitset
	 for( int i = (int) bs.size()-1; i >= 0; i-- ) {
	   cout << bs[i] << " ";
	 }
	 cout << endl;
	 // create a bitset out of a number
	 bitset<8> bs2( (long) 131 );
	 // display that bitset, too
	 for( int i = (int) bs2.size()-1; i >= 0; i-- ) {
	   cout << bs2[i] << " ";
	 }
	 cout << endl;

	int i;
	string a;
	cin>>a;
	cout<<a<<"!"<<endl;
	for(i=0;i<10;i++)
		v.push_back(i*i);
	f(0,v.size()-1) cout<<v[i]<<endl;
	vector<int>::iterator it=v.begin();
	while(it!=v.end()){
		cout<<*it<<endl;
		it++;
	}
	*/
	//Sang eratosten
	/*
	memset(isPrime,1,limit);
	int i,j;
	isPrime[0]=0;
	isPrime[1]=0;
	for(i=2;i*i<=limit;i++){
		if(isPrime[i]){
			j=i;
			while(j*i<=limit){
				isPrime[j*i]=false;
				j++;
			}
		}
	}
	for(i=2;i*i<=limit;i++)
		if(isPrime[i])
		cout<<i<<' ';
	*/

