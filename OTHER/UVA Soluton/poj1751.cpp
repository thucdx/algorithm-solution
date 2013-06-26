#include <iostream>
#include <cstring>
using namespace std;
#define  GetDisDB(x0,y0,x1,y1) ((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0))
#define  Max  751
typedef struct
{
	int x,y;
}Point;

int HashConn[Max][Max];
int Map[Max][Max];

bool IsLeft[Max];
int Distance[Max];
int Prev[Max];

Point Value[Max];

void SetZero(int a,int b)
{
	Map[a][b] = 0;
	Map[b][a] = 0;
}

void Build(int n)
{
	int a,b,i,j,v;
	int index = 0;
	int curi,curj;
	
	int pre = 1;
	
	Prev[pre] = 0;

	while(pre)
	{
		IsLeft[pre] = true;
		if(Prev[pre] && !HashConn[pre][Prev[pre]])cout<<pre<<" "<<Prev[pre]<<endl;
		for(i=1;i<=n;i++)
		{
			if(!IsLeft[i] && (Distance[i]<0 || Distance[i]>Map[pre][i]))
			{
				Distance[i] = Map[pre][i];
				Prev[i] = pre;
			}
		}
		pre = 0;
		for(i=1;i<=n;i++)
		{
			if(!IsLeft[i] && Distance[i]>=0 && (pre==0 || Distance[i]<Distance[pre]))
			{
				pre = i;
			}
		}
	}
}


int main()
{
	int i,j,n,p,a,b;
	int v,x,y;

	(cin>>n);
	{
		memset(Map,0,sizeof(int)*Max*Max);
		memset(Value,0,Max*sizeof(Point));
		memset(IsLeft,0,Max*sizeof(bool));
		memset(Distance,-1,Max*sizeof(int));
		
		for(i=1;i<=n;i++)
		{
			cin>>x>>y;
			Value[i].x = x;
			Value[i].y = y;
		}
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		{
		Map[i][j] = GetDisDB(Value[i].x,Value[i].y,Value[j].x,Value[j].y);
		Map[j][i] = Map[i][j];
		}
		cin>>p;
		for(i=1;i<=p;i++)
		{
			cin>>a>>b;
			SetZero(a,b);
			HashConn[a][b] = 1;
			HashConn[b][a] = 1;
		}
		Build(n);
	}

	return 0;
}
