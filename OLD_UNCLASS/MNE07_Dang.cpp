#include <iostream>
using namespace std;
string x,y,z,t;
int n,next[5050];
int main(){
    freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
    int i,j,k;
    cin>>y;
    cin>>x;
    n=x.size();
    x.append(x);
    y.append(y);
    for (k=0;k<n;k++){
        z=x.substr(k,n);
        t=z;
        for (i=0;i<n;i++)
            if (z[i]=='0' && x[i]=='0') t[i]='0';
            else t[i]='1';
        i=1;
        j=0;
        next[1]=0;
        while (i<=n){
            if (j==0 || t[i-1]==t[j-1]) next[++i]=++j;
            else j=next[j];
        }
        i=1;
        j=1;
        while (i<=2*n && j<=n){
            if (j==0 || y[i-1]==t[j-1]){
                i++;
                j++;
            }else j=next[j];
        }
        if (j>t.size()){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}

