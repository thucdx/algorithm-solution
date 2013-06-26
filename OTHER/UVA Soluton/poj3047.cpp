#include <algorithm>
using namespace std;

const int D[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char ANS[7][10] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };

struct Date
{
    int year, month, day;
    Date(int y = 0, int m = 0, int d = 0)
        : year(y), month(m), day(d) {}
    bool operator < (Date &a)
    {
        if (year < a. year) return true;
        if (year == a. year && month < a. month) return true;
        if (year == a. year && month == a.month && day < a. day) return true;
        return false;
    }
};

Date a, b(1900, 1, 1);

bool special(int x)
{
    if (x % 400 == 0) return true;
    if (x % 100 != 0 && x % 4 == 0) return true;
    return false; 
}

int daysA(Date x)
{
    int days[13], ret = 0;
    memcpy(days, D, sizeof(days));
    if (special(x. year))
        days[2] = 29;
    int t = x. month;
    while (t > 1)
    {
        ret += days[t - 1];
        t--;
    }
    ret += x. day;
    return ret;
}

int daysB(Date x)
{
    int days[13], ret = 0;
    memcpy(days, D, sizeof(days));
    if (special(x. year))
        days[2] = 29;
    int t = x. month;
    while (t < 12)
    {
        ret += days[t + 1];
        t++;
    }
    ret += days[x. month] - x. day;
    return ret;
}

void solve_A()
{
    int days = 0;
    int p = daysB(a);
    if (a. year + 1 < b. year) 
    {   a. year++;
        while (a. year + 1 < b. year)
        {
            if (special(a.year)) days += 366; else days += 365;        
            a. year++;
        }
    }
    days += p;
    days++;
    printf("%s\n", ANS[6 - days % 7]);
}

void solve_B()
{
    int days = 0;
    int p = daysA(a);
    while (b. year < a. year)
    {
        if (special(b.year)) days += 366; else days += 365;
        b.year++;
    }    
    days += p;
    days--;
    printf("%s\n", ANS[days % 7]);
}

int main()
{
    scanf("%d %d %d", &a. year, &a. month, &a. day);
    if (a < b) solve_A();
    else solve_B();
    return 0;
}
