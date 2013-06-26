#include <iostream>
using namespace std;
#include <stdio.h>
#define max 100005
int l,r;
void init();
int sum[max];

int main(){
	scanf("%d%d",&l,&r);
	init();
	int i,num=0;
	for(i=l;i<=r;i++)
	if(sum[i]>i ) num++;
	printf("%d\n",num);
}
void init(){
	int i,j;
	int limit=r/2+1;
	for(i=1;i<=r;i++)
		sum[i]=1;
	for(i=2;i<=limit;i++){
		j=i*2;
		while(j<=r){
			sum[j]+=i;
			j+=i;
		}
	}
}
