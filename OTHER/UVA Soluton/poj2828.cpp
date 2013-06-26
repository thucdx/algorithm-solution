#include <algorithm>
using namespace std;

const int MAXN = 200100;

struct Node
{
    int left, right;
    int sum, value;
};

struct Tree
{
    int num;
    int root;  
    bool sign;
    Node T[MAXN];
    void clear();
    int insert(int p, int x, int y);
    void insert(int x, int y);
    void preorder(int p);
    void preorder();
};

void Tree::clear()
{
    num = 0;
    memset(T, 0, sizeof(T));
    root = 0;
}

int Tree::insert(int p, int x, int y)
{
    if (p == 0) 
    {
        num++;
        T[num]. left = T[num]. right = 0;
        T[num]. sum = 1;  T[num]. value = y;
        p = num;
    }
    else
    if (T[T[p]. left]. sum >= x)
        T[p]. left = insert(T[p]. left, x, y);
    else
        T[p]. right = insert(T[p]. right, x - T[T[p]. left]. sum - 1, y);
    T[p]. sum = T[T[p]. left]. sum + T[T[p]. right]. sum + 1;
    return p;
}

void Tree::preorder(int p)
{
    if (p == 0) return;
    preorder(T[p]. left);
    if (sign) printf(" "); else sign = true;
    printf("%d", T[p]. value);
    preorder(T[p]. right);
}

void Tree::preorder()
{
    preorder(root);
}

void Tree::insert(int x, int y)
{
    root = insert(root, x, y);
}

Tree t;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        t. clear();
        for (int i = 0; i < n; i++)
        {
            int p, v;
            scanf("%d %d", &p, &v);
            t. insert(p, v);
        }
        t. sign = false;
        t. preorder();
        printf("\n");
    }
    return 0;
}
