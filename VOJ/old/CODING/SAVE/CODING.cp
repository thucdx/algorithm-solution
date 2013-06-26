#include <iostream>
#include <stdio.h>
#include <climits>
using namespace std;
int n;
int a[2005];
int f[2005][2005];
int w[2005][2005];
int k[2005][2005];

int main() {
	int i,j,t,c,d;
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	cin>>n;
	a[0]=0;
	for(i=1;i<=n;i++){
		cin>>c;
		a[i]=a[i-1]+c;
		//cout<<a[i]<<' ';
	}
	//cout<<endl;
	//khoi tao w[i][j]
	for(i=1;i<=n;i++)
	for(j=i;j<=n;j++){
		w[i][j]=a[j]-a[i-1];
		f[i][j]=10000000;
	}
	for(i=1;i<=n;i++)
	{
		k[i][i]=i;
		f[i][i]=0;
	}

	for(d=2;d<=n;d++)
		for(i=1;i<=n-d+1;i++){
			j=i+d-1;
			for(t=k[i][j-1];t<=k[i+1][j];t++){
				int tmp= w[i][j]+f[i][t-1]+f[t][j];
				if (tmp<f[i][j] ){
					f[i][j]=tmp;
					k[i][j]=t;
				}
			}
			cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
		}
	cout<<f[1][n];
}
