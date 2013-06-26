#include <iostream>
#include <conio.h>
using namespace std;

int main()
{   
    freopen("NTFS.INP", "rt", stdin);
    freopen("NTFS.OUT", "wt", stdout);
    int nbyte;
    do
    {
        cin>>nbyte;
        if(nbyte==0) break;
        cout<<((nbyte-1)/4096+1)<<endl;
    }while(true);
}
