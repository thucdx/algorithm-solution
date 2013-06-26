#include <iostream>
#include <cstring>
#include <cstdio>
#include <sstream>
using namespace std;
char c[256][256];
int nWord;
int main()
{   
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);  
    nWord=0;
    char s[256];
    gets(s);
    cout<<s<<endl;
    stringstream ss;
    ss<<s;
    ss>>c[1];
    ss>>c[2];
    cout<<ss.str()<<" "<<c[1]<<" "<<c[2]<<endl;
    /*
    for(int i=0;i<nWord;++i)
    cout<<c[i]<<" ";
    */
}
