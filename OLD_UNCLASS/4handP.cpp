#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;

#define CARDSIZE  52
#define nSAME 4
#define CHOOSECARD  13
#define SHUFFLE 15

#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);
#define MS(arr,value) memset(arr, value, sizeof(arr));

int cards[CARDSIZE + 5], current[CHOOSECARD + 5];
//int swap(int &a, int &b)
//{
//    int tmp = a;
//    a = b;
//    b =  tmp;
//}
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int nTest;
    cin >> nTest;

    for(int i = 1; i <= nTest; i++)
    {
        int nRound;
        int success = 0;

        cin >> nRound;

        REP(round, 1, nRound)
        {
            REP(i,0,CARDSIZE - 1)
                cards[i] = i/4;

            REP(j,1,SHUFFLE)
            {
                int tmp[CARDSIZE + 5];
                int first = rand() % CARDSIZE;
                int second = rand() % CARDSIZE;
                if (first > second)  swap(first, second);

                REP(i,first,second)
                    tmp[i -first] = cards[i];

                REP(i,0,first -1 )
                    tmp[i + second -first + 1] = cards[i];

                REP(i,0,second)
                    cards[i] = tmp[i];
            }

            int cnt[CHOOSECARD + 5];
            MS(cnt, 0);

            REP(i,0,CHOOSECARD-1)
                cnt[cards[i*4]]++;

            REP(i,0,CHOOSECARD-1)
            {
                //cout <<cnt[i]<<",";
                if (cnt [i] == nSAME) {success +=1; break;}
            }
            //cout <<endl;

        }

        cout <<"RESULT : " <<success <<" " <<nRound << "   " <<success * 1.0 / nRound<<endl;
    }

    return 0;
}
