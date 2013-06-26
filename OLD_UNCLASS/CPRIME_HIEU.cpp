#include <cstdio>
#include <conio.h>
#include <math.h>
#define lon 100000000
#define doc(n) ( bpc[n/13]&(1<<(n%13)))
#define set(n) { bpc[n/13]|=(1<<(n%13));}
int bpc[6500000];

int main()
{
    freopen("CPRIME.in","r",stdin);
    freopen("CPRIME_HIEU.out","wt",stdout);    
    set(0);
    for(int i = 3;i*i<= lon;i+=2)
    {  
        if(!doc(i/2))
        {
             for(int j = i*i;j<=lon;j+=2*i){set(j/2);}
        }
    }
    int a[1010],vt[1010],so=0,temp,pi[1010],m;
    while(scanf("%d",&a[++so])>0&&a[so]>0);
    so--;
    for(int i = 1;i<=so;i++)
         vt[i] = i;
    for(int i = 1;i<=so;i++)
         for(int j = i+1;j<=so;j++)
         {
              if(a[i]>a[j])
              {
                   temp = a[i];
                   a[i] = a[j];
                   a[j] = temp;
                   temp = vt[i];
                   vt[i] = vt[j];
                   vt[j] = temp;
              }
         }
    int n = 2,chay = 1;
    for(int i = 1;i<=so;i++)
    {
        while(n<a[i])
        {
             n++;
             if((n%2)&&!doc(n/2))
                  chay++;
        }
        pi[i] = chay;
    }
    for(int i = 1;i<=so;i++)
         for(int j = i+1;j<=so;j++)
         {
              if(vt[i]>vt[j])
              {
                   temp = vt[i];
                   vt[i] = vt[j];
                   vt[j] = temp;
                   temp = pi[i];
                   pi[i] = pi[j];
                   pi[j] = temp;
                   temp = a[i];
                   a[i] = a[j];
                   a[j] = temp;
                                            
              }
         }
    for(int i = 1;i<=so;i++)
         printf("%.1lf\n",fabs((pi[i]-a[i]/log(a[i]))/(0.01*pi[i])));
   //getch();
}

