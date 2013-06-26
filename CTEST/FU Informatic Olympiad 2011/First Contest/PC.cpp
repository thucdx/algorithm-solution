#include <iostream>
using namespace std;

int main()
{
    long long int num = 0;
    cin >> num;
    for(int ind = 0; ind < num; ind++)
    {
        long long int k;
        cin >> k;
        long long int r = k*(k+1)*(k*k+5*k+6)/8;
        cout << (ind+1) << " " << k << " " << r << endl;
    }
}
