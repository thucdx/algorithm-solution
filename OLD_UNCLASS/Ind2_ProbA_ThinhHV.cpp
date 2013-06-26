#include  <iostream>
#include  <fstream>
#include <string.h>
#include <stdlib.h>
using  namespace   std;
char emoticon[1000][100], message[1000][200];
long m,n;
void   nhap()
{
       char str[1000];
       cin>>n>>m;
       gets(str);
       for (int i=1; i<=n; i++)
       {
           gets(emoticon[i]);
       }
       for (int i=1; i<=m; i++)
       {
           gets(message[i]);
       }
}

void   tim()
{
       long tong = 0;
       for (int i=1; i<=m; i++)
       {
           int mesLen = strlen(message[i]);
           for (int j=mesLen-1;j>=0;j--)
           {
               for (int k=1; k<=n; k++)
               {
                   if (strstr(message[i]+j,emoticon[k]))
                   {
                      tong++;
                      message[i][j]='\0';
                      break;
                   }
               }
           }
       }
       cout<<tong;
}
int   main()
{
   nhap();
   while (n!=0||m!=0)
   {
     tim();
     nhap();
     if (n!=0||m!=0) cout<<endl;
   }
  // system("pause");
   //cout<<1<<endl;
}
