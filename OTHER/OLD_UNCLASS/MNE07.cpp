#include <iostream>
#include <cstring>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)
string first,last;
int nLen;
int main()
{   
    cin>>first>>last;
    nLen=last.length();
    first.append(first);
    last.append(last);
    FOR(i,nLen){
        string temp=last.substr(i,nLen);
        string patern=temp;
        FOR(j,nLen){ //Tinh patern= last OR temp;
            patern[j]=max(last[j],temp[j]);  
        }    
        if(first.find(patern)<nLen){ //found patern in first  
            cout<<"Yes";
            return 0;    
        }   
    }
    cout<<"No";
}
