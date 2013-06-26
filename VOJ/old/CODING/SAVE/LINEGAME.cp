#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int n,i;
	cin >>n;
	long long od,ev;
	int tmp;
	scanf("%d",&tmp);
	od=tmp;
	ev=0;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&tmp);
		int tOd=od,tEv=ev;
		ev=max(tOd-tmp,tEv);
		od=max(tEv+tmp,tOd);
	}
	cout<<max(od,ev);

}
