//============================================================================
// Name        : MAJSTOR.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
int R,N;


char enemy[51][51];
//char list[]="RSP";//nam dam, keo, giay
int cmp(char a, char b);
char svan[51];
int main() {
	int i,j,GradeA=0,GradeB=0;
	int gS=0,gR=0,gP=0;
	scanf("%d",&R);//so vong
	while(getchar()!='\n');
	scanf("%s",svan);
	scanf("%d",&N);//so dich thu
	for(i=1;i<=N;++i){
		scanf("%s",enemy[i]);
	}
	//tinh
	for(i=0;i<R;++i){
		gR=0;gS=0;gP=0;
		for(j=1;j<=N;++j){

			GradeA += cmp(svan[i],enemy[j][i]);
			switch(enemy[j][i]){
			case 'R':
				gR++;gP+=2;
				break;
			case 'S':
				gS++;gR+=2;
				break;
			case 'P':
				gP++;gS+=2;
				break;
			}
		}
		int max=gP;
		if(max<gS) max=gS;
		if(max<gR) max=gR;
		GradeB+=max;
	}

	cout<<GradeA<<endl;
	cout<<GradeB<<endl;
}
int cmp(char a, char b){
	if (a==b) return 1;
	if(a=='R'&&b=='S') return 2;
	if(a=='S'&&b=='P') return 2;
	if(a=='P'&&b=='R') return 2;

	if(a=='S'&&b=='R') return 0;
	if(a=='P'&&b=='S') return 0;
	if(a=='R'&&b=='P') return 0;

}
