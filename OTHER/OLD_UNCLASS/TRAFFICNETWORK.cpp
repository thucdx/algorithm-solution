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
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);

#define VI vector<int>
#define VVI vector<VI>
#define er erase
#define INF 10000005
struct Point{
    int id;
    int d;
    Point(){}
    Point(int _id, int _d)
    {
        id=_id;
        d=_d;    
    }
    Point(const Point& that)
    {
        id=that.id;
        d=that.d;    
    }
    bool operator<(const Point that) const{
        return id<that.id;
    }
    void operator=(const Point that)
    {
        id=that.id;
        d=that.d;    
    }

};
//ham

int fromS[10005], toT[10005],rawS[10005], rawT[10005];
bool v[10005];
vector <int> adj[10005],dAdj[10004],prev[10005],dPrev[10004];

void init();
int n,m,k,s,t;
int main()
{
   freopen("TrafficNetWork.IN", "rt", stdin);
   freopen("TrafficNetWork.OUT", "wt", stdout);              
   int nTest;
   scanf("%d",&nTest);
   REP(r,1,nTest)
   {

	   scanf("%d%d%d%d%d", &n,&m,&k,&s,&t);
	   int a,b,d;
	   REP(i,1,n)
	   {
	       adj[i].clear();
	       prev[i].clear();
	       dAdj[i].clear();
	       dPrev[i].clear();
	   }
	   
	   REP(i,1,m)
	   {
			scanf("%d%d%d",&a,&b,&d);
			//dinsert[a][b]=d;
			adj[a].push_back(b); 
			dAdj[a].push_back(d);
			prev[b].push_back(a);
            dPrev[b].push_back(d);        
	   }
	   init();
	   int result=fromS[t];
	   REP(i,1,k)
	   {
			scanf("%d%d%d",&a,&b,&d);
			int temp;
			temp=fromS[a]+toT[b]+d;
			if(temp<result) result=temp;    
			temp=fromS[b]+toT[a]+d;
			if(temp<result) result=temp;
		}
		if(result>=INF) printf("-1\n");
		else printf("%d\n",result);
    }
   //getch();
}
void init()
{   
    set<Point> st;
    REP(i,1,n)
    {
        fromS[i]=INF;
        toT[i]=INF;
        rawS[i]=INF;
        rawT[i]=INF;
    }
    int len1=adj[s].size(),len2=prev[t].size()-1;
    if(len1>=1)
    REP(i,0,len1-1)
    {
        rawS[adj[s][i]]=dAdj[s][i];     //S tp    
    }
    if(len2>=1)    
    REP(i,0,len2-1)
    {
        rawT[prev[t][i]]=dPrev[t][i];     // to T
    }
    
    //dach sach min toi cac canh s-> i;
    memset(v, false, sizeof(v));
    v[s]=true;
    st.insert(Point(s,0));
    fromS[s]=0;
    int count=1;
    do
    {   
        count++;
        if(st.empty()) break;
        Point first=*(st.begin());
        int node=first.id;
        int dNode=first.d;
        v[node]=true;    
        //cout<<endl<<"NODE_ DNODE"<<node<<" "<<dNode<<endl;
        st.er(st.begin());
        //fromS[node]=dNode;
        int len=adj[node].size()-1;
        if(len<0) continue;
        REP(t,0,len)
        {
            int nVer=adj[node][t];
            //cout<<nVer<<" ";
            if(v[nVer]==true) continue;
            int dinsertTonVer=dAdj[node][t];
            int dVer=min(rawS[nVer], dNode+ dinsertTonVer);
            if(dVer>=INF) continue;
            fromS[nVer]=dVer;
            st.insert(Point(nVer,dVer));            
        }   
    }
    while(count<n+1);
    //REP(i,1,n)
    //cout<<i<<" "<<fromS[i]<<endl;
    //danh sach min tu i->t
    
    st.clear();
    memset(v, false, sizeof(v));
    v[t]=true;
    toT[t]=0;
    st.insert(Point(t,0));
    count=1;
    do
    {   
        count++;
        if(st.empty()) break;
        Point first=*(st.begin());
        int node=first.id;
        int dNode=first.d;
        v[node]=true;    
        st.er(st.begin()); //erase
        //toT[node]=dNode;
        int len=prev[node].size()-1;
        if(len<0) continue;
        REP(j,0,len)
        {
            int nVer=prev[node][j];
            if(v[nVer]==true) continue; //vinsertited , ko can vinsertited nua
            int dinsertFromnVer=dPrev[node][j];
            //cout<<"rawT[nver]_nVer"<<rawT[nVer]<<" "<<nVer<<"  cur"<<node<<endl;
            int dVer=min(rawT[nVer], dinsertFromnVer+ toT[node]);
            if(dVer>=INF) continue;
            toT[nVer]=dVer;
            st.insert(Point(nVer,dVer));            
        }
    }
    while(count<n+1);        
    //REP(i,1,n)
    //    cout<<i<<" "<<toT[i]<<endl;
}
