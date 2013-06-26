#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>

struct TribeWords
{
	string w;
	int nA;
	int nB;
	int val;
};

TribeWords wds[55];
int n, x,y,z;
size_t trace[55];
int rs[51][51][51];

int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	cin>>n;
	cin>>x>>y>>z;
	string tmp;
	int _val;
	for(int i=1;i<=n;i++){
		cin>>tmp;
		cin>>_val;
		wds[i].w=tmp;
		wds[i].val=_val;
		//tinh wds[i].nA,wds[i].nB;
		for(int j=0;j<(wds[i].w).length();j++)
			if(wds[i].w[j]=='a')
				wds[i].nA++;
		wds[i].nB=wds[i].w.length()-wds[i].nA;

	}
	//Qui hoach dong
	for(int i=0;i<=x;i++)
		for(int j=0;j<=y;j++)
			for(int k=0;k<=z;k++)
			{
				for(int t=1;t<=n;t++){
					if(i>= wds[t].nA  && j>=wds[t].nB) //co the them bot duoc
					{
						if(k==0){
							if (wds[t].val > rs[i][j][k])
							{
								rs[i][j][k]=wds[t].val;
								trace[0]=t;
							}
						}
						else
						{
							if(rs[i-wds[t].nA][j-wds[t].nB][k-1]+wds[t].val > rs[i][j][k])
							{
								rs[i][j][k]=rs[i-wds[t].nA][j-wds[t].nB][k-1]+wds[t].val;
								trace[k]=t;
							}

						}
					}
				}
			}
	cout<<"VALUE "<<rs[x][y][z]<<endl;
	int list[51];
	int nSpace=0;
	int _x=x,_y=y,_z=z;
	for(int i=z;i>=0;i--){
		_x-=wds[trace[i]].nA;
		_y-=wds[trace[i]].nB;
		list[z-i]=trace[i];
		nSpace=z-i;
		if (rs[_x][_y][i]==0) break;
	}
	for(int i=0;i<=nSpace;i++){
		cout<<list[i]<<' ';
	}

	/*
	for(int i=z;i>=1;i--){
		if(trace[i]==0) break;
		cout<<trace[i]<<' ';
		cout<<wds[trace[i]].w<<' ';
	}
	*/
	//Trace lai
	/*
	int list[51];
	int _x=x,_y=y,_z=0;
	for(int i=z;i>=1;i--){
		if(trace[i]==0) break;
		_z++;
		list[_z]=trace[i];
		_x-= wds[trace[i]].nA;
		_y-= wds[trace[i]].nB;
	}
	cout<<_x<<' '<<_y<<endl;
	int maxVal=0,pos=-1;
	for(int i=1;i<=n;i++){
		if(wds[i].nA>=_x && wds[i].nB>=_y && wds[i].val>maxVal)
		{
			maxVal=wds[i].val;
			pos=i;
		}
	}
	if(pos!=-1){
		_z++;
		list[_z]=pos;
	}
	for(int i=1;i<=_z;i++)
	{
		cout<<list[_z]<<' ';
	}
	*/


}
