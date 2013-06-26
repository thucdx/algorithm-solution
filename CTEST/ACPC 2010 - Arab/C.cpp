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

string expression;
void solve();

int main()
{
//    freopen("C.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
    
    int test = 0;
    do
    {
        cin >> expression;
        if(expression == "()") break;    
        test ++;
        cout << test <<". ";
        solve();        
    }
    while(true);
}
void solve()
{
    stack<char> st;
    int size = expression.length();
    int maxDeep = -1;
    int deep = 0;
    REP(i,0,size-1)
    {
        char current = expression[i];
        if(current == '(') ++deep;
        else if(current ==')') 
        {
            if (deep > maxDeep) 
                maxDeep = deep;
            --deep;
        }
    }
        
    deep = 0;    
    REP(i,0,size-1)    
    {
        char current = expression[i];
        
        if(current == '(')
        {
            deep ++;
            st.push(current);
        }
        else if( current == 'F' || current == 'T')
        {
            st.push(current);    
        }
        else //current == ')')
        {
            char top = st.top();
            st.pop();
                       
            bool subResult;
            bool isFirstOperator = true;
            bool value;
            
            while(top != '(')
            {
                value = (top == 'F' ) ? false : true;
                
                if(isFirstOperator)
                {
                    isFirstOperator = false;
                    subResult = value;
                }           
                else
                {
                    if(deep % 2 == maxDeep % 2)
                    { //AND
                        subResult &= value;
                    }
                    else //OR
                    {
                        subResult |= value;
                    }
                }
                top = st.top();
                st.pop();
                
            }
            
            st.push((subResult == false) ? 'F' : 'T');            
            --deep;
        }            
    }    
    
    char top = st.top();
    st.pop();
    
    cout << ((top == 'F') ? "false" : "true" )<<endl;
}
