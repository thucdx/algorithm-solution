#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n;
double d, r[16];
double rs[(1<<17)][16];
void calc();
int main(){
	//freopen("input.txt","rt", stdin);
	//freopen("output.txt","wt", stdout);
	int i;
	do
	{
		cin>>n;
		if(n==0) break;
		cin>>d;
		for(i=0;i<n;i++)
		{
			cin>>r[i];
		}
		calc();
	}
	while(true);
	return 0;
}
void calc()
{
	int lim=(1<<n)-1;
	int i,j,k,t;
	for(i=0;i<=lim;i++)
		for(j=0;j<n;j++)
		rs[i][j]=1000000;
	for(i=0;i<n;i++)
	{
		rs[1<<i][i]=2*r[i];
	}
	for(i=0;i<n;i++)
		rs[0][i]=0;
	for(i=1;i<=lim;++i){
		for(j=0;j<n;j++){
			if((i &(1<<j))!=0)//bit thu j cua i la 1
			{	//cap nhat
				double tmp;
				k=i-(1<<j);
				if(k==0) continue;
				else
				for(t=0;t<n;t++){
					if((k&(1<<t))!=0) //bit thu t cua k la 1.
					{
						tmp=rs[k][t]-r[t]+sqrt(d)*sqrt(2*(r[t]+r[j])-d)+r[j];
						//cout<<"____"<<tmp<<endl;
						if(tmp<rs[i][j]) rs[i][j]=tmp;
						//tmp=rs[k]-r[t]+2.0*sqrt(r[t]*r[j])+r[j];
						//if(tmp<rs[i]) rs[i]=tmp;
					}

				}
			}
		}
		//cout<<i<<' '<<rs[i]<<endl;
	}
	double rsMin=1000000;
	for(i=0;i<n;i++){
		if(rsMin>rs[lim][i]) rsMin=rs[lim][i];
	}
	cout<<(int)(rsMin+1.0/2)<<endl;
}



