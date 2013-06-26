#include <iostream>
using namespace std;
#include <algorithm>
#define max 50000
int m,n,q;
int list[max];
int m[max][max];
int main()
{
    int i,j;
    int u,v;
    cin>>n>>m;
    //list=new int[n];
    memset(list,0,n);
    for(i=0;i<m;i++){
        cin>>u>>v;
        for(j=u;j<=v;j++)
            list[u]++;
    }
    //Khoi tao.
    for(i=0;i<m;i++){
        max=list[i];
        for(j=i;j<m;j++){
            if(max<list[j])
             m[i][j]=list[j];
             else m[i][j]=max;
        }
    }
    //Doc cac test
    cin>>q;
    for(i=0;i<q;i++){
        cin>>u>>v;
        cout<<m[u][v]<<endl;
    }
}

