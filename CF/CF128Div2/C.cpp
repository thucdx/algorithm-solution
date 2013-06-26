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

using namespace std;

#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);

#define pb  push_back
#define ins insert
#define all(x) begin(x), end(x)
#define sz(x) size(x)
#define ms(arr,val) memset(arr, val, sizeof(arr))

#define INF 1000000000
#define PI 3.14159

#define VI vector<int>
#define VVI vector<VI>


int a, b, n ,d;

struct client
{
    int memory;
    int id;
    client(){}
    client(int x, int y,int _id)
    {
        id = _id;
        memory = x * a + y * b;
    }
    bool operator<(const client& other) const
    {
        return memory < other.memory;    
    }        
};

vector<client> clients;
vector<int> canServe;

int main()
{
    //freopen("C.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> d;
    cin >> a >> b;
    int x,y;
    
    REP(i,1,n)
    {
        cin >> x >> y;
        clients.pb(client(x,y,i));   
    }
    
    sort(clients.begin(), clients.end());
    
    long long total = 0;
    
    
    for(vector<client>::iterator it = clients.begin(); it != clients.end(); it++)
    {
        total = total + it -> memory;
        if(total > d)
        {
            break;
        }  
        else
        {
            canServe.pb(it -> id);   
        }
    }
    
    cout << canServe.size()<<endl;
    for(vector<int>::iterator it = canServe.begin(); it != canServe.end(); it++)
    {
        cout <<*it<<" ";
    }
}
