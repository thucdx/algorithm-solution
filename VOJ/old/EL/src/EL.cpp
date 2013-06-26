#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m;
int result=0;
int list[105];
int cmp(const void * a,const void * b){
	int *ia= (int*) a;
	int *ib= (int *)b;
	return (*ib-*ia); //sort nguoc
}


int main() {
	int i;

	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&list[i]);
	}
	//Tinh toan.
	do
	{
		qsort(list,n,sizeof(list[0]),cmp);
		//tu 0 dem m-1 giam di 1.
		if(list[0]==1){
					int add=0;
					for(i=0;i<=m;i++)
					{
						if(list[i]==1)
							++result;
						else break;

					}

		}
		else result+=m;
		for(i=0;i<m;i++)
			--list[i];
	}
	while(list[0]!=0);
	printf("%d\n",result);
}
