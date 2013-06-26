#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdio>
using namespace std;
double eps[]={1e-0,1e-1,1e-2,1e-3,1e-4,1e-5,1e-6,1e-7,1e-8,1e-9,1e-10};
double f;
char c[30];
inline void farey(double r, double epsilon);
inline int getDec()
{   
    string s=c;
    f=0.0;
    int i,j,len=s.length();
    stringstream ss;
    ss<<s;
    ss>>f;
    f=f-(int)f;
    return len-2;
}

int find();
int main()
{   
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int count=0;
    do
    {   
        ++count;
        scanf("%s",c);
        if(c[0]=='-') break;
        printf("Case %d: ",count);
        int k= getDec();
        farey(f,5*eps[k+1]);
    } while(true);       
}

void farey(double r, double epsilon)
{
    int a, b, c, d, h, k, done;
    double error;

    /* Step 1 */
    a = 0;  b = c = d = 1;

    done = false;
    do {
        /* Step 2 */
        h = a + c;
        k = b + d;

        /* Step 3 */
        error = r - ((double) h) / k;

        /* Step 4 */
        
        if ( fabs(error) < epsilon )
            done = true;

        /* Step 5 */
        if (error > 0) {
            a = h;
            b = k;
        }

        /* Step 6 */
        if (error < 0) {
            c = h;
            d = k;
        }

    } while ( ! done );
    printf("%d\n",k);
    /* print values of h and k */

} /* end of farey() */
    
    
