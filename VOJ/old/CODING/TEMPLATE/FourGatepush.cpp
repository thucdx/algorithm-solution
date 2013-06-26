#include <iostream>
using namespace std;
#include <stdio.h>
long long f[2005][2005];
long long max(long long a, long long b)
{
	if (a>b) return a;
	return b;
}
int main()
{
	long long M,G,Z,S,E;
	long long i,j;
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	do
	{
		cin>>M>>G>>Z>>S>>E;
		if(M==0 && G==0 && Z==0  && S==0 && E==0) break;
		//Qui hoach dong;
		int _m=M/25,_g=G/25;
		for(i=0;i<=_m;++i)
			for(j=0;j<=_g;++j)
			{
				f[i][j]=0;
			}
		for(i=0;i<=_m;++i){
			for(j=0;j<=_g;++j)
			{
				//f[i][j]=
				//truong hop 1.
				if(i>=4) 			f[i][j]=max(f[i][j],f[i-4][j]+Z );
				if(i>=5 && j>=2) 	f[i][j]=max(f[i][j],f[i-5][j-2]+S );
				if(i>=2 && j>=4)    f[i][j]=max(f[i][j],f[i-2][j-4]+E);
			}
			//cout<<i<<' '<<j<<' '<<f[i][j];
		}
		cout<<f[_m][_g]<<endl;
	}
	while(true);

}
