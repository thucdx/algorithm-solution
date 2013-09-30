#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;
char c[100];
int getNum();

bool cmp(int a, int b)
{
    return (a<b);    
}
struct classCmp
{
    bool operator() (const int & f, const int & l) const
    {
        return (f>l);    
    }    
};
int main()
{   
    freopen("input.txt", "rt", stdin);
    freopen("output.txt",  "wt", stdout);
    priority_queue<int> pq;
    
    while(scanf("%s",c)==1)
    {   
        if(c[0]=='-')
        {   
            if(pq.empty()) continue;
            int k=pq.top();
            while(pq.top()==k && !pq.empty())
                pq.pop();    
            
        }   
        else 
        {
            if(pq.size()<15000 )
            {
                pq.push(getNum());   
            }   
        } 
    }
    set<int,classCmp> s;
    while(!pq.empty())
    {
        s.insert(pq.top());
        pq.pop();
    }
    printf("%d\n",s.size());
    for(set<int>::iterator iter=s.begin(); iter!=s.end();iter++)
    {
        printf("%d\n",*iter);
    }   
}
int getNum()
{
    int rs=0;
    int i=1;
    while(c[i]!='\0')
    {
        rs=rs*10+c[i]-'0'; 
        i++;   
    }    
    return rs;
}
