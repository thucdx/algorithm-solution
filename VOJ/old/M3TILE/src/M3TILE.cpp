//============================================================================
// Name        : M3TILE.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
#include <iostream>
#include <stdio.h>
using namespace std;
int n;
void calc();
int G(int );
int F(int);
int main() {
	do{
		scanf("%d",&n);
		if(n==-1) break;
		else calc();
	}while(true);
}
void calc(){
	if(n%2==1) printf("0\n");
	else
	{
		printf("%d\n",F(n));

	}
}
int G(int a){
	if(a==2) return 1;
	else return(F(a-2)+G(a-2));

}
int F(int a){
	if(a==2) return 3;
	else return(2*G(a)+F(a-2));
}
*/
#include <iostream>
#include <stdio.h>
using namespace std;
int n;
void calc();
long long F[30];
long long G[30];
int main(){
	int i;
	F[2]=3;
	G[2]=1;
	for(i=4;i<=30;i=i+2){
		G[i]=F[i-2]+G[i-2];
		F[i]=2*G[i]+F[i-2];
	}
	do{
		scanf("%d",&n);
		if(n==-1) break;
		if(n%2==1||n==0) printf("0\n");
		else printf("%lld\n",F[n]);
	}
	while(true);


}
