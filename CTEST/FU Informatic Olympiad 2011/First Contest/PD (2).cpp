#include <iostream>
using namespace std;

int main()
{
        double kg_ps = 2.2046;
        double ps_kg = 0.4536;
        double lt_ga = 0.2642;
        double ga_ls = 3.7854;
        int num = 0;
        cin >> num;
        for(int ind = 0; ind < num; ind++)
        {
            double in;
            char un[100];
            cin >> in >> un;

            if(un[0]=='k'&&un[1]=='g')
            {
                double tpRes = in*kg_ps;
                printf("%d %.4lf lb", (ind+1), tpRes);
            }
            else if(un[0]=='l'&&un[1]=='b')
            {
                double tpRes = in*ps_kg;
                printf("%d %.4lf kg", (ind+1), tpRes);
            }
            else if(un[0]=='l')
            {
                double tpRes = in*lt_ga;
                printf("%d %.4lf g", (ind+1), tpRes);
            }
            else
            {
                double tpRes = in*ga_ls;
                printf("%d %.4lf l", (ind+1), tpRes);
            }
        }
}
