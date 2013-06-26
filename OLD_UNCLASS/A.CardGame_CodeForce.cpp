#include <iostream>

using namespace std;
int getNum (char c);
int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    
    char trump;
    string first,  second;
    cin>>trump;
    cin>>first>>second;
    if(first[1]==second[1])
    {
        if(getNum(first[0]) >getNum(second[0]))
        cout<<"YES";
        else cout<<"NO";
        return 0;
    }
    else
        if(first[1]==trump)
        {
                cout<<"YES";
                return 0;    
        }
        else {
            cout<<"NO";
            return 0;
        }    
}
int getNum (char c)
{
    switch(c)
    {
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        case 'A': return 14;
        default: return c-'0';
    }
    return 1;
}
