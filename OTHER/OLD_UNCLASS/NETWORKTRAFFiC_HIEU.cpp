#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<iterator>
#include<iostream>
#include<cctype>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
//#include<conio.h>
#define ep 0.000000001
#define maxn 10011
#define oo 1111111111
#define modunlo 111539786
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
double const PI=4*atan(1);

using namespace std;

typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;

struct canh{
     int id,gt;
     canh(){};
     canh(int _id, int _gt){
          id = _id;
          gt = _gt; 
     }
};

struct doan{
     int chiso,gt;
     doan(){};
     doan(int _chiso,int _gt){
          chiso = _chiso;
          gt = _gt; 
     }
     bool operator <(const doan D)const{
          return gt<D.gt;
     }  
};

set<doan> S1,S2;
set<doan>::iterator it;
int f1[111111],f2[111111];
vector<vector<canh> > V1,V2;
int n,m,k,s,t,test;
int x,y,c,u,v,uu,vv;

int main(){
    
    // freopen("TRAFFICN.in","r",stdin);
     
     scanf("%d",&test);
     for(int itest = 1;itest<=test;itest++){
     
     scanf("%d %d %d %d %d",&n,&m,&k,&s,&t);
     V1.clear(); V2.clear();
     V1.resize(n+3); V2.resize(n+3);
     memset(f1,-1,sizeof(f1));
     memset(f2,-1,sizeof(f2));
     
     for(int i = 0;i<m;i++){
          scanf("%d %d %d",&x,&y,&c);
          V1[x].push_back(canh(y,c));
          V2[y].push_back(canh(x,c));
     }

     S1.clear();  
     S1.insert(doan(s,0));
     while(S1.size()){
          it = S1.begin();
          u = (*it).chiso;
          v = (*it).gt;
          S1.erase(S1.begin());
          if(f1[u]==-1){
               f1[u] = v;
               TR(V1[u],it){
                    uu = (*it).id;
                    vv = (*it).gt;
                    if(f1[uu]==-1){
                         S1.insert(doan(uu,v+vv));
                    }
               }
          }
     }     
     
     S2.clear();
     S2.insert(doan(t,0));
     while(S2.size()){
           it = S2.begin();
           u = (*it).chiso;
           v = (*it).gt;
           S2.erase(S2.begin());
           if(f2[u]==-1){
                f2[u] = v;
                TR(V2[u],it){
                     uu = (*it).id;
                     vv = (*it).gt;
                     if(f2[uu]==-1) S2.insert(doan(uu,v+vv));
                }
           }
     }
     
    // for(int i = 1;i<=n;i++) printf("%d %d\n",f1[i],f2[i]);
     
     int kq = oo;
     if(f1[t]!=-1) kq = f1[t];
     for(int i = 0;i<k;i++){
           scanf("%d %d %d",&x,&y,&c);
           if(f1[x]!=-1 && f2[y]!=-1) kq = min(kq,f1[x]+f2[y]+c);
           if(f1[y]!=-1 && f2[x]!=-1) kq = min(kq,f1[y]+f2[x]+c);
     }
     
     if(kq<oo) printf("%d\n",kq);
     else printf("-1\n");
     
     }
    // getch();
}

