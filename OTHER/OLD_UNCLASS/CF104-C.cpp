#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
//#include <conio.h>
using namespace std;


int main()
{
//    freopen("input.txt", "rt", stdin);    
    string a,b;
    cin>>a;
    cin>>b;
    int n=a.length(),four=0,seven=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            if(a[i]=='4')    four++;
            else seven++;
        }
    }

    cout<<four+seven -min(four,seven);
//    getch();
}
