#include <algorithm>
#include <vector>
using namespace std;

int p[50010][2];
int id[50010];

bool cmp(const int &i, const int &j)
{
    return p[i][0] + p[i][1] < p[j][0] + p[j][1]; 
}

int main()
{
    int n, i, j, ans, t, sum;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &p[i][0], &p[i][1]);
        id[i] = i;
    }
    sort(id, id + n, cmp);
    ans = INT_MIN;
    for (sum = 0, i = 0; i < n; i++)
    {
        int j = id[i];
        ans >?= sum - p[j][1];
        sum += p[j][0];
    }
    printf("%d\n", ans);
    return 0;
}
