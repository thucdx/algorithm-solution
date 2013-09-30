
      #ifndef ONLINE_JUDGE
      freopen("input.txt","rt", stdin);
      freopen("output.txt","wt",stdout);
      #endif
       
      #include <iostream>
      using namespace std;
   8.
      #include <math.h>
   9.
       
  10.
       
  11.
      int MOD(int a, int n, int m);//a^n mod m
  12.
      void Jacobi(int a,int p);
  13.
       
  14.
       
  15.
      int main()
  16.
      {
  17.
      int numberOfTest;
  18.
      int a,p,i;
  19.
       
  20.
      cin>>numberOfTest;
  21.
      i=1;
  22.
      do
  23.
      {
  24.
      cin >>a>>p;
  25.
      Jacobi(a,p);
  26.
      i++;
  27.
      }
  28.
      while(i<=numberOfTest);
  29.
      }
  30.
      int MOD(int a, int n, int m)//a^n mod m
  31.
      {
  32.
      int rs=1;
  33.
      int x=a%m,i=0,j;
  34.
      int save=x;
  35.
      while(n>0)
  36.
      {
  37.
      if(n%2==1)
  38.
      rs=(rs*save)%m;
  39.
      save=(save*save)%m;
  40.
      n=n/2;
  41.
      }
  42.
      return rs;
  43.
      }
  44.
      void Jacobi(int b,int n)
  45.
      {
  46.
      int a=b %n;
  47.
      if(MOD(a,(n-1)/2,n)!=1)
  48.
      {
  49.
      cout<<"Khong co"<<endl;
  50.
      return;
  51.
      }
  52.
  53.
      int i;
  54.
      int k=(int)sqrt((double)a);
  55.
      int bp=(k*k)%n;
  56.
      if(bp==a)
  57.
      {
  58.
      cout<<k<<' '<<n-k<<endl;
  59.
      return;
  60.
      }
  61.
      for(i=k+1;i<=(n-1)/2;i++)
  62.
      {
  63.
      bp=(bp+2*i-1)%n;
  64.
      if(bp==a)
  65.
      {
  66.
      cout<<i<<' '<<n-i<<endl;
  67.
      return;
  68.
      }
  69.
      }
  70.
      if(i==(n-1)/2+1)
  71.
      cout<<"Khong co"<<endl;
  72.
      return;
  73.
      } 
