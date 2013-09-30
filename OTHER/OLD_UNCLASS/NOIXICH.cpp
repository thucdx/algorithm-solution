#include <iostream>
#include <cstdio>
#include <algorithm>
//#include <conio.h>
using namespace std;
int main()
{
    int n, a[20005]; 
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);    
    }
    sort(a,a+n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>= n-i-1)
        {
            printf("%d",n-i-1);
            break;    
        }    
    }
    //getch();
}
