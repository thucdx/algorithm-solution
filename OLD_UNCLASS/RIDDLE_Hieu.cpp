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
#define oo 1111111
#define base 100000000
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define chia 21266327
double const PI=4*atan(1);

using namespace std;

typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;

int n,k,a[100111],test,sl[100111],b[100111],run;
long long tong;
bool check;

int tinh(int x){
     cout<<"r= "<<x+1<<endl;
      memset(sl,0,sizeof(sl));
      for(int i = 0;i<=x;i++) sl[a[i]]++;
      run = 0;
      for(int i = 0;i<=100000;i++){
           for(int j = 0;j<sl[i];j++)
                 b[run++] = i; 
      }
      tong = 0; check = true;
      for(int i=0;i<=x;i++)
                  cout<<i<<" "<<b[i]<<endl;
      for(int i = 0;i<=x;i++){

            if(b[i]>tong+1){
                 check = false;
                 break;
            }
            else tong = tong+b[i];
      }
      if(tong>=k && check) return true;
      else return false;
}

int main(){
    freopen("RIDDLE.in","r",stdin);
    freopen("RIDDLE_HIEU.out","wt",stdout);    
     scanf("%d",&test);
     for(int itest = 1;itest<=test;itest++){
          scanf("%d %d",&n,&k);
          for(int i = 0;i<n;i++) scanf("%d",&a[i]);
          int u = 0, v = n , r;
          while(u<v){
               r = (u+v)/2;
               if(tinh(r)) v = r;
               else u = r+1;
             //  printf("%d\n",r);
          }
          if(u==n) printf("-1\n");
          else printf("%d\n",u+1);
     }
    // getch();
}

