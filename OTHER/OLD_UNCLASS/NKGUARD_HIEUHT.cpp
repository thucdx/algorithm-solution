#include <stdio.h>
#include <conio.h>

int n,m,a[701][701],KQ=0;
bool free[701][701],d[701][701];


bool tm(int a,int b)
{
    return (a>=1 && a<=n && b>=1 &&b<=m);     
}

int DFS(int x,int y)
{
    if(d[x][y] == false) return 0;
    else if(!free[x][y]) return 1;
    else
    {
        free[x][y]=false;
        int K = 1;
        for(int i = -1;i<=1;i++)
              for(int j = -1;j<=1;j++)
                   if((i!=0 || j!=0) && tm(x+i,y+j) && a[x][y]==a[x+i][y+j]) K = K&DFS(x+i,y+j);
        return K;
    }
}
           
int main()
{
    freopen("NKGUARD.in","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            free[i][j] = true;
            d[i][j]=true;
        }
    for(int x = 1;x<=n;x++)
        for(int y = 1;y<=m;y++)
           for(int i = -1;i<=1;i++)
           for(int j = -1;j<=1;j++)
           {
                if(i==0 &&j==0) continue;
                else
                {
                    if(tm(x+i,y+j) && a[x][y]<a[x+i][y+j])
                        d[x][y] = false;
                }
           }
                         
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            if(free[i][j])
            {
                KQ = KQ+DFS(i,j);
                printf("%d %d %d\n",i,j,KQ);
            }
    printf("%d",KQ);
    getch();
}

