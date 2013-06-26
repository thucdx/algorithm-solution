//============================================================================
// Name        : VBGRASS.cpp
// Author      : ThucDX
// Version     :
// Copyright   : VBGRASS
// Description : Hello World in C++, Ansi-style
//============================================================================

int n,m;
char g[100][100];
bool f[100][100];
#include <iostream>
#include <stdio.h>
using namespace std;
void input();
void count();
void initial();
int main() {
	input();
	initial();
	count();
	return 0;
}
void initial()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			f[i][j]=true;
}
void input(){
	int i,j;
	scanf("%d%d",&n,&m);
	while(getchar()!='\n');//fflush(stdin);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%c",&g[i][j]);
		}
		getchar();
	}

}
void count(){
	int i,j;
	int num=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			bool isOk=true;
			if(g[i][j]=='#'){
				if(j+1<m)
					if (g[i][j+1]=='#') { num++; f[i][j+1]=false;isOk=false;}
				if(i+1<n)
					if(g[i+1][j]=='#')  { num++;f[i+1][j]=false;isOk=false;}
				if(isOk && f[i][j])
				{
					num++;
					//cout<<i<<' '<<j<<endl;
				}

			}
		}
	printf("%d\n",num);
}
