#include <iostream>
using namespace std;
int n,s,t,q[1111111],qf,ql,a[22],d[2222222],b[22];
int main(){
    int i,j,k,l;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&j);
    t=(1<<j);
    for (i=1;i<=n;i++){
        a[i]=(1<<(n+1))-2;
        scanf("%d",&k);
        for (j=1;j<=k;j++){
            scanf("%d",&l);
            a[i]-=(1<<l);
        }
    }
    for (i=1;i<=n;i++) scanf("%d",&b[i]);
    for (i=n;i>=0;i--) s=s*2+b[i];
    d[s]=1;
    qf=ql=1;
    q[1]=s;
    while (qf<=ql){
        k=q[qf++];
        for (i=1;i<=n;i++){
            l=k;
            l=l&a[i];
            l=(l|(1<<i));
            if (d[l]==0){
                d[l]=d[k]+1;
                q[++ql]=l;
                if (l==t){
                    printf("%d",d[t]-1);
                    return 0;
                }
            }
        }
    }
    printf("-1");
    return 0;
}
