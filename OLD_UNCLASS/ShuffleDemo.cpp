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
#include <ctime>

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
void shuffle(int * cards, int size);
void swap(int &a , int &b);
void swap2(int &a , int &b);
void swap3(int &a, int & b);

int main()
{
    int n = 1000000;
    int * cards;
    cards = new int [n];
    for (int i = 0 ; i < n ; i++)
        cards[i] = i;

    cout <<" _________ "<<endl;
    shuffle(cards, n);

}

void shuffle(int * cards, int size)
{
    srand ( time(NULL) );
    for (int i = 0; i < size ; i++)
    {
        int index = rand() % size ;

        swap2(cards[i], cards[index]);
    }
}

void swap(int &a , int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swap2(int & a, int &b)
{
    a = a + b; // a + b
    b = a - b;
    a = a - b;
}

void swap3(int &a, int & b)
{
    a = a ^ b;  // bit bit bit bit
    b = b ^ a;
    a = a ^ b;
}


