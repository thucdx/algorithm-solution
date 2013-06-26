#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
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
int findMax(int*a, int len);
int main()
{
    freopen("input.txt",  "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int a[]={3435};
    int len=sizeof(a)/sizeof(a[0]);
    cout<<a[findMax(a,len)];    
}
int findMax(int *a, int len)
{
    int head=0,tail=len-1;
    int r1,r2;
    while(head<tail-2)
    {
        //cout<<head<<" "<<tail<<endl;
        r1=(2*head+tail)/3;
        r2=(head+2*tail)/3;    
        if(a[r1]<a[r2]) head=r1;
        else tail=r2;
    }
    int rs=head,maxV=a[head];
    for(int i=head+1;i<=tail;i++)
        if(a[i]>maxV)
        {
            maxV=a[i];
            rs=i;
        }
        
    return rs;
}
    
