#include <iostream>
using namespace std;

int convertDay(int day, int month, int year);

int main()
{
    int num;
    cin >> num;

    for(int ind = 0; ind < num; ind++)
    {
        int day1, month1, year1, month2, day2; 
        scanf("%d/%d/%d %d/%d", &month1, &day1, &year1, &month2, &day2);
        bool check = 0;
        int docu = convertDay(day1, month1, year1);
        for(int year2 = year1-1; year2<=year1+1; year2++)
        {
             int second = convertDay(day2, month2, year2);
             int dif = second - docu;
             if(dif>=-7&&dif<-1)
             {
                  cout << (ind+1) << " " << month2 << "/" << day2 << "/" << year2 << " IS " << -dif << " DAYS PRIOR" << endl;
                  check = 1;                   
                  break;
             }
             else if(dif==-1)
             {
                  cout << (ind+1) << " " << month2 << "/" << day2 << "/" << year2 << " IS 1 DAY PRIOR" << endl;
                  check = 1;                   
                  break;
             }
             else if(dif==0)
             {
                  cout << (ind+1) << " SAME DAY" << endl;
                  check = 1;                   
                  break;
             }
             else if(dif==1)
             {
                  cout << (ind+1) << " " << month2 << "/" << day2 << "/" << year2 << " IS 1 DAY AFTER" << endl;
                  check = 1;                   
                  break;
             }
             if(dif>=2&&dif<=7)
             {
                  cout << (ind+1) << " " << month2 << "/" << day2 << "/" << year2 << " IS " << dif << " DAYS AFTER" << endl;
                  check = 1;                   
                  break;
             }
        }
        if(check==0)
            cout << (ind+1) << " OUT OF RANGE" << endl;
    }
}

int convertDay(int day, int month, int year)
{
    //1/1/1996 is the first day
    int offsetOfNormalMonths[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int offsetOfLeapMonths[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
    int result = 0;
    result += (year-1996)*365;
    if(year%4==0&&year!=2100)
         result += offsetOfLeapMonths[month-1];
    else
         result += offsetOfNormalMonths[month-1];
    result += day;
    int numOfLeaps = (year-1996)/4;
    if(year>=2100)
        numOfLeaps--;
    result += numOfLeaps;
    if(year%4==0&&year!=2100)
        result--;
    
    return result;
}
