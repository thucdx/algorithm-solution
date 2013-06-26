#include <stdio.h>
//#include <conio.h>

int main()
{
    int n,f[100001],a[100001],t;
    freopen("LIS.IN", "rt", stdin);
    freopen("LIS-H.OUT", "wt", stdout); 
    scanf("%d",&n);
    for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
    t = 1;
    f[1] = a[1];
    for(int i = 2;i<=n;i++)
    {
        if(a[i]>f[t])
        {
            t++;
            f[t] = a[i];
        }
        else if(a[i]<=f[1]) f[1] = a[i];
        else
        {
            int u = 1,v = t,r;
            while(v-u>1)
            {
                r = (u+v)/2;
                if(a[i]>f[r])
                    u = r;
                else v = r;
            }
        f[v] = a[i];
        }
    }
    printf("%d",t);
    //getch();
}
    

