#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
int n;
void calc();
struct Point{
	char p;
	int x,y;
};
Point point[27];
int main(){
	//freopen("input.txt","rt", stdin);
	//freopen("output.txt","wt", stdout);
	int i,nSet=0;;

	do
	{
		cin>>n;
		if(n==0) break;
		nSet++;
		cout<<"Point set "<<nSet<<": ";
		for(i=1;i<=n;i++){

			cin>>point[i].p>>point[i].x>>point[i].y;
		}
		calc();
	}
	while(true);

}
void calc()
{
	int nRec=0;
	int i,j,k,l;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				for(l=1;l<=n;l++)
				{
					if(point[i].y==point[j].y && point[i].x< point[j].x
						&& point[j].x==point[k].x  && point [k].y<point[j].y
						&& point[k].y==point[l].y  && point [k].x>point[l].x
						&& point[l].x==point[i].x  && point [l].y<point[i].y)
					{
						if(nRec%10==0) cout<<endl;
						nRec++;
						cout<<point[i].p<<point[j].p<<point[k].p<<point[l].p<<' ';

					}


				}
				if(nRec==0) cout<<"No rectangles";
				cout<<endl;

}

