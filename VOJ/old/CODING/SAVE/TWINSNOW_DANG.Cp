#include <iostream>
using namespace std;
#include <stdio.h>
int a[100100][7],n;
int compare(int a[],int b[]){
    int i;
    for (i=1;i<=6;i++)
        if (a[i]>b[i]) return 1;
        else if (a[i]<b[i]) return -1;
    return 0;
}
void swap(int a[],int b[]){
    int i;
    for (i=1;i<=6;i++) swap(a[i],b[i]);
}
void save(int a[],int b[]){
    int i;
    for (i=1;i<=6;i++) a[i]=b[i];
}
void qsort(int l,int r){
    int i,j,k,b[7];
    i=l;
    j=r;
    k=(i+j)/2;
    save(b,a[k]);
    while (i<=j){
        while (compare(a[i],b)<0) i++;
        while (compare(a[j],b)>0) j--;
        if (i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if (i<r) qsort(i,r);
    if (l<j) qsort(l,j);
}
int main(){
	freopen("input.txt","rt", stdin);
	freopen("output.txt","wt", stdout);
    int i,j,k,b[7],c[7];
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        for (j=1;j<=6;j++) scanf("%d",&a[i][j]);
    for (i=1;i<=n;i++){
        save(b,a[i]);
        for (k=1;k<=6;k++){
            for (j=1;j<=6;j++) c[j]=a[i][(j+k-1)%6+1];
            if (compare(b,c)>0) save(b,c);
        }
        for (j=1;j<=3;j++) swap(a[i][j],a[i][7-j]);
        for (k=1;k<=6;k++){
            for (j=1;j<=6;j++) c[j]=a[i][(j+k-1)%6+1];
            if (compare(b,c)>0) save(b,c);
        }
        save(a[i],b);
    }
    qsort(1,n);
    for(i=1;i<n;i++)
    {
    	for(j=1;j<=6;j++)
    	cout<<a[i][j]<<' ';
    	cout<<endl;
    }
    for (i=1;i<n;i++)
        if (compare(a[i],a[i+1])==0){
            printf("Twin snowflakes found.");
            return 0;
        }
    printf("No two snowflakes are alike.");
    return 0;
}

