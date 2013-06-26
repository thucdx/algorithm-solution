//============================================================================
// Name        : PARIGAME.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
#define max 502
int nTest, n;
bool b[max][max];
bool h[max][max];
bool v[max][max];
bool anw[max][max];
void input();
void init();
void calc();

int main() {
	scanf("%d",&nTest);
	for(int i=1;i<=nTest;i++){
		input();
		init();
		calc();
	}
}
void input(){
	int i,j;
	int a;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a);
			if(a%2==0) b[i][j]=0;
			else b[i][j]=1;
		}
	}
}
void init(){
	//Tinh h[][] ,v[][]
	int i,j;
	for(i=0;i<n;i++)
	{
		h[i][0]=b[i][0];
		v[0][i]=b[0][i];
		for(j=1;j<n;j++){
			h[i][j]=h[i][j-1]^b[i][j];
			v[j][i]=v[j-1][i]^b[j][i];
		}
	}
	/*
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<i<<' '<<j<<' '<<h[i][j]<<' '<<v[i][j]<<"|    ";
		}
		cout<<endl;
	}
	*/
	//h[i][j] =0 neu tong chan, =1 neu tong le.
}
void calc(){
	int i,j;
	for(i=0;i<n;i++)
		anw[0][i]=!h[0][i];
	for(i=0;i<n;i++)
		anw[i][0]=!v[i][0];
	for(i=1;i<n;i++)
		for(j=1;j<n;j++){
			//tinh anw[i][j]
			/*
			if(h[i][j] && v[i][j]) {anw[i][j]=false;continue;} //ca 2 le
			if(h[i][j] && !v[i][j]) { anw[i][j]=!anw[i][j-1];continue;}//dong le, cot chan.
			if(!h[i][j] && v[i][j]) { anw[i][j]=!anw[i-1][j];continue;} //dong chan, cot le. !0 &&1
			if(!h[i][j] && !v[i][j]) { anw[i][j]=(!anw[i][j-1]) ||(!anw[i-1][j]);continue;}//dong chan, cot chan
			*/
			if(h[i][j]){
				if(v[i][j]) anw[i][j]=false;
				else  anw[i][j]=!anw[i][j-1];
			}
			else
			{
				if(v[i][j]) anw[i][j]=!anw[i-1][j];
				else anw[i][j]=(!anw[i][j-1]) ||(!anw[i-1][j]);
			}

		}
	/*
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++){
			cout<<"( "<<i<<','<<j<<")= ";
			bool a=anw[i][j];
			if(a==true) cout<<"YES";
				else cout<<"NO";
			cout<<" ";
		}
		cout<<endl;
	}
	*/
	bool a=anw[n-1][n-1];
	if(a==true) cout<<"YES\n";
	else cout<<"NO\n";
}

