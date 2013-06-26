#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

pair<int,int> edge[150000];
int weight[150000];
int start[150000];

int n, k;
int m;

void DFS(int root, int *best)
{
  int best2[301];

  copy(best, best+k+1, best2);

  // look at all the children
  for (int i = start[root]; i < m && edge[i].first == root; i++) {
    int child = edge[i].second;

    DFS(child, best2);
  }
  
  best[0] = 0;
  // we can either use the best from our children, or add just the root
  for (int kk = k; kk >=  1; kk--) {
    best[kk] = best2[kk];
    if (best[kk-1] >= 0) {
      best[kk] = max(best[kk], weight[root] + best[kk-1]);
    }
  }
}

bool solve()
{
  if (!(cin >> n >> k)) return false;

  int root = -1;
  m = 0;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p >> weight[i];
    if (p == 0) {
      root = i;
    } else {
      edge[m++] = make_pair(p-1, i);
    }
  }
  sort(edge, edge+m);
  fill(start, start+n, m);
  for (int i = 0; i < m; i++) {
    if (i == 0 || edge[i].first != edge[i-1].first) {
      start[edge[i].first] = i;
    }
  }

  int best[301];
  fill(best, best+k+1, INT_MIN);
  best[0] = 0;

  DFS(root, best);
  if (best[k] == INT_MIN) {
    cout << "impossible" << endl;
  } else {
    cout << best[k] << endl;
  }

  return true;
}


int main()
{
  while (solve())
    ;
  return 0;
}
