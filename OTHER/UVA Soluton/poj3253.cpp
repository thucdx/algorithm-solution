#include <algorithm>
#include <queue>
using namespace std;

priority_queue<unsigned int, vector<unsigned int>, greater<int> > heap;
int     n;

int main()
{
    int     i, t;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &t);
        heap.push(t);
    }
    unsigned int     a, b, ans = 0;
    for (i = 0; i < n - 1; i++)
    {        
        a = heap. top();
        heap. pop();
        b = heap. top();
        heap.pop();
        ans += a + b;
        heap.push(a + b);
    }
    printf("%u\n", ans);
    return 0;
}
