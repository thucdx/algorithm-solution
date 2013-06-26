#include <iostream>
using namespace std;
int s1,s2,s3;
int rs;
int main()
{   
    int sum[81];
    int i,j,t;
    for(i=0;i<=81;i++)
    {
     sum[i]=0;                  
    }
    cin>>s1>>s2>>s3;
    for(i=1;i<=s1;i++)
    for(j=1;j<=s2;j++)
    for(t=1;t<=s3;t++)
    sum[i+j+t]+=1;
    
    //tim max;
    int max=0;
    for(i=0;i<=80;i++)
    if(sum[max]<sum[i]) max=i;
    cout<<max<<endl;
    //cin>>max;
}
