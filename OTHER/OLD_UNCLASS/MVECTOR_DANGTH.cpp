#include <iostream>
#include <math.h>
using namespace std;
struct point{
    long long x,y;
};
double t[30300];
long long r,u,v;
point p[30300];
int n;
double theta(long long dx,long long dy){
    double t;
    if (dx==0 && dy==0) t=0;
    else t=dy/(fabs(dx)+fabs(dy));
    if (dx<0) t=2-t;
    else if (dy<0) t=4+t;
    return t*90;
}
void swap(long long& x,long long& y){
    long long z=x;
    x=y;
    y=z;
}
void qsort(int l,int r){
    int i,j;
    double t0;
    i=l;
    j=r;
    t0=t[(i+j)/2];
    while (i<=j){
        while (t[i]<t0) i++;
        while (t[j]>t0) j--;
        if (i<=j){
            swap(p[i].x,p[j].x);
            swap(p[i].y,p[j].y);
            swap(t[i],t[j]);
            i++;
            j--;
        }
    }
    if (i<r) qsort(i,r);
    if (l<j) qsort(l,j);
}
long long weight(long long x,long long y){
    return x*x+y*y;
}
int main(){
    int i,j;
    cin>>n;
    for (i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
    for (i=1;i<=n;i++) t[i]=theta(p[i].x,p[i].y);
    qsort(1,n);
    u=0;
    v=0;
    j=0;
    while (weight(u,v)<weight(u+p[j%n+1].x,v+p[j%n+1].y)){
        j=j%n+1;
        u+=p[j].x;
        v+=p[j].y;
    }
    if (r<weight(u,v)) r=weight(u,v);
    for (i=2;i<=n;i++){
        u-=p[i-1].x;
        v-=p[i-1].y;
        while (weight(u,v)<weight(u+p[j%n+1].x,v+p[j%n+1].y)){
            j=j%n+1;
            u+=p[j].x;
            v+=p[j].y;
        }
        if (r<weight(u,v)) r=weight(u,v);
    }
    cout<<r;
    return 0;
}
