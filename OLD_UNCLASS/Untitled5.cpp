#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#define MAX 100005
using namespace std;
vector<int> lst[130];
char s[MAX],t[MAX];
int k;
int len;
long long cal(int val,int pos);
int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    scanf("%d%d%s",&k,&len,s);
    for(int i=0;i<len;i++)
    {
        lst[s[i]-'a'].push_back(i);
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%s",t);
        len=strlen(t);
        long long ret=0;
        for(int j=0;j<len;j++)
        {
            ret+=cal(t[j]-'a',j);    
        }    
        printf("%I64d\n",ret);
    }    
}
long long cal(int val, int pos)
{
        int sl=lst[val].size();
        if(sl==0) return len;
        if(pos<=lst[val][0]) return lst[val][0]-pos;
        if(pos>=lst[val][sl-1]) return pos-lst[val][sl-1];
        int ret=len;
        int tmt=lower_bound(lst[val].begin(),lst[val].end(),pos)-lst[val].begin();
        if(tmt<sl) ret=min(ret,lst[val][tmt]-pos);
        if(tmt>0) ret=min(ret, pos-lst[val][tmt-1]);
        return ret;
        
            
        
}
