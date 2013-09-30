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

struct team
{
    string name;
    int point;
    int winball;
    int lostball;  
    int match;
    
    team()    
    {
        point = match = 0;
        winball = lostball = 0;        
    }      
    
    bool operator<(const team &other) const
    {
         if(point < other.point) return true;
         if(point > other.point) return false;
        
         //point = other.point
         if ((winball - lostball) != (other.winball - other.lostball) )
            return winball - lostball < other.winball - other.lostball;          
         if (winball != other.winball)
            return winball < other.winball;
            
         if(name < other.name) return false;
         return true;
    }
};

map<string,team> mp;

map<string,team>::iterator ite;

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    string team1,team2;
    int x, y;
    string tiso;
    string myTeam = "BERLAND";
    
    REP(i,1,5)
    {
        cin >> team1 >> team2 >> tiso;        
        x = tiso[0]-'0';
        y = tiso[2]-'0';
        
        mp[team1].name = team1;
        mp[team2].name = team2;
        
        mp[team1].match++;
        mp[team2].match++;
        
        mp[team1].winball += x;        
        mp[team1].lostball += y;
        mp[team2].winball += y;
        mp[team2].lostball += x;
        
        if(x > y) 
            mp[team1].point +=3;
        else 
            if(x==y) 
                mp[team1].point +=1, mp[team2].point +=1;
        else mp[team2].point +=3;
    }
    
    
    string lastTeam ;    
    for(ite = mp.begin(); ite!= mp.end(); ite++)
    {
        if((ite->second).match == 2 && ite->first != myTeam)        
        {
            lastTeam = ite->first;
            break;    
        }
    }    
    
    vector<team> tmp;
    int me, opponent;
    int i = 0 ;
    for(ite = mp.begin(); ite != mp.end(); ite++)
    {
        tmp.pb(ite -> second);    
        if(ite->first == myTeam)
        {
            me =  i;
            tmp[i].point +=3;
        }
        else if (ite ->first == lastTeam)
            opponent = i;
            
        i++;            
    }
    
    int bestX = 100 , bestY = -1;
    int mewin = tmp[me].winball, melose = tmp[me].lostball;
    int opwin = tmp[opponent].winball, oplose = tmp[opponent].lostball;
    vector<team> bk;
    
    for(int i = 0; i < 4 ;i++)
    {
        bk.pb(tmp[i]);    
    }
    
    for(int y = 0; y <= 100; y++)
    {
        for(int x = y + 1; x <= 100; x++)
        {
            for(int i = 0; i< 4; i++)
            {
                tmp[i] = bk[i];    
            }
            
            tmp[me].winball = mewin +x ;    
            tmp[me].lostball = melose + y;
            tmp[opponent].winball = opwin + y;
            tmp[opponent].lostball = oplose + x;
            
            sort(tmp.begin(), tmp.end()); 
            
            for(int i = 0; i < 4; i++)
            {
                if (tmp[i].name == myTeam)
                {
                    if(i>=2 )
                    {
                        if( x - y < bestX - bestY)
                        {
                            bestX = x ;
                            bestY = y;    
                        }    
                        else if (x - y == bestX - bestY)
                        {
                            if ( y <bestY )
                            {
                                bestX = x ;
                                bestY = y;     
                            }    
                        }
                    }    
                }                  
            }            
        }    
    }
    
    if(bestY == -1) 
        cout <<"IMPOSSIBLE"<<endl;
    else 
    cout<<bestX<<":"<<bestY<<endl;           
}
