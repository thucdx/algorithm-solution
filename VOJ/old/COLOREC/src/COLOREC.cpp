//============================================================================
// Name        : COLOREC.cpp
// Author      : ThucDX
// Version     :
// Copyright   : COLOREC
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
#define max 400
int table[max][max];
int t[]={1,2,4,8};
int n;
inline void input();
inline void init();
inline void count();
int main() {
	init();
	input();
	count();
}
void init(){
	int i,j;
	for(i=0;i<max;i++)
		for(j=0;j<max;j++)
			table[i][j]=0;
}
void input()
{	int i,x,y,color;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d",&x,&y,&color);
		table[x+200][y+200]=t[color-1];
	}
}
void count(){
	int num=0;
	int s[19];
	int i,j,k;
	for(i=0;i<max-1;++i)
		for(j=i+1;j<max;++j)
		{//chon 2 cot i,j
			//khoi tao mang.
			for(k=0;k<=18;k++)
				s[k]=0;
			for(k=0;k<max;k++){
				int a=table[k][i];
				int b=table[k][j];
				if(a==0 ||b==0 ||(a==b)) continue;
				++s[a+b];
			}
			num+=s[3]*s[12]+ s[5]*s[10]+s[9]*s[6];
		}
	cout<<num<<endl;
}
