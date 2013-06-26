#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

map<int,vector<pair<int,int> > >    M;
map<int,vector<pair<int,int> > >::iterator  it;
vector<pair<int,int> >::iterator    i;
multiset<int, greater<int> >    S;
 
int main() 
{
	int    N, L, a, b, h, opens, k;
	__int64  s;

	while (scanf("%d", &N) != EOF)
	{
        s = 0;
        M.clear();  S.clear();
        while(N--) 
        {
		  scanf("%d %d %d", &a, &b,&h);
		  M[a]. push_back( make_pair(h,1) );
		  M[b]. push_back( make_pair(h,0) );
	    }
	    a = 0;
	    for (it = M.begin(); it != M.end(); it++) 
        {
		    b = it->first;
		    if (!S.empty()) s += (__int64)(b - a)*( *S.begin() );
		    a = b;
		    for ( i = (it->second).begin(); i!=(it->second).end(); i++) 
            {
			    k = i->first;
			    opens = i->second;
			    if (opens) S.insert(k);
			        else S.erase( S.find(k) );
		    }
	    }
	    printf("%I64d\n",s);
    }
	return 0;
}

