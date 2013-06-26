#include <iostream>
#include <cstdlib>
#include <cmath>

#include <sstream>
#include <cstring>
#include <string.h>
#include <conio.h>
using namespace std;
const long long mod=5645634;
int main()
{
    string s="THUCDXFDFDSx";
    long long  key=1;
    for(int i=0;i<s.length();i++)
    {
        key=key*((int)(s[i]*s[i]+1))%mod;
    }
    cout<<key<<endl;
    getch();
       
}
