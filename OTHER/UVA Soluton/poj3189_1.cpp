#include <stdio.h>

int grid[2000][30], rev[2000][30];
int low, high, n, b, cap[30], ans;


void readr() 
{
    scanf("%d%d", &n, &b);
    for (int i = 0; i < n; i++)
	    for (int j = 0; j < b; j++) 
        {
	        scanf ("%d", &grid[i][j]);
	        grid[i][j]--;
	        rev[i][grid[i][j]] = j;
	    }
    for (int i = 0; i < b; i++)
	    scanf("%d", &cap[i]);
}

int used[2000], to[2000], tot[30], found;
int path[2000], rec[2000];

void search(int pos, int len) 
{
    if (found) return;
    path[len] = pos;
    used[pos] = 1;
    for (int i = low; i < high; i++)
	    if (tot[grid[pos][i]] < cap[grid[pos][i]]) 
        {
	        path[len + 1] = grid[pos][i];
	        rec[0] = len + 1;
	        for (int j = 1; j <= rec[0]; j++)
		        rec[j] = path[j];
	        found = 1;
	        return;
	    }
    for (int i = 0; i < n; i++)
	    if ((!used[i]) && (to[i] != -1)) 
        {
	        int id = rev[pos][to[i]];
	        if ((id >= low) && (id < high))
             {
		        path[len + 1] = grid[pos][id];
		        search (i, len + 2);
	        }
	    }
}

int 
match () {
    int     i, j, count;
    for (i = 0; i < b; i++)
	tot[i] = 0;
    count = 0;
    for (i = 0; i < n; i++)
	to[i] = -1;
    for (i = 0; i < n; i++)
	for (j = low; (j < high) && (to[i] == -1); j++)
	    if (tot[grid[i][j]] < cap[grid[i][j]]) {
		tot[grid[i][j]]++;
		to[i] = grid[i][j];
		count++;
	    }
    while (count < n) {
	for (i = 0; i < n; i++)
	    used[i] = 0;
	found = 0;
	for (i = 0; i < n; i++)
	    if ((to[i] == -1) && (used[i] == 0) && (found == 0)) {
		search (i, 1);
		if (!found)
		    return (0);
	    }
	for (i = 1; i < rec[0]; i += 2)
	    to[rec[i]] = rec[i + 1];
	tot[rec[rec[0]]]++;
	count++;
    }
    return (1);
}

int calc(int range) 
{
    for (int i = 0; i + range <= b; i++) 
    {
	   low = i;
	   high = i + range;
	   if (match ()) return 1;
    }
    return 0;
}

void solve() 
{
    int     delta;
    ans = b;
    delta = 16;
    while (delta > 0) 
    {
	   if ((ans - delta > 0) && (calc(ans - delta)))
	       ans -= delta;
	   delta = delta / 2;
    }
    printf ("%d\n", ans);
}


int main () 
{
    readr();
    solve();
}
