//hoan vi
#include <iostream>
#include <algorithm>
#include <conio.h>
using namespace std;

char s[100];
int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    scanf("%s",s);
    int len=1;
    while(s[len-1]!='\0')
        ++len;
    cout<<len<<endl;
    sort(s,s+len-1);
    
    getch();
}
