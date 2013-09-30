#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <sstream>
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

double eps = 1e-10;
int n;

vector<char> stm;
vector<char> rs;
int len;
int ptr;
bool hasError = false;
stringstream ss;
void makePair();

int main()
{
    //freopen("input.txt", "rt", stdin);
    cin>>n;
    int count = 0;
    
    char s[10];
    string input;
    scanf("%*c");
    getline(cin,input);
    
    for(int p = 0; p < input.length();)
    {
                
        if(input[p] == ' ')
        {
            p++; continue;
        }
        
        stm.push_back(input[p]);
        
        if(input[p] == 'p')
        {
            p+= 5;
        }
        else p +=4;
    }
    
    len = stm.size();
    ptr = 0;
    makePair();
    if(ptr != len - 1) hasError = true;
    
    if (hasError) cout<<"Error occurred";
    else
    {
        string s;
        REP(i,0,rs.size() -1 )
        {
            s.push_back(rs[i]);
        }
        cout<<s;
    }
    //getch();

}

void makePair()
{
    if (ptr >= len ) return;
    if (hasError) return ;
    
    char s = stm[ptr];
    if(s == 'i')
    {
        rs.push_back('i');
        rs.push_back('n');
        rs.push_back('t');
        return;
    }
    else //s == pair
    {
        rs.push_back('p');
        rs.push_back('a');
        rs.push_back('i');
        rs.push_back('r');
        rs.push_back('<');
        ptr++;
        if(ptr >= len)
        {
            hasError = true;
            return;
        }
        makePair();
        rs.push_back(',');
        ptr++;
        if(ptr >= len)
        {
            hasError = true;
            return;
        }
        makePair();
        rs.push_back('>');
    }
}
