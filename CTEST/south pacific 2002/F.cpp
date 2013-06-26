#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
//#include <conio.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);
#define pb  push_back
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>

double EPS=1e-9;

struct toado{
     int x,y;
     toado(){};
     toado(int _y,int _x){
          x = _x; y = _y;
     }
};

vector<toado> V,V1;
toado S;

char s[333][333];
int f[222][222],m,n,run,chay = 0;
int r[] = {-1,1,0,0};
int c[] = {0,0,-1,1};

void duyet(toado T){
     if(T.x<=0 || T.x>m || T.y<=0 && T.y>n) return;
     if(f[T.y][T.x]>-1) return;
     f[T.y][T.x] = run;
     for(int i = 0;i<4;i++){
          if(s[T.y*2-1+r[i]][T.x*2-1+c[i]]=='.' ){
                
                //printf("%d %d %d %d\n",T.y+r[i],T.x+c[i],T.y*2-1+r[i],T.x*2-1+c[i]);
                V.push_back(toado(T.y+r[i],T.x+c[i]));
          }  
     }
}

int tinh(int u,int v){
     int re = INF;
     if(f[u][v]==-1) return re;
     if(u==1 && s[0][v*2-1]=='.') re = f[u][v]+1;
     if(u==n && s[2*n][v*2-1]=='.') re = f[u][v]+1;
     if(v==1 && s[u*2-1][0] =='.') re = f[u][v]+1;
     if(v==m && s[u*2-1][m*2]=='.') re = f[u][v]+1;
     return re;  
}

int main()
{
  //  freopen("F.IN", "rt", stdin);
  //  freopen("F.OUT", "wt", stdout);      
    while(scanf("%d %d\n",&m,&n)>0 && n>0){
         for(int i = 0;i<=2*n;i++){
              gets(s[i]);
             // printf("%s\n",s[i]);
              
              if(i%2){
                    for(int j = 0;j<=2*m;j++) if(s[i][j]=='s'){
                         S.x = (j+1)/2;
                         S.y = (i+1)/2;                
                    }
              }
         }
         
         V.push_back(S);
         memset(f,-1,sizeof(f));
         
         for(run = 0;;run++)
         {
              if(V.size()==0) break;
              for(int i = 0;i<V.size();i++) V1.push_back(V[i]);
              V.clear();
              for(int i = 0;i<V1.size();i++) duyet(V1[i]);
              V1.clear();
         }
         
         int kq = INF;
         for(int i = 1;i<=n;i++) for(int j = 0;j<=m;j++) kq = min(kq,tinh(i,j));
         if(kq>=INF) printf("Maze %d: No escape!\n",++chay);
         else printf("Maze %d: %d\n",++chay,kq);
    } 
    
  //  getch();      
}

