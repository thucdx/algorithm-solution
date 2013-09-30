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
#define all(x) (x).begin(), (x).end()
#define sz(x) size(x)

#define INF 1000000000
#define PI 3.14159

#define VI vector<int>
#define VVI vector<VI>


//#include <conio.h>
struct record
{
    string name;
    int mark;

    record(){}
    record(string n, int m)
    {
        name = n;
        mark = m;
    }

    bool operator<(const record& other) const
    {
        return mark < other.mark;
    }
};

vector<record> records;
int n;
int nPlayer;
string remark(int lessthan, int equal)
{
    int pNotWorseThan = (lessthan + equal) * 100 / nPlayer;

    if (pNotWorseThan < 50)
        return "noob";
    else if (pNotWorseThan < 80)
        return "random";
    else if (pNotWorseThan < 90)
        return "average";
    else if (pNotWorseThan < 99)
        return  "hardcore";
    else
        return "pro";
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    cin >> n;
    string nm;

    vector<record>::iterator it1, it2;
    int m;
    REP(i, 1, n)
    {
        cin >> nm >> m;
        bool isExist = false;
        for (it1 = records.begin(); it1 != records.end(); it1 ++)
        {
            if (it1->name == nm)
            {
                it1 ->mark = max(it1->mark, m);
                isExist = true;
                break;
            }
        }
        if (!isExist)
            records.pb(record(nm,m));
    }

    nPlayer = records.size();
    cout<<nPlayer<<endl;

    sort(all(records));

    int lessThan = 0, equal = 0, greaterThan = 0;


    for (it1 = records.begin(); it1 != records.end() ; it1 ++)
    {
        int curMark = it1 -> mark;
        lessThan = 0, equal = 0, greaterThan = 0;
        for (it2 = records.begin(); it2 != records.end() ; it2 ++)
        {
            if ( it2 -> mark < curMark) lessThan ++;
            else if (it2 -> mark == curMark) equal ++;
            else break;
        }

        cout << it1 -> name <<" "<< remark(lessThan, equal) <<endl;
    }
}
