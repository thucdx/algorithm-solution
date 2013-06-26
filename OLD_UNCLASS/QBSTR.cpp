#include <iostream>
using namespace std;

int f[1005][1005];
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.length();++i)
    {
            f[i][0]=(a[i]==b[0]? 1:0);
    }
    for(int j=0;j<b.length();++j)
    {
            f[0][j]=(b[j]==a[0]? 1:0);
    }
    for(int i=0;i<a.length();++i)
    for(int j=0;j<b.length();++j)
    {
        //f[i][j]
        if(i==0 && j==0)
        {
            f[i][j]=(a[0]==b[0]? 1:0); continue;
        }
        if (i>0)
            f[i][j]=max(f[i][j], f[i-1][j]);
        if(j>0)
            f[i][j]=max(f[i][j],f[i][j-1]);
        if(i>0 && j>0)
            f[i][j]=max(f[i][j], (a[i]==b[j]? 1:0) + f[i-1][j-1]);
            
    }
    cout<<f[a.length()-1][b.length()-1];    
}
