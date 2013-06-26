#include <iostream>
using namespace std;
struct Tcube
{
        int x, length;
};
struct Tline
{
        int x1, x2;
};
void sight(Tcube* kadj, Tline* see, const int& n)
{
        for(int i = 0; i < n; ++i)
        {
            see[i].x1 = kadj[i].x - kadj[i].length;
            see[i].x2 = kadj[i].x + kadj[i].length;
        }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if (i != j 
                && kadj[i].length > kadj[j].length 
                && kadj[i].x - kadj[i].length <= see[j].x1 
                && kadj[i].x + kadj[i].length > see[j].x1)
                {
                    if (kadj[i].x + kadj[i].length >= see[j].x2)
                        see[j].x1 = see[j].x2;
                    else
                        see[j].x1 = kadj[i].x + kadj[i].length;
                }
}
int main()
{
        int n;
        while(scanf("%d", &n) && n)
        {
            Tcube *kadj = new Tcube[n];
            Tline *see = new Tline[n];
            int b;
            for(int i = 0; i < n; ++i)
            {        
                scanf("%d", &b);
                kadj[i].length = b;
                if (!i)
                    kadj[i].x = b;
                else
                {
                    if (b <= kadj[i - 1].length)
                        kadj[i].x = kadj[i - 1].x + (b << 1);
                    else
                    {
                        int limitDis = 0;
                        int k;
                        for(k = i - 1; k >= 0; --k)
                        {
                            int tmp = kadj[k].x + ((b < kadj[k].length ? b : kadj[k].length) << 1);
                            if (limitDis < tmp)
                                limitDis = tmp;
                            if (b <= kadj[k].length)
                                break;
                        }
                        if (k < 0 && b >= limitDis)
                            kadj[i].x = b;
                        else
                            kadj[i].x = limitDis;
                    }
                }
            }
            sight(kadj, see, n);
            bool flag = true;
            for(int i = 0; i < n; ++i)
                if (see[i].x1 != see[i].x2)
                {
                    printf(flag ? "%d" : " %d", i + 1);
                    flag = false;
                }
            printf("\n");
            delete[] kadj;
            delete[] see;
        } 
        return 0;
}
