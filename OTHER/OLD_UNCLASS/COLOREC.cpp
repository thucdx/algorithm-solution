#include<iostream.h>
#include<stdio.h>
long a[405][405],n,i1,j1,i2,j2,kq;
int nhap();
int xuli();
int inkq();
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    nhap();
    xuli();
    inkq();
    return 0;
}
int nhap()
{
    cin >> n;
    long i,u,v,c;
    for (i=1;i<=n;i++)
    {
        scanf("%d %d %d",&u,&v,&c);
        a[u+200][v+200]=1<<(c-1);
    }
    return 0;
}
int xuli()
{
    long i,j,s[20],k,l;
    kq=0;
    for (i=0;i<=400;i++)
    for (j=i+1;j<=400;j++)
    {
        for (k=0;k<=19;k++) s[k]=0;
        for (k=0;k<=400;k++) s[a[i][k]+a[j][k]]++;
        kq+=s[3]*s[12]+s[5]*s[10]+s[9]*s[6];
    }
}
int inkq()
{
    cout << kq;
}
lor-1];
	}
}
void count(){
	int num=0;
	int s[19];
	int i,j,k;
	for(i=0;i<max-1;++i)
		for(j=i+1;j<max;++j)
		{//chon 2 cot i,j
			//khoi tao mang.
			for(k=0;k<=18;k++)
				s[k]=0;
			for(k=0;k<max;k++){
				int a=table[k][i];
				int b=table[k][j];
				if(a==0 ||b==0 ||(a==b)) continue;
				++s[a+b];
			}
			num+=s[3]*s[12]+ s[5]*s[10]+s[9]*s[6];
		}
	cout<<num<<endl;
}
