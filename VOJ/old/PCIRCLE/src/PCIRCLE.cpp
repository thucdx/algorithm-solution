//============================================================================
// Name        : PCIRCLE.cpp
// Author      : ThucDX
// Version     :
// Copyright   : PCIRCLE
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
int rs[10000][21];
int list[21];
int k=0;
int n;
using namespace std;
void att(int );
void result();
bool isPrime(int);
bool flag[21];
bool prime[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0}; //2=>39.
void initial();
int main() {
	cin >>n;
	initial();
	att(1);
	result();
	return 0;
}
void initial(){
	int i;
	for(i=0;i<=2*n;i++)
	{
		flag[i]=true;
		list[i]=0;
	}
	list[0]=1;
}
bool isPrime(int p){
	/*
	if(p<2) return false;
	if (p==3||p==2) return true;
	int i;
	if(p%2==0) return false;
	for(i=3;i*i<=p;i=i+2){
		if(p%i==0) return false;
	}
	return true;
	*/
	if(prime[p]==1) return true;
	else return false;
}
void att(int i){
	if(i==2*n)//in ra
	{	//cout<<"reach!";
		if(isPrime(list[2*n-1]+list[0])){
			//ok
			//cout<<"# "<<k<<':';
			k++;
			if(k<10001)
				for(int j=0;j<2*n;j++)
				{
					///cout<<list[j];5
					rs[k-1][j]=list[j];
				}
		}
		return;
	}
	//i <n;
	int j;
	for(j=2;j<=2*n;j++){
		if(flag[j]){ //j chua co trong day
			if(isPrime(j+list[i-1]))
			{
				//chon
				flag[j]=false;
			    list[i]=j;
				att(i+1);
				flag[j]=true;
			}
		}
	}
}
void result(){
	printf("%d\n",k);
	int i,j;
	int m=(k<10001? k: 10001);
	for(i=0;i<m;i++){
		for(j=0;j<2*n;j++)
		{
			printf("%d ",rs[i][j]);

		}
		printf("\n");
	}
}
