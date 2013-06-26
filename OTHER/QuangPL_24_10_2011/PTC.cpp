#include <iostream>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxk 100000

int k, len[maxk + 5];
set <int> seq;
map <int, int> howmany;

int main() {
    freopen("PTC.INP", "r", stdin);
    freopen("PTC.OUT", "w", stdout);
    
    scanf("%d", &k);    
    for (int i = 0; i < k; ++i) scanf("%d", &len[i]);
    
    for (int i = 0, x = 0; i < k; ++i) {
        seq.clear();
        
        for (int j = 0; j < len[i]; ++j) {
            scanf("%d", &x);
            seq.insert(x);
        }
        
        for (set <int> :: iterator it = seq.begin(); it != seq.end(); ++it) {
            x = *it;
            if (howmany.find(x) == howmany.end()) howmany[x] = 1;
            else howmany[x] = howmany[x] + 1;
        }
    }
    
    for (map <int, int> :: iterator it = howmany.begin(); it != howmany.end(); ++it) {
        if (it->second == k) {
           printf("%d", it->first);
           return 0;
        }
    }
    
    printf("x");    
    return 0;
}
