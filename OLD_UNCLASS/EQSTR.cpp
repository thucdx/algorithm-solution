#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;i++)

int main()
{
    //freopen("EQSTR.IN", "rt", stdin);
    //freopen("EQSTR.OUT", "wt", stdout);
    string s,t,sign,res;
    do
    {
        cin>>sign;
        if(sign=="[END]")
            return 0;
        //sign= [Case];
        cin>>s>>t;
        //cout<<s<<" "<<t<<endl;
        res="";
        int len=s.length()-1;
        REP(i,0,len)
        {
            char c,sc,tc;
            sc=s[i];
            tc=t[i];
            if(sc>tc) swap(sc,tc);
            if(tc-sc>=(sc-'a')+('z'+1-tc))
                c='a';
            else c=sc;
            res.push_back(c);
        }
        cout<<res<<endl;
    }while(true);
}
