#include <iostream>
using namespace std;
#include <stdio.h>
int p,q,re,rc,m,b[300300],n,a[50001],d[1000001],e[300300*8],c[300300*8],f[300300];
void add(int a){
    if (a/10>0) add(a/10);
    b[++m]=a%10;
}
void build(int i,int x,int y){
    int z;
    z=(x+y)/2;
    if (x==y){
        e[i]=b[z];
        c[i]=z;
        return;
    }
    build(i*2,x,z);
    build(i*2+1,z+1,y);
    if (e[i*2]>=e[i*2+1]){
        e[i]=e[i*2];
        c[i]=c[i*2];
    }else{
        e[i]=e[i*2+1];
        c[i]=c[i*2+1];
    }
}
void get(int i,int x,int y,int u,int v){
    int z;
    if (u>y || v<x) return;
    if (u<=x && y<=v){
        if (e[i]>re || (e[i]==re && c[i]<rc)){
            re=e[i];
            rc=c[i];
        }
        return;
    }
    z=(x+y)/2;
    get(i*2,x,z,u,v);
    get(i*2+1,z+1,y,u,v);
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int i;
    long long j;
    scanf("%d%d",&p,&q);
    a[++n]=2;
    if (p>1)
        for (i=3;i<=1000000;i+=2)
            if (d[i]==0){
                a[++n]=i;
                if (n==p) break;
                for (j=1LL*i*i;j<=1000000;j+=2*i) d[j]=1;
            }
    for (i=1;i<=n;i++) add(a[i]);
    build(1,1,m);
    i=1;
    while (q>0){
        if (q==m-i+1){
            for (j=i;j<=m;j++) f[j]=1;
            break;
        }
        re=rc=0;
        get(1,1,m,i,i+q);
        for (j=i;j<rc;j++) f[j]=1;
        q-=rc-i;
        i=rc+1;
    }
    for (i=1;i<=m;i++)
        if (f[i]==0) printf("%d",b[i]);
    return 0;
}
