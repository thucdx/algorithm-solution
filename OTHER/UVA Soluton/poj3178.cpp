#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-4;
const int MAXN = 160;

struct Point
{
        double x, y;
        Point(double x = 0, double y = 0) : x(x), y(y) {};
};

int n, m;
double r;
bool g[MAXN][MAXN];
int f[MAXN][MAXN];
Point p[MAXN];
Point c[MAXN];

int dcmp(double x)
{
        if (x < -eps) return -1; else return (x > eps);
}

double det(Point p0, Point p1, Point p2)
{
        return (p1. x - p0. x) * (p2. y - p0. y) - (p2. x - p0. x) * (p1. y - p0. y);
}
double dot(Point p0, Point p1, Point p2)
{
        return (p1. x - p0. x) * (p2. x - p0. x) + (p1. y - p0. y) * (p2. y - p0. y);
}

inline double sqr(double x) { return x * x; }

double dis(Point p1, Point p2)
{
        return sqrt(sqr(p1. x - p2. x) + sqr(p1. y - p2. y));
}

double PointLine(Point p0, Point p1, Point p2, Point &cp)
{
        double d = dis(p1, p2);
        double s = det(p1, p2, p0) / d;
        cp. x = p0. x + s * (p2. y - p1. y) / d;
        cp. y = p0. y - s * (p2. x - p1. x) / d;
        return s;
}

bool PointOnSegment(Point p0, Point p1, Point p2)
{
        return (dcmp(det(p0, p1, p2)) == 0 && dcmp(dot(p0, p1, p2)) <= 0);
}

bool intersect(const Point p0, const Point p1, const Point p2)
{
        if (dcmp(dis(p0, p1) - r) <= 0 || dcmp(dis(p0, p2) - r) <= 0) return true;
        double d, d12, dx, dy;
        Point cp1, cp2;
        d = fabs(PointLine(p0, p1, p2, cp1));
        if (d > r) return false;
        if (dcmp(d - r) == 0) return PointOnSegment(cp1, p1, p2);
        d = sqrt(r * r - d * d) / dis(p1, p2);
        dx = (p2. x - p1. x) * d;
        dy = (p2. y - p1. y) * d;
        cp2. x = cp1. x + dx;  cp2. y = cp1. y + dy;
        cp1. x = cp1. x - dx;  cp1. y = cp1. y - dy;
        return PointOnSegment(cp1, p1, p2) || PointOnSegment(cp2, p1, p2); 
}

void init()
{
        scanf("%d %d %lf", &n, &m, &r);
        for (int i = 1; i <= n; i++)
                scanf("%lf %lf", &p[i]. x, &p[i]. y);
        for (int i = 1; i <= m; i++)
                scanf("%lf %lf", &c[i]. x, &c[i]. y);
}

void prepare()
{
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= n; i++)
            for (int j = i + 2; j <= n; j++)
            {
                g[i][j] = true;
                for (int k = 1; k <= m; k++)
                    if (intersect(c[k], p[i], p[j]))
                    {
                            g[i][j] = false;
                            break;
                    }
                g[j][i] = g[i][j];
            }
        g[1][n] = g[n][1] = false;
}

void solve()
{
        memset(f, 0, sizeof(f));
        for (int l = 2; l <= n; l++)
                for (int i = 1; i <= n + 1 - l; i++)
                {
                        int j = i + l - 1;
                        for (int k = i + 1; k <= j; k++)
                                f[i][j] >?= f[i][k] + f[k][j];
                        if (g[i][j]) f[i][j]++;
                }
        printf("%d\n", f[1][n]);
}

int main()
{
        init();
        prepare();
        solve();
        return 0;
}
