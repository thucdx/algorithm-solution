#include <math.h>
#include <algorithm>
using namespace std;

double pi = acos(-1.0);

double angle(double x,double y){
	double a;
	double r = sqrt(x*x + y*y);
	if (y >= 0) a = acos(x/r);
	else a = 2 * pi - acos(x/r);
	return a;
}

int main(){
    double r, x1, y1, x2, y2, x3, y3;
    bool mk;
    double a[3];
    int cases; scanf("%d",&cases);
    while(cases--){
        scanf("%lf%lf%lf%lf%lf%lf%lf", &r, &x1, &y1, &x2, &y2, &x3, &y3);
        if(x1==0&&y1==0 || x2==0&&y2==0 || x3==0&&y3==0){
            printf("No\n");  continue;
        }
        mk = 1;
        a[0] = angle(x1, y1);
        a[1] = angle(x2, y2);
        a[2] = angle(x3, y3);
        sort(a, a + 3);
        if(a[2]-a[0] <= pi/1.5) mk = 0;
        if(a[1]+2*pi-a[2] <= pi/1.5) mk = 0;
        if(a[0]+2*pi-a[1] <= pi/1.5) mk = 0;

        if(mk)printf("Yes\n");else printf("No\n");
    }
    return 0;
}
