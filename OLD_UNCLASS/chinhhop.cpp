#include <iostream>
#include <algorithm>
#include <vector>
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define DOWN(i,a,b) for(int i = a; i >= b; i--)
#define MS(vt,vl) memset(vt, vl, sizeof(vt))

using namespace std;

int n = 10;
int k = 3;

vector<int> permutation;
vector<bool> alreadyInList;

int main()
{
    freopen("output.txt", "wt", stdout);
    permutation.resize(n+1);
    alreadyInList.resize(n+1);

    REP(i,1,k)
    {
        permutation[i] = i;
        alreadyInList[i] = true;
    }

    REP(i,1,k)
        cout << permutation[i] <<" ";
    cout<<endl;

    bool hasNext = true;
    do
    {
        hasNext = false;

        DOWN(i,k,1)
        {
            alreadyInList[permutation[i]] = false;
            REP(j,permutation[i] + 1, n)
            {
                if(!alreadyInList[j])
                {
                    hasNext = true;
                    alreadyInList[j] = true;
                    permutation[i] = j;

                    REP(pos,i+1,k)
                    {
                        int last = 1;
                        REP(val,last,n)
                        {
                            if(!alreadyInList[val])
                            {
                                permutation[pos] = val;
                                last = val + 1;
                                alreadyInList[val] = true;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            if(hasNext)
                break;
        }
        if(hasNext)
        {
            REP(i,1,k)
            {
                cout << permutation[i] <<" ";
            }
            cout<<endl;
        }
    }
    while(hasNext);

}
