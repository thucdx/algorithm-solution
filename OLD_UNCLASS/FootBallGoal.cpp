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
double dientich(double a, double b, double d)
{
    double rs=d*d/4.0;
    double p=(a+b+d)/2;
    rs+=sqrt(p*(p-a)*(p-b)*(p-d));
    return rs;
}
double calc(double a, double b);
double calc2(double a, double b)
{
    double c;
    double ret=-1;
    c=sqrt(a*a+b*b - sqrt(2.0)* a*b);
    if(a+b>c && a+c>b && b+c >a)
        ret=max(ret,dientich(a,b,c));
    c=sqrt(a*a+b*b + sqrt(2.0)* a*b);
    if(a+b>c && a+c>b && b+c >a)
        ret=max(ret,dientich(a,b,c));
    return ret;
}

int main()
{
    double a,b;
    cin>>a>>b;
    printf("%.9f",calc2(a,b));
}
double calc(double a, double b)
{
    double low=fabs(a-b), high=a+b;
    double eps=1e-8;
    double h1,h2;
    while(high-low>eps)
    {
          h1=(2.0 * low+high)/3.0;
          h2=(2.0 * high+low)/3.0;  
          if(dientich(a,b,h1)> dientich(a,b,h2))
          {
                high=h2;
          }
          else low=h1;
    }  
    //cout<<low<<" "<<high<<endl;
    return dientich(a,b,low);  
}
    
