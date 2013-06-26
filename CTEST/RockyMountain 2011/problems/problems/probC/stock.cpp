// Solution to Stock Prices
//
// Howard Cheng
// Aug 24, 2011
//
// The idea: the size of the input is too large to store all of the input and
// sort.  So instead we maintain two priority queues for the k1 lowest and
// k2 highest stock prices and update them as we go.

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

bool solve(int id)
{
  int n, k1, k2;
  cin >> n >> k1 >> k2;
  if (!n && !k1 && !k2) {
    return false;
  }
  cout << "Case " << id << endl;

  priority_queue<pii> smallest, largest;

  for (int d = 1; d <= n; d++) {
    int item;
    cin >> item;

    smallest.push(make_pair(item, d));
    if ((int)smallest.size() > k1) {
      smallest.pop();
    }

    largest.push(make_pair(-item, -d));
    if ((int)largest.size() > k2) {
      largest.pop();
    }
  }

  int sA[100], lA[100];
  for (int i = 0; i < k1; i++) {
    sA[i] = smallest.top().second;
    smallest.pop();
  }
  sort(sA, sA+k1);
  for (int i = 0; i < k1; i++) {
    if (i) cout << ' ';
    cout << sA[i];
  }
  cout << endl;

  for (int i = 0; i < k2; i++) {
    lA[i] = -largest.top().second;
    largest.pop();
  }
  sort(lA, lA+k2);
  for (int i = k2-1; i >= 0; i--) {
    cout << lA[i];
    if (i > 0) cout << ' ';
  }
  cout << endl;

  return true;
}

int main()
{
  int id = 1;
  while (solve(id++))
    ;
  return 0;
}
