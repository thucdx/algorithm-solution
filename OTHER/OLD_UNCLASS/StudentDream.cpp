#include <iostream>
#include <cstdio>
using namespace std;

//#include <conio.h>
int main()
{
  //  freopen("input.txt", "rt", stdin);
    //freopen("ouput.txt", "wt", stdout);
    int al,ar,bl,br;
    scanf("%d%d%d%d",&al,&ar,&bl,&br); //girl -boy
    //br-al
    bool isOk=false;
    if(br>=al-1 && br<=2*al+2)
        isOk=true;
    //ar-bl;
    if(bl>=ar-1 && bl<=2*ar+2)
        isOk=true;
    if(isOk)
    cout<<"YES";
    else cout<<"NO";
    //getch();
    return 0;
    
}
