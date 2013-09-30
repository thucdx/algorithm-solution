#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool f[1005];
bool found,fexit;
bool b[1005][1005];
int list[1005];
int n;
void att(int i);
int main(){
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    char c[1005];
    scanf("%d",&n);
    getchar(); //xoa enter.
    for(int i=1;i<=n;i++)
    {   
        gets(c);
        for(int j=1;j<=n;j++)
        {
            b[i][j]=(c[j-1]=='1'? true: false);        
        }    
    }
    list[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(b[list[i-1]][i]) list[i]=i;
        else
        {
            int j=i-1;
            while(j>=1 && (!b[list[j]][i] ))
            {
                    list[j+1]=list[j];
                    j--;
            }
            list[j+1]=i;   
        }    
    }
    for(int i=1;i<=n;i++)
    printf("%d ",list[i]);
}
/*
void att(int i)
{   
    if(found || fexit) return;
    if(i==n+1)
    {
        for(int j=1;j<=n;j++)    
        printf("%d ",list[j]);
        found=true;
        return ;
    }
    int deg=0;
    for(int j=1;j<=n;j++)
    {   
        if(b[list[i-1]][j] && !f[j])
        {   deg++;
            list[i]=j;
            f[j]=true;
            att(i+1);
            f[j]=false;    
        }
    }
   // if(deg==0) fexit=true;
    
}
*/
