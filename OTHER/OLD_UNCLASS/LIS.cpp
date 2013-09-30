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
//ham
template <class T>  //so ko am
T gcd(T a, T b){if(b==0) return abs(a); else return gcd(b,a%b);}
template <class T>  
T lcm(T a, T b){ return a/gcd(a,b) *b;}

long long startOfK[100005],a[100005],l[100005],dmax,n;

int main()
{
    freopen("LIS.IN", "rt", stdin);
    freopen("LIS.OUT", "wt", stdout);              
    scanf("%d",&n);
    REP(i,0,n-1)
    {
        scanf("%lld",&a[i]);    
       // cout<<a[i]<< " ";
    }
    //cout<<endl;
    //cout<<" i    dmax    l[i]" <<endl;
    dmax=1;
    startOfK[1]=n-1;
    l[n-1]=1;
    DOWN(i,n-2,0)
    {   
        //cout<<"__________________"<<endl;
        if(a[i]>a[startOfK[1]])
        {
            startOfK[1]=i;
        }   
        else
        {
            //tim p max nhat sao cho a[i] <startOfK[p]
            // chu y: a[startOfK[1]]>a[startOfK[2]]>a[startOfK[3]].....> a[startOfK[dmax]
            int low=1, high=dmax+1;
            while(low!=high-1)
            {
                int mid=(low+high)/2;    
                if(a[startOfK[mid]] > a[i])
                {
                    low=mid;
                }
                else
                {
                    high=mid;    
                }
            }
            //cout<<"found "<<startOfK[low]<<endl;
            //cout<<"Before d: dmax= "<<dmax<<endl;
            //REP(i,1,dmax)
//            {
//                //cout<<i<<" "<<startOfK[i]<<" "<<a[startOfK[i]]<<endl;    
//            }
            l[i]=1+l[startOfK[low]];
            if(l[i]> dmax)
            {
                dmax=l[i];
                startOfK[dmax]=i;    
            }
            else if(a[i]>a[startOfK[l[i]]])
            {
                startOfK[l[i]]=i;
            } 
            //cout<<"Update d: dmax= "<<dmax<<endl;
            //REP(i,1,dmax)
//            {
//               // cout<<i<<" "<<startOfK[i]<<" "<<a[startOfK[i]]<<endl;    
//            }       
        }
       // cout<<"at "<<i<<": "<<dmax<<" "<<l[i]<<endl;
    }
    cout<<dmax;
}

