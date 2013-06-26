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

int n;
string month;
int a[200],d[200];

int mid[105][105];
int bd[105][105];
bool visit[105];
void init();
void solve();
void trace(int start, int end);
int main()
{
    //freopen("E.IN", "rt", stdin);
    //freopen("E.OUT", "wt", stdout);  
    bool first=true;
    do
    {
        cin>>month;
        //cout<<month<<endl;
        if(month=="#") break;
        if(first)
        {
            first=false;    
        }
        else cout<<endl;
        init();
        n=0;
        while(scanf("%d%d",&a[n+1],&d[n+1])==2)
        {
            //cout<<n<<" "<<a[n]<<" "<<d[n]<<endl;
            n++;    
        }
        solve();
    }
    while(true);
     
}
void init()
{
    
}
void trace(int start, int end)
{
        int mm=mid[start][end];
        if(mm!=-1)
        { 
           // sver.insert(mm);
            if(visit[mm]==false){
                visit[mm]=true;        
                cout<<mm<<endl;
                trace(start,mm);
                trace(mm,end);
            }
        }
        //mm=-1, lien he truc tiep thi thoi.
        
}
void solve()
{    
    init();  
    memset(visit,false, sizeof(visit));  
    int NEG=-10000000;
    //Tao do thi.
    int ndis[105][105];
    int maxDis[105][105];
    REP(i,0,n)
    {
        REP(j,0,n)
        {   
            bd[i][j]=NEG;
            maxDis[i][j]=0;
            mid[i][j]=-1;
            ndis[i][j]=NEG;
        }
    }
    //Noi dinh 0 voi cac dinh.
    REP(i,1,n)
    {
        bd[0][i]=a[i];
        ndis[0][i]=a[i];
        mid[0][i]=0;    
    }
    ndis[0][n+1]=0;
    mid[0][n+1]=0;
    bd[0][n+1]=0;
    
    REP(i,1,n)
    {
        bd[i][n+1]=0;
        ndis[i][n+1]=0;
        mid[i][n+1]=i;
    }
    REP(i,1,n)
    {
        int j=i+d[i];
        REP(t,j,n)
        {
            bd[i][t]=a[t];
            ndis[i][t]=a[t]; 
            mid[i][t]=i;   
        }    
    }
    //Floyd;
    REP(u,0,n+1)
    REP(i,0,n+1)
    REP(j,0,n+1)
    {
        //if(ndis[i][j]==NEG) continue;
        if(u<=i || u>=j || i>=j) continue;
        int dd=ndis[i][u]+ndis[u][j];
        if(ndis[i][j]< dd)
        {
            ndis[i][j]=dd;
            mid[i][j]= u;  
        }
        else if(ndis[i][j]==dd)
        {
            if(mid[i][j]<u)
                mid[i][j]=u;    
        }  
    }    
    ///cout<<"max lollies:"<<ndis[0][n+1]<<" "<<endl;;
    int start=0,endv=n+1;
    set<int> sver;
    while(bd[start][endv]!=ndis[start][endv]) //khong noi truc tiep
    {
        DOWN(i,endv-1,start+1)
        {
            //cout<<i<<" "<<ndis[start][i]<<" "<<ndis[i][endv]<<endl;
            if((ndis[start][endv]==(ndis[start][i]+ndis[i][endv])) && bd[start][i]==ndis[start][i])
            {   
                //cout<<i<<endl;
                sver.insert(i);
                start=i;
                break;    
            }
        }    
    }
    cout<<"In "<<month<<" "<<ndis[0][n+1]<<" ";
    if(ndis[0][n+1]>=2) cout<<"lollies";
    else cout<<"lolly";
    cout<<" can be obtained:"<<endl;
    for(set<int>::iterator it=sver.begin(); it!=sver.end(); it++)
    {
        int nlolly=a[*it];
        cout<<"On day "<<*it<<" "<<"collect "<<nlolly;
        if(nlolly>1) cout<<" lollies.";
        else cout<<" lolly.";
        cout<<endl;
    }
    //cout<<endl;
    
}
