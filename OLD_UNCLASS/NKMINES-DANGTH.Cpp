#include <iostream>
#define MAX 222
using namespace std;
int p,m,n,a[MAX][MAX],b[MAX][MAX];
void print(){
    int i,j;
    for (i=1;i<=m;i++){
        for (j=1;j<=n;j++) printf("%d ",a[i][j]);
        printf("\n");
    }
}
void cal(int x,int y){
    a[x][y]=b[x-1][y-1]-a[x-2][y-2]-a[x-2][y-1]-a[x-2][y]-a[x-1][y]-a[x][y-1]-a[x][y-2]-a[x-1][y-2];
}
int ok1(int l){
    int i,j,k;
    if (l>1 && l<=2*min(m,n)-1 && l%2==1){
        k=(l+1)/2;
        for (j=2;j<k;j++){
            cal(k,j);
            if (a[k][j]<0 || a[k][j]>1) return 0;
        }
        for (i=2;i<k;i++){
            cal(i,k);
            if (a[i][k]<0 || a[i][k]>1) return 0;
        }
        cal(k,k);
        if (a[k][k]<0 || a[k][k]>1) return 0;
        return 1;
    }
    if (l>2*min(m,n)-1 && m>n){
        k=l-n+1;
        for (j=2;j<=n;j++){
            cal(k,j);
            if (a[k][j]<0 || a[k][j]>1) return 0;
        }
        return 1;
    }
    if (l>min(m,n)*2-1 && n>m){
        k=l-m+1;
        for (i=2;i<=m;i++){
            cal(i,k);
            if (a[i][k]<0 || a[i][k]>1) return 0;
        }
        return 1;
    }
}
int ok2(){
    int i,j;
    for (j=2;j<=n;j++){
        cal(m+1,j);
        if (a[m+1][j]!=0) return 0;
    }
    for (i=2;i<=m+1;i++){
        cal(i,n+1);
        if (a[i][n+1]!=0) return 0;
    }
    return 1;
}
void track(int k){
    int i,x,y;
    if (p==1) return;
    if (k<=min(m,n)*2-1){
        if (k%2==0){
            x=k/2+1;
            y=1;
        }else{
            x=1;
            y=(k+1)/2;
        }
    }else if (m>n){
        x=k-n+1;
        y=1;
    }else{
        y=k-m+1;
        x=1;
    }
    for (i=0;i<=1;i++){
        a[x][y]=i;
        if ((k>1 && k<=min(m,n)*2-1 && k%2==1) || k>min(m,n)*2-1){
            if (ok1(k)){
                if (k<m+n-1) track(k+1);
                else if (ok2()){
                    print();
                    p=1;
                    return;
                }
            }
        }else{
            if (k<m+n-1) track(k+1);
            else if (ok2()){
                print();
                p=1;
                return;
            }        
        }
        a[x][y]=0;
    }
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j;
    scanf("%d%d",&m,&n);
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++) scanf("%d",&b[i][j]);
    track(1);
    return 0;
}
