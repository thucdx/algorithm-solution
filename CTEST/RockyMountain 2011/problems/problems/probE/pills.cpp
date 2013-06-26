// Pills solution
//
// Howard Cheng
// Aug 24, 2011
//
// Idea: Let f(F, H) be the number of ways to empty the bottle if there are
//       F full pills and H half pills.  Then we have the recursion
//
//          f(F, H) = f(F-1, H+1) + f(F, H-1)     if F > 0 and H > 0
//          f(F, 0) = f(F-1, 1)                   if F > 0
//          f(0, H) = 1
// 

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

typedef long long ll;
const int MAX_N = 30;
const int BASE = 10000;

ll f[MAX_N+1][MAX_N+1];

ll compute(int F, int H)
{
  if (f[F][H] > 0) {
    return f[F][H];
  }

  if (F == 0) {
    return f[F][H] = 1;
  }

  if (H == 0) {
    compute(F-1, H+1);
    return f[F][H] = compute(F-1, H+1);
  }

  return f[F][H] = compute(F-1, H+1) + compute(F, H-1);
}

int main(void)
{
  int N;
  while (cin >> N && N > 0) {
    cout << compute(N, 0) << endl;
  }

  return 0;
}
