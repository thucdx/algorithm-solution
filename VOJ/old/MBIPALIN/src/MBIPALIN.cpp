//============================================================================
// Name        : MBIPALIN.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <stdio.h>
using namespace std;
int n,k;
long long L[1000003];
long long R[1000003];
long long make(string k,bool i);
long long make(long long k, bool i);
string toString(long long k);
long long toInt(string a);
string fill(long long k, long long len);
int main() {
	long long i;
	scanf("%d%d",&n,&k);
	//khoi tao L, R
	memset(L,0,k+1);
	memset(R,0,k+1);

	long long start=1,end=1,du,len=(n/2+1)/2;
	long long tmp;
	long long result=0;
	string tStr="";
	bool type=(n%4==0 ? true:false);
	for(i=1;i<=len;i++)
		end*=10;
	tmp=1;
	for(i=1;i<=n/2;i++)
		tmp*=10;
	du=tmp%k;
	start=end/10;

	for(i=start;i<end;i++)
	{
		tmp=(make(i,type))%k;
		R[tmp]++;
		L[(tmp*du)%k]++;
		//cout<<i<<' '<<tmp%k<<' '<<R[tmp%k]<<' '<<L[tmp*du%k]<<endl;
	}
	for(i=0;i<start;i++)
	{
		tStr=fill(i,len);
		tmp=make(tStr,type)%k;
		R[tmp]++;
		//cout<<tStr<<' '<<tmp<<" "<<R[tmp%k]<<endl;
	}
	//for(i=0;i<k;i++)
	//	cout<<L[i]<<' '<<R[(k-i)%k]<<endl;
	result=L[0]*R[0];
	for(i=1;i<k;i++)
		result+=L[i]*R[k-i];
	cout<<result<<endl;
	cin>>result;
}
long long make(long long k, bool i){
	long long rs=k;
	if (i){
		while(k!=0){
			rs=rs*10+k%10;
			k/=10;
		}
	}
	else {
		k=k/10;
		while(k!=0){
			rs=rs*10+k%10;
			k/=10;
		}
	}
	return rs;
}
string fill(long long k, long long len){
	string tmp=toString(k);
	string rs="";
	long long size=tmp.length();
	for(long long i=0;i<len-size;i++)
		rs=rs+"0";
	rs=rs+tmp;
	return rs;
}
string toString(long long k){
	stringstream ss;
	string rs;
	ss<<k;
	ss>>rs;
	return rs;
}
long long toInt(string a){
	stringstream ss;
	long long rs;
	ss<<a;
	ss>>rs;
	return rs;
}
long long make(string k,bool i){
	stringstream ss;
	int j;
	int l;
	long long rs;
	string tmp;
	tmp=k;
	rs=toInt(k);
	if (i==true){
		l=tmp.length()-1;
		if(l>=0)
			for(j=l;j>=0;j--)
				rs=rs*10+(tmp.at((int)j)-'0');
		return rs;
	}
	else
	{
				l=tmp.length()-2;
				if(l>=0)
				{
					for(j=l;j>=0;j--)
						rs=rs*10+(tmp.at((int)j)-'0');
				}
				return rs;

	}
}
