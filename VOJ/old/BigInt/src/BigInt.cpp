//============================================================================
// Name        : BigInt.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <string.h>
#include <stdio.h>
#include <sstream>

class BigInt{
	static const int sizeMx=10000;
public:
	char * val;

	BigInt(){
		val=new char [sizeMx];
	}
	BigInt(char * v){
		strcpy(val,v);
	}
	void operator =(char *v){
		strcpy(val,v);
	}
	void operator = (BigInt b){
		strcpy(val,b.val);
	}
	void operator = (long long a){
		stringstream ss;
		ss<<a;
		ss>>val;
	}
	void set(char *v){
		strcpy(val,v);
	}
	BigInt operator +(BigInt b){
		BigInt rs;
		strcpy(rs.val,sum(val,b.val));
		return rs;
	}
	char * reverse(char * a){
			int i,len=strlen(a);
			char *rs=new char [strlen(a)+1];
			for(i=0;i<len;i++){
				rs[i]=a[len-1-i];
			}
			rs[i]='\0';
			return rs;
		}
	char * sum(char *a, char *b){
		char *a1,*b1,*rs;
		int len1,len2,i,mem,tmp;
		if(strlen(a)<strlen(b))
		{
			a1=reverse(a);
			b1=reverse(b);
		}
		else {
			a1=reverse(b);
			b1=reverse(a);
		}
		//a1<b1;
		len1=strlen(a1);
		len2=strlen(b1);
		mem=0;
		rs=new char [len2+2];
		for(i=0;i<len1;i++){
			tmp=a1[i]+b1[i]-('0'<<1)+mem;
			rs[i]=tmp%10+'0';
			mem=tmp/10;
		}
		for(i=len1;i<len2;i++){
			tmp=b1[i]+mem-'0';
			rs[i]=tmp%10+'0';
			mem=tmp/10;
		}
		if(mem>0)
		{
			rs[i]=mem+'0';
			i++;
		}
		rs[i]='\0';
		return reverse(rs);

	}
	friend istream & operator>>(istream &is,BigInt &b){
			char tmp[sizeMx];
			is >> tmp;
			strcpy(b.val,tmp);
			return is;
	}
	friend ostream & operator<<(ostream & os, BigInt a){
			os << a.val;
			return os;
	}
};

int main() {
	/*
	char a[1000];
	char b[1000];
	scanf("%s",a);
	scanf("%s",b);
	cout<<sum(a,b)<<endl;
	*/
	BigInt a,b,c;
	cin>>a>>b;
	c=(int)10;
	cout<<(a+b)<<endl;
	cout<<a+c<<endl;
}
/*
char * sum(char *a, char *b){
	char *a1,*b1,*rs;
	int len1,len2,i,mem,tmp;
	if(strlen(a)<strlen(b))
	{
		a1=reverse(a);
		b1=reverse(b);
	}
	else {
		a1=reverse(b);
		b1=reverse(a);
	}
	//a1<b1;
	len1=strlen(a1);
	len2=strlen(b1);
	mem=0;
	rs=new char [len2+2];
	for(i=0;i<len1;i++){
		tmp=a1[i]+b1[i]-('0'<<1)+mem;
		rs[i]=tmp%10+'0';
		mem=tmp/10;
	}
	for(i=len1;i<len2;i++){
		tmp=b1[i]+mem-'0';
		rs[i]=tmp%10+'0';
		mem=tmp/10;
	}
	if(mem>0)
	{
		rs[i]=mem+'0';
		i++;
	}
	rs[i]='\0';
	return reverse(rs);

}
char * reverse(char * a){
	int i,len=strlen(a);
	char *rs=new char [strlen(a)+1];
	for(i=0;i<len;i++){
		rs[i]=a[len-1-i];
	}
	rs[i]='\0';
	return rs;
}
*/
