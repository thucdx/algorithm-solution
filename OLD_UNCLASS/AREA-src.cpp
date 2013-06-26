#include <iostream>
#include <algorithm>
#define MAXN 10100
using namespace std;
struct rect{
    double x,y,u,v;
};
rect re[MAXN];
double f[MAXN*16],rx[MAXN*2],ry[MAXN*2],res;
int n,c1[MAXN],c2[MAXN],rxn,ryn,g[MAXN*16];
void qsort1(int l,int r){
    int i,j;
    double t;
    i=l;
    j=r;
    t=re[c1[(i+j)/2]].x;
    while (i<=j){
        while (re[c1[i]].x<t) i++; 
        while (re[c1[j]].x>t) j--;
        if (i<=j){
            swap(c1[i],c1[j]);
            i++;
            j--;
        }
    }
    if (i<r) qsort1(i,r);
    if (l<j) qsort1(l,j);
}
void qsort2(int l,int r){
    int i,j;
    double t;
    i=l;
    j=r;
    t=re[c2[(i+j)/2]].u;
    while (i<=j){
        while (re[c2[i]].u<t) i++; 
        while (re[c2[j]].u>t) j--;
        if (i<=j){
            swap(c2[i],c2[j]);
            i++;
            j--;
        }
    }
    if (i<r) qsort2(i,r);
    if (l<j) qsort2(l,j);
}
int pos(double y0){
    int i,j,k;
    i=1;
    j=ryn;
    while (j-i>1){
        k=(i+j)/2;
        if (ry[k]==y0) return k;
        if (ry[k]<y0) i=k+1;
        else j=k-1;
    }
    if (ry[i]==y0) return i;
    if (ry[j]==y0) return j;
}
void update(int i,int x,int y,int u,int v,int w){
    int z;
    if (y<u || x>v) return;
    z=(x+y)/2;
    if (u<=x && y<=v){
        g[i]+=w;
        if (g[i]==0) f[i]=f[i*2]+f[i*2+1];
        else f[i]=ry[y+1]-ry[x];
        return;
    }
    update(i*2,x,z,u,v,w);
    update(i*2+1,z+1,y,u,v,w);
    if (g[i]==0) f[i]=f[i*2]+f[i*2+1];
    else f[i]=ry[y+1]-ry[x];    
}
void add(int i,int j){
    int x,y;
    x=pos(re[i].y);
    y=pos(re[i].v);
    update(1,1,ryn-1,x,y-1,j);
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j,k;
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        scanf("%lf%lf%lf%lf",&re[i].x,&re[i].y,&re[i].u,&re[i].v);
        c1[i]=c2[i]=i;
        rx[++rxn]=re[i].x;
        rx[++rxn]=re[i].u;
        ry[++ryn]=re[i].y;
        ry[++ryn]=re[i].v;
    }
    qsort1(1,n);
    qsort2(1,n);
    sort(rx+1,rx+rxn+1);
    sort(ry+1,ry+ryn+1);
    k=rxn;
    rxn=1;
    for (i=2;i<=k;i++)
        if (rx[i]>rx[rxn]) rx[++rxn]=rx[i];
    k=ryn;
    ryn=1;
    for (i=2;i<=k;i++)
        if (ry[i]>ry[ryn]) ry[++ryn]=ry[i];
    i=1;
    j=1;
    for (k=1;k<rxn;k++){
        while (i<=n && re[c1[i]].x<=rx[k]){
            add(c1[i],1);
            i++;
        }
        while (j<=n && re[c2[j]].u<=rx[k]){
            add(c2[j],-1);        
            j++;
        }
        res+=(rx[k+1]-rx[k])*f[1];
    }
    printf("%.0lf",res);    
    return 0;
}
