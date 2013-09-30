#include <iostream>
#include <conio.h>
using namespace std;
#include <cmath>
int main()
{   
    freopen("input.txt","rt", stdin);
    freopen("output.txt","wt", stdout);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    long long rs;
    int b;
    if(m<=ceil(n/2)) b=1;
    else b=0;
    rs=2*n+1-(2*n-2*m+1)*( 1<<((int)ceil(log(ceil(n/(2*n-2*m+1.0)))/log(2.0)  ) +1)-b);
    cout<<rs<<endl;
}
