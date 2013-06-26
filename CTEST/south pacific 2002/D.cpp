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




char company[111];
vector<vector<int> > V;
vector<int>::iterator it;
char s1[111111][11],s2[111111][11];
//map<string,vector<string> >::iterator it;
map<string,int> m;
int F[111111][2],tien[111111];

int n,x,boss;

int duyet(int u,int co){
   //  printf("%d %d\n",u,co);
     if(F[u][co]>-1) return F[u][co];
   //  printf("%d\n",V[u].size());
     if(V[u].size()==0){
       //   printf("??");  
          if(co) return F[u][co] = tien[u];
          else return F[u][co] = 0;
     }

     int kq = 0;
     if(co){
          kq += tien[u];  
          vector<int>::iterator it;
          for(it = V[u].begin(); it!=V[u].end();it++) 
                kq+= duyet(*it,0);
     }
     else{
            
          vector<int>::iterator it;  
          for(it = V[u].begin(); it!=V[u].end();it++)
                kq+= max(duyet(*it,0),duyet(*it,1));   
                   
     }
     
     return F[u][co] = kq;
}

int main()
{
   // freopen("D.IN", "rt", stdin);
   // freopen("D.OUT", "wt", stdout);   
    while(gets(company) && company[0]!='#'){
    
         scanf("%d",&n);
         memset(F,-1,sizeof(F));
         V.clear();
         V.resize(n+2);
         for(int i = 0;i<n;i++){
              scanf("%s %d %s",s1[i],&tien[i],s2[i]);
              m[s1[i]] = i;
         }
         for(int i = 0;i<n;i++){
              if(s2[i][0]=='-') boss = i;  
              else V[m[s2[i]]].push_back(i);
         }
      //   printf("%d\n",boss);
        // printf("%s\n",company);  
         printf("%s: %d\n",company,duyet(boss,1));
         
         scanf("\n");

    }
   // getch();
            
}

