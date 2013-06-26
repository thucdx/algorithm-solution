#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;
double m[10005],f[10005];
int n;
double z;
bool isOk();
int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int i;
	scanf("%lf %lf %d",&f[0],&m[0],&n);
	for(i=1;i<=n;i++){
		scanf("%lf %lf",&f[i],&m[i]);
	}
	double head=0,tail=100000000;
	while(tail-head>1E-6){
		z=(head+tail)/2;
		if(isOk()) head=z;
		else tail=z;
	}
	if(fabs(f[0]/m[0]-z)<1e-6)
	{
		cout<<"NONE";
		return 0;
	}
	for(i=1;i<=n;i++){
		if(f[i]/m[i]>=z)
			printf("%d\n",i);
	}


}
bool isOk(){
	int i;
	double u=f[0],v=m[0];
	for(i=1;i<=n;i++){
		if(f[i]/m[i]>z){
			u+=f[i];
			v+=m[i];
		}
	}
	if(u/v>z) return true;
	else return false;

}
