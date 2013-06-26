#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool same(int A[], int N)
{
  for (int i = 0; i < N; i++) {
    if (A[i] != A[0]) {
      return false;
    }
  }
  return true;
}

bool solve(int id)
{
  int N;
  cin >> N;
  if (!N) return false;

  int A[20];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int count = 0;
  while (!same(A, N) && count <= 1000) {
    int B[20];
    copy(A, A+N, B);
    for (int i = 0; i < N; i++) {
      A[i] = abs(B[i] - B[(i+1)%N]);
    }
    count++;
  }

  cout << "Case " << id << ": ";
  if (same(A, N)) {
    cout << count << " iterations" << endl;
  } else {
    cout << "not attained" << endl;
  }
  
  return true;
}
int main()
{
  int id = 1;
  while (solve(id++))
    ;
  return 0;
}
