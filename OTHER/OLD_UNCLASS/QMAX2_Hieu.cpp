#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
//#include <conio.h>
#define maxn 50000
#define amvocung -2000000000

using namespace std;

int n,m,x,y,gt,hoi,dt[maxn*8],f[maxn*8];

int update(int r,int k,int l,int u,int v,int tang){
     int g;
     if(u>l||v<k) return 0;
     if(u<=k && v>=l){
          dt[r]+=tang;
          return 0;
     }
     dt[2*r] = dt[2*r]+dt[r];
     dt[2*r+1] = dt[2*r+1]+dt[r];
     dt[r] = 0;
     g = (k+l)/2;
     update(2*r,k,g,u,v,tang);
     update(2*r+1,g+1,l,u,v,tang);
     f[r] = max(dt[2*r]+f[2*r],dt[2*r+1]+f[2*r+1]);
}

int getmax(int r,int k,int l,int u,int v){
     int g,t1,t2;
     if(u>l||v<k) return amvocung;
     if(u<=k && v>=l){
          dt[2*r] = dt[2*r]+dt[r];
          dt[2*r+1] = dt[2*r+1]+dt[r];
          dt[r] = 0;
          f[r] = max(dt[2*r]+f[2*r],dt[2*r+1]+f[2*r+1]);
          return f[r];
     }
     g = (k+l)/2;
     dt[2*r] += dt[r];
     dt[2*r+1] += dt[r];
     dt[r] = 0;
     t1 = getmax(2*r,k,g,u,v);
     t2 = getmax(2*r+1,g+1,l,u,v);
     f[r] = max(dt[2*r]+f[2*r],dt[2*r+1]+f[2*r+1]);
     return max(t1,t2);     
}
int main(){
    //freopen("QMAX2.in","r",stdin);
    scanf("%d %d",&n,&m);
    memset(dt,0,sizeof(dt));
    memset(f,0,sizeof(f));
    for(int i = 1;i<=m;i++){
         scanf("%d",&hoi);
         if(hoi){
              scanf("%d %d",&x,&y);
              printf("%d\n",getmax(1,1,n,x,y));
         }
         else{
              scanf("%d %d %d",&x,&y,>);
              update(1,1,n,x,y,gt);
         }
    }
  //  getch();
}

