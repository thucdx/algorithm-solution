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

#define INF 1000000000
#define PI 3.14159

#define VI vector<int>
#define VVI vector<VI>


//#include <conio.h>

bool isExist(int val, int* arr, int size);

int main()
{
    int a[] = {11,23,4,45,34,38,4,6,8,99};
    int sa = sizeof(a) / sizeof(a[0]);
	
    int b[] = {121,23,24,145,314,38,4,16,18,199};
    int sb = sizeof(b) / sizeof(b[0]);
	
    REP(i,0,sa-1)
    REP(j,0,sb-1)
    {
        if (a[i] == b[j])
            cout<<a[i]<<endl;
    }

//    sort(a, a + sa);
//
//    for (int i = 0; i < sb ; i++)
//    {
//        if (isExist(b[i], a, sa))
//            cout<<b[i]<<endl;
//    }
}


bool isExist(int val, int* a, int size )
{
    int low = 0, hi = size - 1;
    int mid;

    while (low < hi - 1)
    {
        mid = (low + hi) / 2;
        if(val < a[mid])
        {
            hi = mid;
        } // val  >= a[mid]
        else low = mid;
    }

    if (a[low] == val || a[hi] == val) return true;

    return false;
}

