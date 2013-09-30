#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);

#define pb  push_back
#define ins insert
#define all(x) begin(x), end(x)
#define sz(x) size(x)
#define ms(arr,val) memset(arr, val, sizeof(arr))

#define INF 1000000000
#define PI 3.14159

#define VI vector<int>
#define VVI vector<VI>

//Thuc DX

string expre;
void solve();
int main()
{
    int test = 0;    
    do
    {
        cin >> expre;
        if(expre == "()") break;
        test ++;
        cout << test <<". ";
       // cout <<expre<<endl;
        solve();
    }
    while(true);
}
void solve()
{
    bool result = true;
    int ngoac = 0;
    int len = expre.length();
    
    stack<char> st;
    int deep = -1;
    
    for(int i = 0; i< len; i++)
    {
        char cur = expre[i];
        if(cur == '(')
        {
            ngoac ++;    
        }    
        else if(cur == ')')
        {
            if(ngoac > deep ) deep = ngoac;
            ngoac--;    
        }
        
    }
    
//    cout <<deep <<endl;
    ngoac = 0;
    
    for(int i = 0; i < len ; i++)
    {
        char cur = expre[i];
        if (cur == 'T' || cur == 'F')
            st.push(cur);
                
        else if ( cur == '(')
        {
            ngoac ++;
            st.push(cur);    
        }
        
        else if (cur == ')')
        {
            bool isAnd ;
            if(ngoac %2 == deep % 2) isAnd = true;
            else isAnd  = false;
            bool curResult ;
            int countOpe = 0;
            do
            {
                char pp = st.top();
                st.pop();
                
                if(pp == '(')
                {
                    //cout <<"push "<< curResult<<endl;
                    if (curResult)
                        st.push('T');
                    else st.push('F');
                    
                    ngoac --;
                    break;
                }
                else 
                {
//                    if(isAnd) cout <<"tai " << i << "thuc hien AND";
                    
  //                  else  cout <<"tai " << i << "thuc hien OR";
                    //cout <<"    voi "<<pp<<endl;
                    countOpe++;
                    if(countOpe == 1)
                    {
                        if( pp =='F')
                            curResult = false;
                        else curResult = true;          
                    }
                    else
                    {
                        if(isAnd) // ??? 
                        {
                            
                            if (pp == 'F')
                            {
                                curResult = curResult && false;       
                            }    
                            else if (pp == 'T')
                            {
                                curResult = curResult && true;
                            }
                        }
                        else
                        {
                            if (pp == 'F')
                            {
                                curResult = curResult || false;       
                            }    
                            else if (pp =='T')
                            {
                                curResult = curResult || true;
                            }
                        }
                    }
                    
                }
            }
            while(true);            
        }
        
//        cout <<i<<" "<<expre[i]<<" "<< ngoac<<endl;
    }
    
    char pp = st.top();
    st.pop();
    if(pp =='F') cout <<"false"<<endl;
    else cout << "true"<<endl;
}
