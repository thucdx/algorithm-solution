#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <cstring>
#include <conio.h>


#define FOR(i, n) for(int i=0; i<n; i++)
#define REP(i, a) for(int i=0; i<=a; i++)
#define SIZE(c) (int)c.size()

#define MAX 100000  
#define INF 1000000000

using namespace std;

struct V{
    int id, d;
    V(int _id, int _d)
    {
        id=_id; d=_d;    
    }   
    bool operator<(const V& that) const
    {
        if(id!= that.id)
            return (d<that.d);
        return (id<that.id);    
    }
};

vector <int> nextVer[MAX+5], dis[MAX+5];
int n,m,start,end,d[MAX+5];
set<V> s;

int main()
{
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    scanf("%d%d%d%d", &n, &m, & start, &end);
    int x,y,z;
    REP(i, m-1)
    {
        
        scanf ("%d%d%d",&x,&y,&z);
        cout<<x<<" "<<y<<" "<<z<<endl;
        nextVer[x].push_back(y);
        dis[x].push_back(z);
    }
    
     
    for(int i=0;i<n;i++)
    d[i]=INF;
    d[start]=0;   
    s.insert(V(start,0));
    while(!s.empty()){
        int id=s.begin()->id;
        int dist=s.begin()->d;
        cout<<"Chon "<<id<<endl;
        if(id==end)
        {
            printf("%d",dist);
            getch();
            return 0;
        }
        s.erase(s.begin());
        FOR(l,SIZE(nextVer[id])){
            int _id=nextVer[id][l];
            int _d=dis[id][l];
            
            if(d[_id]> dist+_d)
            {
                d[_id]=dist+_d;
                s.insert(V(_id,d[_id]))  ;
                cout<<"insert "<< _id<<"  "<<d[_id]<<endl;
            }
        }
    }
    getch();
}
    
    
