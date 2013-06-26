// Created : 1:47:58 PM ; Oct 16, 2012

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, a) for (int i = 0; i < (a); i++)
#define FIT(it, v) for (typeof((v).begin())it = (v).begin(); it != (v).end(); it++)

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))
#define FILL(a, x, n) fill(a, a + n, x)
#define SORT(v) sort(ALL(v))
#define GSORT(v) sort(ALL(v), greater<typeof(*(v).begin())>())
#define UNIQUE(v) SORT(v); (v).resize(unique(ALL(v)) - (v).begin())

#define PB push_back
#define MP make_pair
#define F first
#define S second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< vi > vvi;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

const double PI = 4.0f * atan(1);  // double or long double ?
const int INF = (int) 1E9 + 5;    // enough ?
const double EPS = 1E-11;        // enough ?
const ll MOD = (ll) 1E9 + 7;    // of problem ?
struct film{
	int minFavorite;
	int maxFavorite;

	film(){}
	film(int minF, int maxF){
		minFavorite = minF;
		maxFavorite = maxF;
	}
};

int m, k;
bool favor[105];

film getInfo(vector<int> actors, int nActors){
	int cntFree = 0;
	int minRet = 0;
	int cntFavor = 0;
	int maxRet = 0;
	bool already[105];

	memset(already, false, sizeof(already));

	REP(i, SZ(actors)){
		if (favor[actors[i]]) {
			cntFavor++;
		}
		if (actors[i] == 0) cntFree++;

		already[actors[i]] = true;
	}

	// what is max???
	int favorleft = 0;

	FOR(i,1, nActors){
		if (favor[i] && !already[i]){
			favorleft++;
		}
	}
	//cout << favorleft << endl;
	int notFavorleft = 0;
	FOR(i, 1, nActors){
		if (!favor[i] && !already[i])
			notFavorleft ++;
	}
	//cout << "not favorleft" << notFavorleft << endl;
	maxRet = cntFavor + min( favorleft, cntFree);
	minRet = cntFavor + max(0, cntFree - notFavorleft);

	return film(minRet, maxRet);
}

vector<film> fs;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &m , &k);
	memset(favor, false, sizeof(favor));

	int like;
	REP(i, k){
		scanf("%d" , &like);
		favor[like] = true;
	}

	int nFilm , numActor;
	string name;

	cin >> nFilm;

	REP(i, nFilm){
		cin >> name;
		scanf("%d", &numActor);

		vector<int> actor;
		int act;
		REP(j, numActor){
			scanf("%d",&act);
			actor.PB(act);
		}

		film newFilm = getInfo(actor, m);
		//cout << newFilm.minFavorite << " " << newFilm.maxFavorite << endl;
		fs.PB(newFilm);
	}

	//cout << "ret " << endl;
	REP(i, nFilm){
		bool sureFavor;
		bool sureNotFavor;

		int minLike = fs[i].minFavorite;
		int maxLike = fs[i].maxFavorite;

		int maxLikeOther = -1;
		int minLikeOther = -1;
		REP(j, nFilm){
			if (j != i){
				if (maxLikeOther < fs[j].maxFavorite) maxLikeOther = fs[j].maxFavorite;
				if (minLikeOther < fs[j].minFavorite) minLikeOther = fs[j].minFavorite;
			}
		}

		if (minLike < maxLikeOther)
			sureFavor = false;
		else sureFavor = true;

		if (maxLike < minLikeOther)
			sureNotFavor = true;
		else sureNotFavor = false;

		if (sureFavor){
			cout << 0;
		}
		else if (sureNotFavor){
			cout << 1;
		}
		else cout << 2;
		cout << endl;
	}
}
