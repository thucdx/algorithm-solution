#include <cstdio>
#include <cstring>

int arr[128];    
int num[60], max[60];         
int under[60][1010], data[60][1010];  
char order[80];      
int noErr, all;

int getNum(int p, int q)
{
   int ans = 0;
   while (p <= q)
      ans = ans * 10 + order[p++] - 48;
   return(ans);
}

void newArr(int len)
{
   ++all;
   arr[ order[0] ] = all;
   num[all] = 0;
   max[all] = getNum(2, len - 2);
}

int get(int p, int q)
{
   int i, j;
   int t;
   if (order[p + 1] != '[')
      return(getNum(p, q));
   
   int now = arr[ order[p] ];
   
   t = get(p + 2, q - 1);
   if (t == -1)
      return(-1);
   else if (now == 0)
      return(-1);
   else
   {
      for (i=1; i <= num[now]; i++)
         if (under[now][i] == t)
            break;
      if (i > num[now])
         return(-1);
      else
         return(data[now][i]);
   }
}

int main()
{
   int i, j, k;
   int x;
   int len;
   int now;
   while (scanf("%s", &order) && order[0] != '.')
   {
      all = noErr = 0;
      x = 0;
      for (i = 65; i <= 127; i++)
         arr[i] = 0;
      while (order[0] != '.')
      {
         ++x;
         if (noErr == 0)
         {
            for (i = 0; order[i] != '=' && order[i] != 0; i++);
            for (len = i; order[len] != 0; len++);
            
            if (i == len)
               newArr(len);
            else
            {
               j = get(i + 1, len - 1);
               i = get(2, i - 2);
               if (i == -1 || j == -1) noErr = x;
               else if (arr[ order[0] ] == 0) noErr = x;
               else if (max[ arr[ order[0] ] ] <= i) noErr = x;
               else
               {
                  now = arr[ order[0] ];
                  for (k=1; k <= num[now]; k++)
                     if (under[now][k] == i)
                        break;
                  if (k > num[now])
                     ++num[now];
                  under[now][k] = i;
                  data[now][k] = j;
                  
                  if (num[now] > max[now])
                     noErr = x;
               }
            }
         }
         scanf("%s", &order);
      }
      printf("%d\n", noErr);
   }
   return(0);
}


