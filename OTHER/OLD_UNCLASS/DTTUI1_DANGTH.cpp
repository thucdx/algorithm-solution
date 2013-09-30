#include <iostream>
#include <cstdlib>
using namespace std;
unsigned int u,v,x[44],y[44],ax[1100000],ay[1100000],bx[1100000],by[1100000],res,n,m,an,bn;
void qsorta(int l,int r){
    int i,j,k;
    unsigned int x,y;
    i=l;
    j=r;
    k=rand()%(j-i+1)+i;
    x=ax[k];
    y=ay[k];
    while (i<=j){
        while (ax[i]<x || (ax[i]==x && ay[i]<y)) i++;
        while (ax[j]>x || (ax[j]==x && ay[j]>y)) j--;
        if (i<=j){
            swap(ax[i],ax[j]);
            swap(ay[i],ay[j]);
            i++;
            j--;
        }
    }
    if (i<r) qsorta(i,r);
    if (l<j) qsorta(l,j);
}
void qsortb(int l,int r){
    int i,j,k;
    unsigned int x,y;
    i=l;
    j=r;
    k=rand()%(j-i+1)+i;
    x=bx[k];
    y=by[k];
    while (i<=j){
        while (bx[i]<x || (bx[i]==x && by[i]<y)) i++;
        while (bx[j]>x || (bx[j]==x && by[j]>y)) j--;
        if (i<=j){
            swap(bx[i],bx[j]);
            swap(by[i],by[j]);
            i++;
            j--;
        }
    }
    if (i<r) qsortb(i,r);
    if (l<j) qsortb(l,j);
}
void track1(int k){
    int i;
    for (i=0;i<=1;i++){
        u+=i*x[k];
        v+=i*y[k];
        if (u<=m)
            if (k<n/2) track1(k+1);
            else{
                an++;
                ax[an]=u;
                ay[an]=v;
            }
        u-=i*x[k];
        v-=i*y[k];
    }
}
void track2(int k){
    int i;
    for (i=0;i<=1;i++){
        u+=i*x[k];
        v+=i*y[k];
        if (u<=m)
            if (k<n) track2(k+1);
            else{
                bn++;
                bx[bn]=u;
                by[bn]=v;
            }
        u-=i*x[k];
        v-=i*y[k];
    }
}
int main(){
    int i,j;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin>>n>>m;
    for (i=1;i<=n;i++) cin>>x[i]>>y[i];
    if (n==1){
        if (m>=x[1]) cout<<y[1];
        else cout<<0;
        return 0;
    }
    track1(1);
    track2(n/2+1);
    qsorta(1,an);
    qsortb(1,bn);
    for (i=2;i<=bn;i++) by[i]=max(by[i],by[i-1]);
    j=0;
    for (i=an;i>0;i--){
        while (j<bn && ax[i]+bx[j+1]<=m) j++;
        if (j<=bn && ax[i]+bx[j]<=m && ay[i]+by[j]>res) res=ay[i]+by[j];
    }
    cout<<res;
    return 0;
}
