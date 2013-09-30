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
#include <list>
#include <algorithm>

using namespace std;

#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a)

#define pb  push_back
#define ins insert
#define all(x) begin(x), end(x)
#define sz(x) size(x)
#define ms(arr,val) memset(arr, val, sizeof(arr))

#define INF 1000000000
#define PI 3.14159

#define VI vector<int>
#define VVI vector<VI>

string suite = "SDHC";
string value = "23456789TJQKA";

inline string toCard(int number)
{        
    string rs = "__";
    rs[1] = suite[number % 4];
    rs[0] = value[(number - number %4)/4];
    return rs;
}

inline int toNumber(string card)
{
    int s, v;
    for(s = 0; s < suite.length(); s++)
    {
        if(suite[s] == card[1])
            break;
    }
    
    for(v = 0; v < value.length(); v++)
    {
        if(value[v] == card[0])
            break;
    }
    //cout<<card<<" : ";
    //cout <<v <<" "<<s<<" => ";
    //cout <<v * 4 + s <<endl;
    
    
    return v * 4 + s;
}

inline bool canGroup(int a, int b)
{
    //cout <<"CHECK " <<a <<" "<<b<<endl;
    return (a % 4 == b % 4) || (a / 4 == b /4 );
}


int n;

vector<int> card;
int currentSize ;

bool disable[55];

bool go(int n);

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    string c;
    memset(disable, 0, sizeof(disable));    
    card.resize(n);
    
    REP(i,1,n)
    {
        cin >> c;        
        card[i-1] = toNumber(c);        
    }    
        
    bool possible = go(n);    
    if(possible) cout <<"YES";
    else cout <<"NO";
}

bool go(int n)
{    
    //cout << "go " << n<<endl;   
    if(n == 1)  
        return true;
        
    bool rs;
    
    int id1 = -1, count = 0;
    
    for(int i = n -1 ; i >= 0 ; --i)
    {
        if(!disable[i])
        {
            count ++ ;
            if(count == 2 ) {id1 = i; break;}
        }
    }    
    //cout <<"id1 "<<id1<<endl;
    
    if(id1 != -1)
    {
        for(int i = 0 ; i < n;i++)
        {
            if(!disable[i] && i != id1 && canGroup(card[i], card[id1]))
            {
               // cout <<i <<" "<<id1<<endl;
                //cout <<card[i]<<" "<<card[id1]<<endl;
                disable[i] = true;
                int tmp = card[id1];
                card[id1] = card[i];
                
                bool sub = go(n-1);                
                if(sub) return true;
                
                card[id1] = tmp;
                disable[i] = false;
            }    
        }
    }  
    
    //n-3
    count = 0; 
    if(n >= 4)
    {
        int id3 = -1;
        for(int i = n -1 ; i >= 0 ; --i)
        {
            if(!disable[i])
            {
                count ++ ;
                if(count == 4 ) {id3 = i; break;}
            }
        }    
        
        if(id3 != -1)
        {
            for(int i = 0 ; i < n;i++)
            {
                if(!disable[i] && i != id3 && canGroup(card[i], card[id3]))
                {
                    disable[i] = true;
                    int tmp = card[id3];
                    card[id3] = card[i];
                    
                    bool sub = go(n-1);                
                    if(sub) return true;
                    
                    card[id3] = tmp;
                    disable[i] = false;
                }    
            }        
        }
    }
    
    return false;
    
    
}
