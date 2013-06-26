#include <algorithm>
using namespace std;
const int   MAXN = 100000;

int     N;

struct cow 
{
    int ti, di; 
} cows[MAXN];

bool cmp (const cow x, const cow y)
{
	return (x.ti * y.di - x.di * y.ti <= 0);
}

int main()
{
	int    i, j, l, k, s;
	scanf("%d", &N);
	s = 0;
	for (i = 0; i < N; ++i)
    {
		scanf("%d %d", &k, &l);
		cows[i].ti = k;
		cows[i].di = l;
		s += l;
	}
	sort(cows, cows + N, cmp);
     
    __int64 ans = 0;
	for(i = 0; i < N; i++)
	{
		s -= cows[i].di;
		ans += 2 * s * cows[i].ti;
    }
	printf("%I64d\n", ans);
	return 0;
}
