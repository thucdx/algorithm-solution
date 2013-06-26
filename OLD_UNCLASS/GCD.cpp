#include <iostream>
using namespace std;
#include <conio.h>
int gcd(int ,int);
int main(){
    int m,n;
    cin>>m>>n;
    cout<<gcd(m,n);
    getch();
}
int gcd(int a,int b){
    if(a<0 ) a=-a;
    if(b<0) b=-b;
    while(b!=0 &&a!=0)
    {
     if(a>b) a=a%b;
     else b=b%a;           
    }
    return (a+b);
}
