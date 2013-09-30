#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int getIndexMedian(vector<double> a);

int main()
{
        vector<double>  vd;
        vd.clear;
        vd.push_back(1.0);
        vd.push_back(2.0 );
        vd.push_back(-1.0 ); 
        vd.push_back(5.0 );
        cout<<vd[getIndexMedian(vd)];       
        getch();
}
