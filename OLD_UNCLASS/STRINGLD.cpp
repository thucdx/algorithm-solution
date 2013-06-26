#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;
vector <string> v[105];
void solve();
void input();
int n;
int minLen;
int main()
{
    freopen("input.txt","rt", stdin);
    freopen("output.txt", "wt", stdout);
    do
    {
        scanf("%d",&n);
        if(n==0)
        break;
        input();
        solve();
        
    }  
    while(true);  
        
}
void input()
{   
    //clear
    for(int i=0;i<=100;i++)
    {
        v[i].clear();    
    }
    int len;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        v[s.length()].push_back(s);
    }
}
void solve()
{
    minLen=1000;
    for(int i=0;i<=100;i++)
    {
        if(!v[i].empty())
        {
            minLen=i;
            break;    
        }    
    }
    //cout<<"minLen: "<<minLen<<endl;
    for(int step=1;step<minLen;step++)
    {
        for(int i=minLen;i<=100;i++)
        {
            if(!v[i].empty())
            {
                set <string> s;
                string str;
                for(int j=0;j<v[i].size();j++)
                {
                       str=v[i][j].substr(step); 
                       s.insert(str);
                }
                if(s.size()<v[i].size()) 
                {
                    printf("%d\n",step-1);
                    return ;    
                }    
            }    
        }    
    } 
    printf("%d\n",minLen-1);
    return ;           
}
