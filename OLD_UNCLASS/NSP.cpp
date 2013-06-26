#include<iostream>

using namespace std;

int b[1005][1005];
int n,k;
int rock[10005];
int x,y;
bool isOK;
void find(int a);
int victim;
void find(int ax,int ay, int bx, int by);
int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
    {
        scanf("%d",&b[i][j]);    
    }
    for(int i=1;i<=k;++i)
    {
        scanf("%d",&rock[i]);
        find(rock[i]);
    }
    return 0;    
}
void find(int a)
{
     x=-1;y=-1;
     victim=a;
     isOK=false;   
     find(1,1,n,n);
     if(isOK) {
            printf("%d %d\n",x,y);
    }
    else printf("Not found\n");
}
void find(int ax, int ay, int bx, int by)
{   
    //cout<<ax<<" "<<ay<<" "<<bx<<" "<<by<<endl;
    if(isOK) return ; //da tim thay, khong tim nua
    if(ax>bx || ay>by) return;
    if(bx==ax && by==ay )
    {   
        if(b[ax][ay]==victim)
        {
            x=ax;
            y=ay;    
            isOK=true;
        }
        return;
    }
    
    int midx=(ax+bx)/2, midy=(ay+by)/2;
    if(b[midx][midy]>=victim)
    {
        find(ax,ay,midx,midy);    
    }    
    else 
    {   
                find(midx+1,ay,bx,by);
                find(ax,midx+1,bx,by);   
    }
}

