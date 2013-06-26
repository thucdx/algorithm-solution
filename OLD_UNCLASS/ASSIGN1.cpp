#include <iostream>
using namespace std;
#define MAX 200
int C[MAX][MAX];
int minTime=1000000;
int n;
int m=0;
void input();
bool f[MAX];
void att(int );
int main(){
    input();
    att(0);
    cout<<minTime<<endl;
}
void input(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        f[i]=true;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&C[i][j]);

}
void att(int per){
    int i;
    int save;
    if(per==n)
    {
        if(m<minTime)
            minTime=m;
        return;
    }

    for(i=0;i<n;i++){
        if(f[i])
        {   //chon c[per][i];
            save=m;
            if(C[per][i]>m) m=C[per][i];
            if(m>minTime)
            {
                m=save;
                continue;
            }
            f[i]=false;//chon
            att(per+1);
            //khoi phuc.
            m=save;
            f[i]=true;
        }
    }
}
