//ok
#include <iostream>
using namespace std;
 
char s[11],t[11];
int tt[11];
int fact[11];
int len;

__int64 dfs(int now,int level)
{
    if(level==len)
    {
        if(now>tt[level-1])
            return 1;
        return 0;
    }
    if(s[level]=='?')
    {
        int i=0;
        while(i<10 && now*10+i<tt[level])
            i++;
        __int64 tmp=dfs(now*10+i,level+1);
        if(i+1<10)
            tmp+=(9-i)*dfs(now*10+i+1,level+1);
        return tmp;
    }
    else if(now*10+s[level]-'0'>=tt[level])
    {
        return dfs(now*10+s[level]-'0',level+1);
    }
    else
    {
        return 0;
    }
}

void solve()
{
    int i,j,k;
    len=strlen(s);
    tt[0]=t[0]-'0';
    for(i=1;i<len;i++)
        tt[i]=tt[i-1]*10+t[i]-'0';
    printf("%I64d\n",dfs(0,0));
}
 
int main()
{
    fact[0]=1;
    for(int i=1;i<=10;i++)
        fact[i]=fact[i-1]*10;
    while(true)
    {
        scanf("%s",s);
        if(s[0]=='#') return 1;
        scanf("%s",t);
        solve();
    }
}
