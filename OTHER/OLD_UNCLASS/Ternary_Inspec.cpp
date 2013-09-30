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

vector<int> arr;
int n;

int ternarySearch(int low, int hi);

int main()
{
    freopen("Ternary_Inspec.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    
    cin >> n;
    int val;
    REP(i,1,n)
    {
        cin >> val;
        arr.pb(val);
    }
    
    cout <<ternarySearch(0,n-1);    
}

int ternarySearch(int low, int hi)
{
    cout << low <<" "<<hi<<endl;
    
    if(low >= hi -2)
    {
        int result = arr[low];
        REP(i,low+1,hi)
            if(result < arr[i])
                result = arr[i];
        return result;
    }
    
    int leftThird = (2 * low + hi )/3;
    int rightThird = (low + 2 * hi)/3;
    
    if (arr[leftThird] < arr[rightThird])
        return ternarySearch(leftThird, hi);
    else return ternarySearch(low, rightThird);
}
