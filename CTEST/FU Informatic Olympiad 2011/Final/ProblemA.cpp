#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct A
{
    int num;
    char name[30];
    char wei;
    int time;
} a[300],b[300];

int cmp1(const void *c,const void *d)
{
    return *(int *)c-*(int *)d;
}
int main ()
{
    int i,j,l,t1,d,m,ss,g,k,max;
    int d1,m1,s1,g1;
    char s[1000]; 
    while (1)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        d1=m1=s1=g1=0;
        for (i=0;i<22;i++)
        {
            scanf("%d",&a[i].num);
            if (i==0 && a[i].num==0)
                return 0;
            scanf(" %s %c ",&a[i].name,&a[i].wei);
            if (a[i].wei=='S')
                s1++;
            else if (a[i].wei=='G')
                g1++;
            else if (a[i].wei=='D')
                d1++;
            else
                m1++;
            a[i].time=0;
            memset(s,0,sizeof(s));
            gets(s);
            l=strlen(s);
            j=0;
            while (j<l)
            {
                t1=0;
                while (s[j]!='-')
                {
                    t1=t1*10+s[j]-'0';
                    j++;
                }
                a[i].time-=t1;
                j++;
                t1=0;
                while (s[j]!=' '&& j<l)
                {
                    t1=t1*10+s[j]-'0';
                    j++;
                }
                a[i].time+=(t1+1);
                j++;
                while (s[j]==' ')
                    j++;
            }
        }
        qsort(a,22,sizeof(a[0]),cmp1);
        scanf("%d-%d-%d",&d,&m,&ss);
        g=1;
        if (g1<g || s1<ss || d1<d || m1<m)
        {
            printf ("IMPOSSIBLE TO ARRANGE\n");
        }
        else
        {
            i=0;
            k=0;
            while (g)
            {
                if (a[i].wei=='G')
                {
                    b[k++]=a[i];
                    g--;
                }
                i++;
            }
            i=0;
            while (d)
            {
                if (a[i].wei=='D')
                {
                    b[k++]=a[i];
                    d--;
                }
                i++;
            }
            i=0;
            while (m)
            {
                if (a[i].wei=='M')
                {
                    b[k++]=a[i];
                    m--;
                }
                i++;
            }
            i=0;
            while (ss)
            {
                if (a[i].wei=='S')
                {
                    b[k++]=a[i];
                    ss--;
                }
                i++;
            }
            max=0;
            for (i=0;i<11;i++)
            {
                if (b[i].time>b[max].time || (b[i].time==b[max].time && b[i].num>b[max].num))
                    max=i;
            }
            printf ("%d %s %c\n",b[max].num,b[max].name,b[max].wei);
            for (i=0;i<k;i++)
            {
                if (i!=max)
                    printf ("%d %s %c\n",b[i].num,b[i].name,b[i].wei);
            }
        }
        printf ("\n");
    }
    return 0;
}
