#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MaxN = 10000 + 100000;
struct Application {
    int profit, deadline;
    bool operator < (const Application& a) const {
    	return deadline < a.deadline;
	}
}app[MaxN];
int n, l;

void init() {
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &app[i].profit, &app[i].deadline);
}

void work() {
    sort(app, app + n);
    priority_queue<int, vector<int>, greater<int> > q;

    int ans = 0, app_left = 0, pre = -1;
    for (int i = 0; i < n; ++i) {
        app_left += (app[i].deadline - pre) * l;
        if (app_left == 0) {
            if (q.empty()) continue;
            int delta = app[i].profit - q.top();
            if (delta > 0) {
                ans += delta; q.pop();
                q.push(app[i].profit);
            }
        }
        else {
            ans += app[i].profit;
            q.push(app[i].profit); 
			--app_left;
        }

        pre = app[i].deadline;
    }
    printf("%d\n", ans);
}
int main() {
    for (; scanf("%d%d", &n, &l) == 2; ) {
        init();
        work();
    }
    return 0;
}



