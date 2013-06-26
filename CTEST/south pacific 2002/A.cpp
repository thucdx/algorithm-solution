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
char s[111];
int n,kq,run = 0,a,b;

int main()
{
   // freopen("A.IN", "rt", stdin);
   // freopen("A.OUT", "wt", stdout);   
    scanf("%s",s);  
    while(true){
          scanf("%d %d",&a,&b);
          int flag = 0;
          printf("Set %d\n",++run);
          while(scanf("%s",s)>0){
             //   printf("%s\n",s
                if(s[0]=='#'){
                      flag = 1;
                      break;
                }
                else if(s[0]=='C'){
                      flag = 2;
                      break;
                }
                else{
                     n = atoi(s);
                //     printf("%d\n",n);
                     kq = 0;
                     while(n>0){
                          if(n%2) kq+=b;
                          else kq+=a;
                          n/=2;
                     }
                     printf("%d\n",kq);
                }
          }
          if(flag==1) break;
    }
            
}

