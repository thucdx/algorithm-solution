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
long long n,kq,nhan,the,run;

int main()
{
   // freopen("B.IN", "rt", stdin);
   // freopen("B.OUT", "wt", stdout);
    while(scanf("%s",s)>0 && s[0] != '#'){
        // printf("%s\n",s);
         n = (long long)(atoi(s));
         nhan = 1;
         run = 0;
         for(int i = 1;;i++){
              the = nhan*10;
              if(run+(the-nhan)*i<n){
                   
                   run += (the-nhan)*i;
                   nhan = the;
                  // continue; 
              }
              else{
                    n = n-run;
                   // printf("%lld %lld\n",n,run);
                    if(n%i!=0) cout<<"Impossible!"<<endl;
                    else{
                         cout<<n/i+nhan-1<<endl;
                    }
                    break;
              }     
         }
    }
             
}

