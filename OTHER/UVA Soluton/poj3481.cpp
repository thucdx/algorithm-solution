#include <algorithm>
#include <set>
using namespace std;

struct node {int k, p;};

bool operator < (node a, node b)
{   return a.p < b.p; }

set<node> q;


int main()
{
    int     k, p, op;
    node    t;  
    set<node>::iterator it;

    q.clear();
    while (1)
    {
        scanf("%d", &op);
        if (op == 0) break;
        if (op == 1)
        {
            scanf("%d %d", &k, &p);
            t. k = k;  t. p = p;
            q.insert(t);
        }
        if (op == 3)
        {
            if (q.empty()) printf("0\n");
            else
            {    
                t = *(q.begin());
                printf("%d\n", t. k );                
                q.erase(t); 
            }
        }
        if (op == 2)
        {            
            if (q.empty()) printf("0\n");
            else
            {   
                it = q.end();              
                t = *(--it);
                printf("%d\n", t. k );        
                q.erase(t);                
            }
        }
    }
    return 0;
}

