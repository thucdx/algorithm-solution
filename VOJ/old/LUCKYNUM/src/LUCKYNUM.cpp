//============================================================================
// Name        : LUCKYNUM.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
int f[205];//111...1 chia cho m
int dece[205];//10^n chia cho m.
int m;
void init();
void calc();
bool check(int j,int i);
int main() {
	int i,nTest;
	cin>>nTest;
	for(i=1;i<=nTest;i++){
		scanf("%d",&m);
		init();
		calc();
	}

}
void init(){
	int i;
	f[0]=0;
	f[1]=1;
	for(i=2;i<=200;++i)
		f[i]=(10*f[i-1]+1)%m;
	dece[0]=1;
	dece[1]=10%m;
	for(i=2;i<=200;++i)
		dece[i]=10*dece[i-1]%m;
}

void calc(){
	int i,j;
	for(i=1;i<=200;i++){
		//So co i chu so.
		for(j=0;j<=i;++j){
			if(check(j,i)){
				//in ra.
				i=i-j;
				j--;
				i--;
				while(j>=0){
					printf("8");
					--j;
				}
				while(i>=0){
					printf("6");
					--i;
				}
				printf("\n");
				return;
			}
		}
	}
	printf("-1\n");
}

bool check(int j,int i){
	//cout<<"CHeck with "<<j<<' '<<i<<' '<<m<<endl;
	//j so dau la 8. cac so con lai la 6
	//cout<<f[j]<<' '<<dece[i-j]<<' '<<f[i-j]<<endl;
	//cout<<"SO="<<(8*f[j]*dece[i-j]+6*f[i-j])<<endl;
	int num=(8*f[j]%m*dece[i-j]%m+6*f[i-j]%m)%m;
	if(num==0) return true; else return false;
}
