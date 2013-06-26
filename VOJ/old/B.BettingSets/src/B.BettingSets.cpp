#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m;
double p[105][15];
void solve();
int cmp(const void * a, const void *b){
	double * ia=(double *) a, * ib= (double *)b;
	double rs=*ib-*ia;
	if(rs>0) return 1;
	else return -1;
}
int main() {
	int i,j;
	do
	{
		scanf("%d%d",&n,&m);
		if(n==0 && m==0) break;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++)
			{
				scanf("%lf",&p[i][j]);
			}
		}
		solve();
	}
	while(true);
}
void solve()
{
	int i,j;
	double result=0;
	double set[105];
	double temp[105];
	for(i=1;i<=104;i++)
		set[i]=1.0;
	for(i=1;i<=m;i++){
		//sort lai day cot
		for(j=1;j<=n;j++)
			temp[j-1]=p[j][i];
		qsort(temp,n,sizeof(temp[0]),cmp);
		for(j=1;j<=n;j++)
		{	//cout<<temp[j-1]<<' ';
			set[j]*=temp[j-1];
		}
		//cout<<endl;
	}
	for(i=1;i<=n;i++){
		result+=set[i];
	}
	printf("%.4f\n",result);


}
