    #include <iostream>
    using namespace std;
    #include <stdio.h>
    int n,a[2020],b[2020],f[2020][2020],g[2020][2020];
    int main(){
    freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
    int i,j,k,l;
    cin>>n;
    for (i=1;i<=n;i++) cin>>a[i];
    for (i=1;i<n;i++){
    f[i][i+1]=a[i]+a[i+1];
    g[i][i+1]=i;
    }
    for (i=1;i<=n;i++) b[i]=b[i-1]+a[i];
    for (l=3;l<=n;l++)
    for (i=1;i<=n-l+1;i++){
    j=i+l-1;
    for (k=g[i][j-1];k<=g[i+1][j];k++)
    if (f[i][j]==0 || f[i][j]>b[j]-b[i-1]+f[i][k]+f[k+1][j]){
    f[i][j]=b[j]-b[i-1]+f[i][k]+f[k+1][j];
    g[i][j]=k;
    }
    }
    cout<<f[1][n];
    return 0;
    }
