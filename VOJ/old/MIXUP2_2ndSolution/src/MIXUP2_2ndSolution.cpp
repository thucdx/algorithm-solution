#include <iostream>
#include <stdio.h>
long long f[66000][17];
#define INF 9223372036854775807
int n,k;
int cow[17];
using namespace std;
void input();
void calc();
int main() {
	input();
	calc();
}
void input(){
	int i;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",&cow[i]);
}
void calc(){
	int i,j,t;
	int dis;
	int max=(1<<n)-1;
	for(i=0;i<=max;++i)
		for(j=0;j<n;++j)
			f[i][j]=0;
	for(j=0;j<n;++j){
			f[1<<j][j]=1;
	}
	for(i=1;i<=max;++i){
		for(j=0;j<n;++j){
			if((i&(1<<j))!=0)//bit thu j cua i la 1
			{
				if(i==(1<<j))
				{
					continue;
				}
				//f[i][j]=0;
				for(t=0;t<n;t++){
					if(((i&(1<<t))!=0) && (t!=j))
					{
						dis=cow[j]-cow[t];
						if (dis<0) dis=-dis;
						//cout<<"dis: "<<dis<<' '<<j<<' '<<t<<endl;
						if(dis>k)
						{	//cout<<"dis: "<<dis<<' '<<j<<' '<<t<<endl;
							//cout<<"f prev"<<(i&(~(1<<t)))<<' '<<t<<' '<<f[i&(~(1<<t))][t]<<endl;
							f[i][j]+=f[i&(~(1<<j))][t];
							//cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
						}
					}
				}
			}
		}
	}
	long long result=0;
	for(i=0;i<n;++i)
	{
		result+=f[max][i];
		//cout<<f[max][i]<<' '<<i<<endl;
	}
	cout<<result<<endl;
}
