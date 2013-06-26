#include <iostream>
using namespace std;
#include <algorithm>
#define max 2005
#define INF 100000.0
#define NEGINF -100000.0
int n;
struct point{
    int x;
    int y;
}list[max];
float k[max][max];
int cmp(const void * a, const void *b){
    float *ia=(float*)a;
    float *ib=(float*)b;
    float rs=(*ia-*ib);
    if(rs>0) return 1;
    if(rs==0) return 0;
    if(rs<0) return -1;
}
float calK(point a, point b);
int main()
{
    int i,j,t,l;
    int result=0;
    cin>>n;
    for(i=0;i<n;i++){
        scanf("%d%d",&list[i].x,&list[i].y);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            k[i][j]=calK(list[i],list[j]);
        }
        k[i][i]=-100000.0;
        qsort(k[i],n,sizeof(k[i][0]),cmp);

        //Dem so
        j=0;
        l=0;
        while(j<n) {
            l=1;
            if(j==n-1) break;
            while(k[i][j]==k[i][j+1] ){
                j++;
                l++;
                if(j==n-1) break;
            }
            if(l>=2) result=result+ (l*(l-1)/2);
            if(l==1) j++;
        }
    }
    cout<<result/3<<endl;
}
float calK(point a, point b){
    if(a.y==b.y) return (float)INF;
    else return ((float)(a.x-b.x)/(a.y-b.y));
}


