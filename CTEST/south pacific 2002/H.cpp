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
#include <sstream>
//#include <conio.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);
#define pb  push_back
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>

char test[111],s[111];
int n,m,kq,x;
int block[15][15];
int h[15],mu4[15],quay[15],r[15],b[15],len[15],the,tong;
bool check;

void init(){
     mu4[0] = 1;
     for(int i = 1;i<15;i++) mu4[i] = mu4[i-1]*4;
}

int main()
{
   // freopen("H.IN", "rt", stdin);
   // freopen("H.OUT", "wt", stdout);   
     init(); 
   
     while(scanf("%s",&test)>0 && test[0]!='#'){
          scanf("%d %d",&n,&m);
          for(int i = 0;i<n;i++){
               scanf("%d",&h[i]);
               h[i] = (h[i]/3)%4;
          }
          scanf("\n");
          //block.clear();
          //block.resize(m+5);
          for(int i = 0;i<n;i++) len[i] = 0;
          for(int i = 0;i<m;i++){
               gets(s); 
               istringstream is(s);
               while(is>>x){      
                    block[x][len[x]++] = i;
               }
          }

          kq = 100;
          
          if(m==0){
                check = true;
                for(int j = 0;j<n;j++) if(b[j]%4!=0){
                     check = false;
                     break;
                }
                if(check) printf("%s: No moves required.\n",test);
                else printf("%s: No solution.\n",test);
                continue;
          }
          for(int i = 0 ; i<mu4[m];i++){
               the = i,tong = 0;
               for(int j = 0;j<n;j++) b[j] = h[j];
               
               for(int j = 0;j<m;j++){
                    r[j] = the&3;
                    the = the>>2;
                    tong+=r[j]; 
               }
               
               check = true;
               for(int j = 0;j<n;j++) {
                    for(int k = 0;k<len[j];k++) b[j] += r[block[j][k]];
                    if(b[j]%4!=0){
                         check = false;
                         break;
                    }
               }
               if(check){
                    if(tong<kq){
                         kq = tong; 
                         for(int j = 0;j<m;j++) quay[j] = r[j];
                    }
                    else if(tong==kq){
                         bool flag;
                         for(int j = 0;j<m;j++) {
                              if(quay[j]<r[j]) { flag = true; break;}
                              else if(quay[j]>r[j]){ flag = false; break;}
                         }
                         if(flag){
                              for(int j = 0;j<m;j++) quay[j] = r[j];
                         }
                    }
               }
          } 
          
          if(kq==0) printf("%s: No moves required.\n",test);
          else if(kq>=100) printf("%s: No solution.\n",test);
          else{
              // printf("%d\n",kq); 
               vector<int> KQ; 
               for(int i = 0;i<m;i++) 
                    for(int j = 0;j<quay[i];j++)
                         KQ.push_back(i);
               printf("%s:",test);
               for(int i = 0;i<KQ.size();i++) printf(" %d",KQ[i]);
               printf("\n");
          }
     } 
    // getch();           
}

