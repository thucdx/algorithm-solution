#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;
int main()
{
    string a="hello";
    string b="fdgfdsfgdfgsdhexllosfdsfsfdsfhello";
    if(b.find(a)>=b.size())
    cout<<"Not found!";
    else 
        cout<<b.find(a)<<endl;
    getch();    
}
