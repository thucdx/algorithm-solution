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
#include <ctime>
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

int * cards;
int size = 52;
int hand = 13;

void shuffle(int k);
bool hasNSame(int* cards, int size, int nSame);
void showArr();
bool unitTest(int i);

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);

    int nTest;
    int rep;

    cin>>rep;
    for(int i = 1; i<= rep; i++)
    {
        cin>>nTest;
        int success = 0;
        srand ( time(NULL) );
        REP(i,1,nTest)
        {
            success += unitTest(rand());
        }
        cout<<success<< " "<<"Percent = "<<(success * 1.0 /nTest)<<endl;
    }


}

bool unitTest(int i)
{
    srand (i );
    cards = new int[size];
    REP(i,0, size - 1)
    {
        cards[i] = i/4;
    }

    shuffle(15);

    //showArr();

    //cout <<"xong";
    //return 0;
    int * currentHand = new int[hand];
    for (int i = 0; i< 13; i++)
    {
        currentHand[i] = cards[4*i+1];
    }
//    for(int i = 0 ; i < size; i+=4)
//    {
//        currentHand[i/4] = cards[i];
//        //cout<<currentHand[i/4]<<" ";
//    }
    //cout<<"currentHand"<<endl;

    bool hasFourKind = hasNSame(currentHand, hand, 4);
//    if (hasFourKind)
//        cout<<"Tu qui";
//    else cout <<" Khong co tu qui";
    return hasFourKind;
}
void showArr()
{
    REP(i,0,size -1 )
        cout <<cards[i] <<" ";
    cout <<endl;
}

void shuffle(int k)
{
    int * tmp;

    tmp = new int[size];

    for(int i = 1; i <= k ;i++)
    {
        int pos = rand() % size;
        int pos2;
        do
        {
            pos2 = rand() % size;
        }
        while(pos == pos2);

        if(pos2 < pos)
        {
            int tmp = pos;
            pos = pos2;
            pos2 = tmp;
        }

        //cout <<"shuffle "<< i <<" at pos "<<pos <<" " <<pos2<<endl;

        for(int i = pos ; i <= pos2 ; i++)
        {
            tmp[i-pos] = cards[i];
        }

        for(int i = 0; i< pos; i++)
        {
            tmp[i+pos2-pos+1] = cards[i];
        }

        for(int i = pos2 ; i < size; i++)
        {
            tmp[i] = cards[i];
        }
        for(int i = 0; i < size; i++)
        {
            cards[i] = tmp[i];
            //cout <<cards[i]<<" ";
        }
        //cout<<endl;
    }
}

bool hasNSame(int *cards, int size, int nSame)
{
    int* count = new int[hand + 5];

    memset(count, 0, sizeof(count));

    for(int i= 0; i< size; i++)
    {
        count[cards[i]] ++;
    }

    for(int i = 1 ; i <= hand; i++)
        if (count[i] == nSame) return true;
    return false;
}
