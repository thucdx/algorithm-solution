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
#include <conio.h>
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

double EPS=1e-9;
string num;
inline bool divi3(string number);
inline string toNum(string a);
int main()
{
    freopen("NUMSET.IN", "rt", stdin);
    freopen("NUMSET.OUT", "wt", stdout);              
    do
    {
    cin>>num;
    if(num=="-1") break;
    int len=num.length()-1;
    set<string> s;
    s.insert(toNum(num));
    REP(i,0,len)
    {
        REP(j,i,len) //xoa tu i toi j
        {  
            if(i==0 && j==len) continue; 
            string tmp="";
            REP(t,0,len)
            {
                    if(t<i || t>j)
                    {
                        tmp.push_back(num[t]);    
                    }
            }
            s.insert(toNum(tmp));
        }
    }
    set<string>::iterator it;
    int count=0;
    for(it=s.begin(); it!=s.end(); it++)
    {
        //cout<<*it<<endl;
        if(divi3(*it)) count++;
        
    }
    cout<<count<<endl;
    }
    while(true);
}
string toNum(string a)
{
    int i=0;
    bool firstZero=true;
    string rs="";
    if(a=="") return "";
    while(i<a.length())
    {
        if(firstZero && a[i]=='0')
        {
            i++;    
        }
        else
        {
            rs.push_back(a[i]);
            i++;
            firstZero=false;    
        }
            
    }
    if(firstZero) rs.push_back('0');
    return rs;
}
bool divi3(string number)
{
    //cout<<number<<endl;
    int remain=0,len=number.length()-1;
    REP(i,0,len)
    {
        remain+=((int)number[i]-'0')%3;
    }    
    return (remain%3==0);
}

