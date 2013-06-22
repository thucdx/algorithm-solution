#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
//   freopen("in", "r", stdin);
//   freopen("out", "w", stdout);

	int ntest;
	scanf("%d", &ntest);
	double xa, xb, xc, a, s, b, c, d, r;
	while (ntest--) {
      scanf("%lf %lf %lf %lf", &a, &xa, &xb, &xc);
		s = xa * a;
		b = s / xb;
		c = s / xc;
		r = a * b * c / (6.0 * s);
		d = 4.0 * (r * r - (a * a + b * b + c * c)/9.0);
		d = d < 0.0 ? 0.0 : d;
		printf("%.3lf %.3lf\n", 1.5*s, sqrt(d));
	}
}



