//============================================================================
// Name        : HOUSES.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
int list[101];
int num[21];
int l,n,len;
void print();
void swap(int &a, int &b);
int main() {
	int i,j,t,sum=0,numOfSet=0;
	//input
	scanf("%d%d",&l,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		sum=sum+num[i];
	}

	//khoi tao
	len=(l-sum)+n;
	list[1]=1;
	i=1;
	for(j=1;j<=l-sum;j++)
	{
		list[i+j]=0;
	}
	i=i+j;
	j=2;
	while(i<=len)
	{
		list[i]=j;
		++i;++j;
	}
	do
	{
		print();
		numOfSet++;
		if(numOfSet>=1000) break;
		//tim tu duoi len.
		j=len;
		while(list[j-1]>=list[j]){
			j--;
			if(j==1) break;
		}
		if(j==1) break;
		//Tim list[t], nho nhat lon hon list[j-1];
		t=len;
		while(list[t]<=list[j-1]&& t>j-1) t--;
		swap(list[j-1],list[t]);
		i=j; t=len;
		while(i<t){
			swap(list[i],list[t]);
			i++;t--;
		}
	}
	while(true);

}
void print(){
	int i,j;;
	for(i=1;i<len;i++)
	{
		if(list[i]==0) printf("0 ");
		else{
			for(j=1;j<=num[list[i]];j++)
				printf("%d ",list[i]);
		}
	}
	if(list[i]==0) printf("0");
	else{
		for(j=1;j<num[list[i]];j++)
			printf("%d ",list[i]);
		printf("%d",list[i]);
	}
	printf("\n");
}
void swap(int &a, int &b){
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}
