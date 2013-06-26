#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int     n, l;
    scanf("%d %d", &n, &l);
    vector<pair<int, int> > q(n);
    
    for (int i = 0; i < n; i++)
        scanf("%d %d", &(q[i]. first), &(q[i]. second));
    sort(q. begin(), q. end());
    int     used = 0;
    int     p = 0;
    int     s, t;
    int     tmp;
    while (p < n) 
    {
	   s = q[p]. first;
	   t = q[p]. second;
	   tmp = 1 + (t - 1 - s) / l;
	   used += tmp;
	   tmp = s + tmp * l;
	   while (p < n && q[p]. second <= tmp)
	       p++;
	   if (p < n)
	       q[p].first >?= tmp;
    }
    printf("%d\n", used);
    system("pause");
    return 0;
}
