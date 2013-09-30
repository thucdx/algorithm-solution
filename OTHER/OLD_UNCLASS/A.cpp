#include <iostream>

using namespace std;
#include <conio.h>

string getName(int day);
#define SIZE 3
int main()
{
    typedef enum 
    {
        monday = 0,
        tuesday = 1,
        wednesday = 2
    } DAY;
    
    DAY day = wednesday;
    DAY nextDay = (DAY)((int)day + 1);
    
    if((int)nextDay == SIZE) nextDay = monday;
    
    cout << getName(nextDay) <<endl;

    getch();
}

string getName(int day)
{
    switch(day)
    {
        case 0 : return "monday";
        case 1 : return "tuesday";    
    }
}


