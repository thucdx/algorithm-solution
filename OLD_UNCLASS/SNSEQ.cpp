#include <iostream>
//#include <conio.h>
using namespace std;

int n;
double a;
int main()
{
    cin>>n>>a;
    double minA=0.0;
    for(int i=3;i<=n;i++)
    {
        minA=max(minA, ((i-2)*a -(i-1)*(i-2))/(i-1) );   
    }
    printf("%.2f", (n-1)*minA-(n-2)*a+(n-1)*(n-2));  
    //getch();        
}
