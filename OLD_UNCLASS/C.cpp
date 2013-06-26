#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>
using namespace std;
int f[256];
string s;
int nFree,notServed;
int main()
{
    scanf("%d",&nFree);
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(f[s[i]]==0) //vao
        {
            if(nFree>0)
            {
                f[s[i]]=1;
                nFree--;
            }
            else
            {
                f[s[i]]=2;//ko dc vao
                notServed++;
            }
        }
        else if(f[s[i]]==1)
        {
            f[s[i]]=0;
            nFree++;
        }
        else if(f[s[i]]==2)
        {
            f[s[i]]=0;        
        }
    }
    if(notServed==0) cout<<"All are served!"<<endl;
    else cout<<notServed<<endl;
    getch();
        
}
