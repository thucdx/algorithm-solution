//============================================================================
// Name        : PTRANG.cpp
// Author      : ThucDX
// Version     : 1.0
// Copyright   : PTRANG
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int n, l;
int list[6000];
int sLine=0;//position of the word beggining of line
int result=1001; //min cua cac max.
int max=1001;
int lLine=0;
void input();
void att(int);
int main() {

}
void input(){
	cin>>n>>l;
	int i;
	for(i=0;i<n;i++)
		cin>>list[i];
}
void att(int i){
	int j;
	int save_sLine;
	int save_lLine;
	save_lLine=lLine;
	save_sLine=sLine;
	if(i==n) //save ket qua
	{
		if(max<result) result=max;
	}
	if(lLine+list[i]>l){ //sang trang khac
		sLine=i;//i la dau dong
		lLine=list[i];
		att(i+1);
		sLine=save_sLine;
		lLine=save_lLine;
	}
	else{ //co the them vao hoac khong.!
		if(lLine<)
	}
}
