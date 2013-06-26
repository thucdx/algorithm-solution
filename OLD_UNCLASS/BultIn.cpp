#include <iostream>
using namespace std;
#include <conio.h>
#include <vector>
int main()
{
 vector <int> a;
 vector <int>::iterator it;
 int list[]={3,4,5,6,54,456,324,-453,45,45,56,5};
 int i;
 for(i=0;i<sizeof(list)/sizeof(int);i++)
 {
   a.push_back(list[i]);
 }
 //duyet;
 for(it=a.begin();it<a.end();it++)
 {
  cout<<*it<<' ';                                    
 }
 getch();
}
