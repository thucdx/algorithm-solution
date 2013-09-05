#include <map>
#include <cstdio>
#include <iostream>
using namespace std;
#define REP(i, b) for(int i=1;i<=b;++i)

const int M = 1005;
map<int,int> m;
int s[M][M],x[M*10],y[M*10],n,k,v,id;

int main(){
	scanf("%d %d",&n, &k);
	REP(i,n) REP(j,n) scanf("%d", &s[i][j]);
	REP(i,k) scanf("%d", &v), m[v]=i;

	map<int,int>::iterator it;
	REP(i,n) REP(j,n) {
		if((it = m.find(s[i][j])) != m.end())
			id = it->second, x[id] = i, y[id] = j;
	}

	REP(i,k) printf("%d %d\n", x[i], y[i]);
}
