#include <iostream>
using namespace std;

string s[205];
int f[205],m,n;
int main()
{   
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
        cin>>s[i];
        
    int i,j;
    //duyet theo tung cot
    for(i=0;i<n;i++)
    {
        j=0;
        int d=0;
        while(j<m)
        {
            if(s[j][i]=='1')
            {
                ++f[d];    
                d=0;
            }
            else
            {
                ++d;    
            }
            ++j;
        }
        ++f[d];
    }
    for(i=1;i<=m;i++)
    {   
        if(f[i]!=0)
        {
            printf("%d %d",i,f[i]);
            if (i!=m) printf("\n");    
        }
    }
    
}
