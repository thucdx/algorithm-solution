#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<bitset>
#include<functional>

using namespace std;

int n,x,y,z,f[100010];
long long cnt[100010],ans;

int fa(int k)
{
	if (f[k]==k) return k; return f[k]=fa(f[k]);
}

bool lucky(int k)
{
	if (!k) return false;
	while(k)
	{
		int t=k%10;
		k/=10;
		if (t!=4&&t!=7) return false;
	}
	return true;
}

int main()
{
	//freopen("e.in","r",stdin);
    freopen("input.txt", "rt", stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if (!lucky(z)) f[fa(x)]=fa(y);
	}
	for(int i=1;i<=n;i++) cnt[fa(i)]++;

    for(int i = 1; i <= n; i++) cout<<i<<" "<<cnt[i]<<endl;
	for(int i=1;i<=n;i++) ans+=cnt[i]*(n-cnt[i])*(n-cnt[i]-1);
	cout<<ans<<endl;

	return 0;
}
