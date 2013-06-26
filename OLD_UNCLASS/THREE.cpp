#include <iostream>
#include <cstdio>
#define INF 10000000
using namespace std;


int edge[105][105],bet[105][105],num[105][105],n,m,verMin,minDis;
bool d[20005];

void trace(int x, int y);
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
    {
        edge[i][j]= INF;   
    }
    for(int i=1,a,b,dis;i<=m;i++)
    {
            scanf("%d%d%d",&a,&b,&dis);
            if(dis<edge[a][b])
            {
                edge[a][b]=edge[b][a]=dis;
                num[a][b]=num[b][a]=i;    
            }
    }
    //Floy
    

    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    for(int t=1;t<=n;t++)    
    {
        if(edge[i][j]> edge[i][t]+edge[t][j])
        {
            edge[i][j]=edge[i][t]+edge[t][j];
            bet[i][j]=t;
            bet[j][i]=t;
        }   
    }
    for(int i=1;i<=n;i++)
        edge[i][i]=0;
    //Tim diem;
    minDis=INF;
    for(int i=1;i<=n;i++)
    {
            if(edge[i][1]+edge[i][2]+edge[i][3]< minDis)
            {
                   minDis= edge[i][1]+edge[i][2]+edge[i][3];
                   verMin=i;
            }
    }
    //cout<<minDis<<" "<<verMin<<" (minDis _ verMin)"<<endl;
    trace(verMin,1);
    trace(verMin,2);
    trace(verMin,3);
    int nEdge=0;
    for(int i=1;i<=m;i++)
    {
        nEdge+=d[i];    
    }
    printf("%d\n%d\n",minDis,nEdge);
    for(int i=1;i<=m;i++)
    {   
        if(d[i])
        printf("%d ",i);    
    }
}
void trace(int x, int y)
{
    if (x==y) return;
    int k=bet[x][y];    
    if(k==0) //canh
    {
        d[num[x][y]]=true;
        return  ;
    }
    trace(x,k);
    trace(k,y);
}
