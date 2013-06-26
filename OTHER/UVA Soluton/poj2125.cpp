#include<stdio.h>
#include<string.h>

#define INF		0x3fffffff
#define S		0
#define T		N
#define	MaxN	202

int n, m, N;
int G[MaxN][MaxN];

void readr()
{
	scanf("%d%d", &n, &m);
	N = 2 * n + 1;
	int i, u, v;
	memset(G, 0, sizeof(G));
	for(i = 1; i <= n; ++i)
    {
		scanf("%d", &v);
		G[i*2][T] = v;
	}
	for(i = 1; i <= n; ++i) 
    {
		scanf("%d", &v);
		G[S][i*2-1] = v;
	}
	for(i = 1; i <= m; ++i)
    {
		scanf("%d%d", &u, &v);
		G[u*2-1][v*2] = INF;
	}
}

int F[MaxN][MaxN], pnt[MaxN], open[MaxN], d[MaxN], mk[MaxN];

int maxflow()
{
	int cur, tail, i, j, u, v, flow=0; memset(F,0,sizeof(F));
	do{ memset(mk,0,sizeof(mk)); memset(d,0,sizeof(d));
		open[0]=S;mk[S]=1;d[S]=INF;
		for(pnt[S]=cur=tail=0;cur<=tail&&!mk[T];cur++)
			for(u=open[cur],v=0;v<=N;v++)if(!mk[v]&&F[u][v]<G[u][v]){
				mk[v]=1; open[++tail]=v; pnt[v]=u;
				if(d[u]<G[u][v]-F[u][v])d[v]=d[u];
					else d[v]=G[u][v]-F[u][v];
			}
		if(!mk[T])break; flow+=d[T];
		for(u=T;u!=S;){v=u;u=pnt[v];F[u][v]+=d[T]; F[v][u]=-F[u][v];}
	}while(d[T]>0); return flow;
}

void dfsvis( int u ) 
{
	mk[u]=1 ;
	for(int v = 0; v <= N; ++v) if( F[u][v]<G[u][v] && !mk[v] )
		dfsvis(v);
}

void solvr ()
{
	int ans = maxflow();
	printf("%d\n",ans);
	memset(mk, 0, sizeof(mk));
	dfsvis(S);
	int i, times = 0;
	for(i = 1; i <= n; ++i)
	{
		if( !mk[i*2-1] ) ++times;
		if( mk[i*2] ) ++times;
	}
	printf("%d\n",times);
	for(i = 1; i <= n; ++i)
	{
		if( !mk[i*2-1] ) printf("%d -\n", i);
		if( mk[ i*2 ] ) printf("%d +\n", i);
	}
}

int main ()
{
		readr();
		solvr();
}
