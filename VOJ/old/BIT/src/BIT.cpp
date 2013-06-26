//============================================================================
// Name        : BIT.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define max 100000
int n,m,i;
int a[max+1];
int T[max+1];
void init();
void input();
void update(int i,int v);
int getSum(int i);
int main() {
	init();
	input();

}
void init(){
	for(i=0;i<=max;++i)
	{
		a[i]=T[i]=0;
	}
}
void input(){
	int u,v;
	cin>>n>>m;
	//Doc tung thao tac.
	for(i=1;i<=m;++i){
		cin>>u>>v;
		update(u,v);
	}
	//Doc cach tinh.
	//
	for(i=1;i<=n;++i)
		cout<<a[i]<<endl;
	int nTest;
	cout<<"So thao tac"<<endl;
	cin>>nTest;
	for(i=1;i<=nTest;++i){
		cin>>u>>v;
		cout<<(getSum(v)-getSum(u-1))<<endl;
	}

}
void update(int i, int v){
	//int dis=v-a[i];
	int j=i;
	while(i<=n){
		T[i]=T[i]+v-a[j];
		i=i+(i&(-i));//nut cha cua no
	}
	a[j]=v;
}
int getSum(int i){
	int rs=0;
	while(i>0){
		rs+=T[i];
		i=i-(i&(-i));
	}
	return rs;
}
