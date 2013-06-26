//============================================================================
// Name        : LASCALE.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
int tp[50];
long long mu[50];
int le[19];
int ri[19];
int len;
long long n;
void make(long long n);
void init();
void swap(int *);
void swap(int &a , int &b);
void calc();
int main() {
	init();
	cin>>n;
	make(n);
	swap(tp);
	calc();

}
void calc(){
	int l=0,r=0,i;
	int mem=0,tmp;
	i=1;
	tp[len+1]=0;
	while(i<=len){
		if(tp[i]==2){
			l++;
			le[l]=i-1;
			i++;
			tmp=tp[i];
			tp[i]=(tmp+1+mem)%3;
			//cout<<"tp"<<i<<' '<<tp[i]<<' ';
			mem=(tmp+1+mem)/3;
		}
		else {
			if(tp[i]==1){
				r++;
				ri[r]=i-1;

			}
			i++;
			tmp=tp[i];
			tp[i]=(tmp+mem)%3;
			//cout<<"tp"<<i<<' '<<tp[i]<<' ';
			mem=(tmp+mem)/3;
		}
	}
	if(tp[len+1]==1)
	{
		r++;
		ri[r]=len;
	}
	cout<<l<<" ";
	for(i=1;i<=l;++i)
		cout<<mu[le[i]]<<" ";
	cout<<endl;
	cout<<r<<" ";
	for(i=1;i<=r;++i)
		cout<<mu[ri[i]]<<" ";

}
void swap(int &a , int &b){
	int c;
	c=a;
	a=b;
	b=c;
}
void swap(int *list){
	int size=sizeof(list)/sizeof(int);
	int i=1,j=size;
	while(i<j){
		swap(list[i],list[j]);
		++i;--j;
	}
}
void init(){
	int i;
	mu[0]=1;
	for(i=1;i<=19;++i)
		mu[i]=3*mu[i-1];
}
void make(long long n){
	len=0;
	while(n!=0){
		len++;
		tp[len]=n%3;
		n/=3;
	}
}
