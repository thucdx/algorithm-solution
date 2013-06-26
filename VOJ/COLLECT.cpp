// Created		: 4:01:11 PM Feb 16, 2013
// Task			: COLLECT
// Description	: 

#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

vector<int> adj[130];
bool visit[130];
int dis[130];
int k, z, s, m, z0, s0, m0;
queue< pair<int, int> > q;

inline int toNum(int z, int s, int m) {
	return z * 25 + s * 5 + m;
}

inline void get(int n, int& z, int& s, int& m) {
	z = n / 25;
	n %= 25;
	s = n / 5;
	m = n % 5;
}

inline bool isValuable(int s) {
	int zz, ss, mm;
	get(s, zz, ss, mm);
	return zz >= z0 && ss >= s0 && mm >= m0;
}

int main() {
#ifdef LOCAL
	freopen("input/COLLECT", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int start, z1, s1, m1, z2, s2, m2;

	scanf("%d", &k);
	scanf("%d %d %d %d %d %d", &z, &s, &m, &z0, &s0, &m0);

	start = toNum(z, s, m);
	while (scanf("%d", &z1) != EOF) {
		scanf("%d %d %d %d %d", &s1, &m1, &z2, &s2, &m2);
		for (int zz = 0; zz <= 4 - max(z1, z2); zz++)
		for (int ss = 0; ss <= 4 - max(s1, s2); ss++)
		for (int mm = 0; mm <= 4 - max(m1, m2); mm++) {
			int from = toNum(z1 + zz, s1 + ss, m1 + mm);
			int to   = toNum(z2 + zz, s2 + ss, m2 + mm);
			if (!isValuable(from)) 	adj[from].push_back(to);
		}
	}

	//UNIQUE
	for (int i = 0; i < 125; ++i ) {
		sort(adj[i].begin(), adj[i].end());
		adj[i].resize(unique(adj[i].begin(), adj[i].end()) - adj[i].begin());
	}

	memset(visit, false, sizeof(visit));
	for (int i = 0; i < 125; ++i) dis[i] = -1;
	visit[start] = true; q.push(make_pair(start, 0)); dis[start] = 0;

	while (!q.empty()) {
		pair<int, int> curpair = q.front(); q.pop();
		int curVer = curpair.first;
		int curDis = curpair.second;
		for (int i = 0; i < (int) adj[curVer].size(); ++i) {
			int nxt = adj[curVer][i];
			if (!visit[nxt]) {
				visit[nxt] = true;
				q.push(make_pair(nxt, curDis + 1));
				dis[nxt] = curDis + 1;
			}
		}
	}

	vector<int> result;
	for (int i = 0; i < 125; ++i) {
		if (dis[i] != -1 && i != start && dis[i] <= k) {
			get(i, z, s, m);
			if (z >= z0 && s >= s0 && m >= m0 ) {
				result.push_back(i);
			}
		}
	}
	if (result.size() == 0) {
		cout << -1 << endl;
	} else  {
		cout << result.size() << endl;
		int z, s, m;
		for (int i = 0; i < (int) result.size(); ++i) {
			get(result[i], z, s, m);
			printf("%d %d %d %d\n", z, s, m, dis[result[i]]);
		}
	}
}
