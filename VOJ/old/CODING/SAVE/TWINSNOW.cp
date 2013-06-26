#include <iostream>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <string.h>
using namespace std;
struct snow
{
	int a[7];

	bool operator==(snow b)
	{
		int i;
		for(i=0;i<6;i++)
			if(a[i]!=b.a[i]) return false;
		return true;
	}
	void operator =(snow b){
		for(int i=0;i<6;i++)
			a[i]=b.a[i];
	}
	bool operator<(snow b)
		{

			int i;
			for(i=0;i<6;i++)
			{
				if(a[i]>b.a[i]) return false;
				else if(a[i]<b.a[i]) return true;
			}
			return false;
		}
} l[100005];
int cmp(const void *a, const void *b){
	snow *pa,*pb;
	pa=(snow *)a;
	pb=(snow *)b;
	int i;
	for(i=0;i<6;i++)
	{
		if(pa->a[i] > pb->a[i]) return 1;
		else if(pa->a[i]< pb->a[i]) return -1;
	}
	return 0;
}
int n;
int main()
{
	freopen("input.txt","rt", stdin);
	freopen("output.txt","wt", stdout);
	scanf("%d",&n);
	int minE=7,tmp,pos=-1;
	snow sn1,sn2;
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<6;j++)
		{
			scanf("%d",&tmp);
			l[i].a[j]=tmp;

		}
		minE=10000005;
		for(j=0;j<6;j++){
			if(l[i].a[j]<minE)
				{ minE=l[i].a[j]; pos=j;}
			else if(l[i].a[j]==minE){
				int k;
				for(k=1;k<6;k++){
					if(l[i].a[(j+k)%6]< l[i].a[(pos+k)%6])
					{
						pos=j;
						break;
					}
					else if(l[i].a[(j+k)%6]> l[i].a[(pos+k)%6]) break;
				}
			}
		}
		sn1.a[0]=l[i].a[pos];
		for(j=1;j<=5;j++)
		{	pos=(pos+1)%6;
			sn1.a[j]=l[i].a[pos];
		}
		//swap;
		int tw;
		for(j=0;j<3;j++){
			tw=l[i].a[j];
			l[i].a[j]=l[i].a[5-j];
			l[i].a[5-j]=tw;
		}
		minE=10000005;
		for(j=0;j<6;j++){
			if(l[i].a[j]<minE)
				{ minE=l[i].a[j]; pos=j;}
			else if(l[i].a[j]==minE){
				int k;
				for(k=1;k<6;k++){
					if(l[i].a[(j+k)%6]< l[i].a[(pos+k)%6])
					{
						pos=j;
						break;
					}
					else if(l[i].a[(j+k)%6]> l[i].a[(pos+k)%6]) break;
				}
			}
		}
		//Hoan vi lai.
		sn2.a[0]=l[i].a[pos];
		for(j=1;j<=5;j++)
		{	pos=(pos+1)%6;
			sn2.a[j]=l[i].a[pos];
		}

	    if(sn2<sn1)
	    	l[i]=sn2;
	    else l[i]=sn1;

	}
	qsort(l,n,sizeof(l[0]),cmp);


	for(i=0;i<n;i++)
	{
		for(j=0;j<=5;j++)
			cout<<l[i].a[j]<<' ';
		cout<<endl;
	}

	bool found=false;
	for(i=0;i<n-1;i++){
		if(l[i]==l[i+1])
		{
			cout<<"Twin snowflakes found.";
			found=true;
			break;
		}
	}
	if(!found)
		cout<<"No two snowflakes are alike.";
}

