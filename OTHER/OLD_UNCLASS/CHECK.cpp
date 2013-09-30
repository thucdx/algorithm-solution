#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt",  "wt", stdout);
    int n;
    do
    {
    cin>>n;
    if(n==0) break;
    int cnt=0;
    bool f[10];
    memset(f,false,sizeof(f));
    int save=n;
    while(n!=0)
    {
        int cs=n%10;
        if(save%cs==0 && !f[cs])
        {
            cnt++;
            f[cs]=true;
            cout<<" : "<<cs<<" ";
        }
        n/=10;
    }    
    cout<<save<<" "<<cnt<<endl;
    }
    while(true);
    
}
