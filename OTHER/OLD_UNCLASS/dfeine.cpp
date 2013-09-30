#include <iostream>
using namespace std;

#define  f(i,a,b)\
for(int i=int(a);i<=int(b);i++)

#include <conio.h>

int main()
{
 int arr[10];
 f(i,0,5){
          cin>>arr[i];
 }
 f(i,1,4)
  cout<<arr[i]<<' ';
  getch();
}
