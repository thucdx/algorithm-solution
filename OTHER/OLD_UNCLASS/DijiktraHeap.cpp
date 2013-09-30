/*
Program: Dijiktra heap.

*/
#include <iostream>
#include <queue>
#include <conio.h>
using namespace std;

#define MAX 100000
#define FOR(i,a,b) for(int i=a;i<=b;i++)
typedef vector<int> vi;
typedef pair<int, int > ii;
typedef vector<ii> vii;


int n, start, end,m ;
struct verDis{
    int ver,dist;
    verDis(int v, int d){
        ver=v;
        dist=d;   
    }
    
};

class compareVerDis{
    bool operator()(verDis & vd1, verDis & vd2){
        if(vd1.dist >vd2.dist) return true;
        return false;
    }   
}
vi vt[MAX+5];
int D[MAX+5];

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt" ,"wt", stdout);
    cin>>n>>m>>start>>end;
    int i,j,dis;
    FOR(t,1,m)
    {   
        cin>>i>>j>>dis;
  //      cout<<i<<" "<<j<<" "<<dis<<endl;
        vt[i].push_back(ii(j,dis));    
        ii e=vt[i].back();
//        cout<<e.first<<" "<<e.second<<endl<<endl;;
    }
    //tim duong di tu start-> end.
    priority_queue <verDis, vector<verDis>, compareVerDis> pq;
    
    memset(D, 987654321, n+5);
    pq.push(verDis(start,0));
    D[start]=0;
    ii newNode;
    int newV, newDis;

    while(!pq.empty())
    {
            newNode=pq.top();
            pq.pop();
            newV=newNode.ver; newDis=newNode.dist;
            if(newV==end) 
            {
                cout<<newDis<<endl; break;
            }
            if(newDis<= D[newV])
            {
                //duyet tat ca cac dinh ke voi voi newDis
                for(vii::iterator it=vt[newDis].begin();it !=vt[newDis].end();it++){
                    int v2= it->first, dis=it->second;
                    if(D[v2]> D[newV]+dis)
                    {
                        D[v2]=D[newV]+dis;
                        pq.push(ii(v2,D[v2]));    
                    }
                }
            }
            
    }
        
}
