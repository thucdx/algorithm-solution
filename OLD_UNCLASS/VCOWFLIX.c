#include <iostream>
#incldue <algorithm>
using namespace std;
#define W 5000
#define N 16
int maxW,nCow;
int wei[W];
int f[W][N];
void input();
void process();
int cmp(const void *a,const void *b);
int max(int a,int b)
int main()
{


}
void input()
{
    int i;
    cin>>maxW>>nCow;
    for(i=0;i<nCow;i++)
    scanf("%d",&wei[i]);
}
int cmp(const void *a,const void *b){
    return (*(int *)a- *(int *)b);
}
int max(int a,int b)
{
    if (a>b) return a;
    else return b;
}
void process()
{
    qsort(wei,nCow,sizeof(wei[0]),cmp));
    //khoi tao f[w][0];
    int i;
    for(i=0;i<=maxW;i++)
        for(j=0;j<nCow;j++)
        f[i][j]=0;
    for(i=wei[0];i<=maxW;i++)
        f[i][0]=wei[0];
    for(i=1;i<nCow;i++){
        for(j=wei[i];j<=maxW;j++)
        {
            //f[j][i]=max(w_i+ f[j-w_i][i-1],f[j][i];
            f[j][i]=max(wei[i]+f[j-wei[i]][i-1],f[j][i]);
        }
    }
    cout<<f[maxW][nCow]<<endl;
}
