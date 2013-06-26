#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
using namespace std::rel_ops;

const int MAX_TRIPS = 100;

const int daysInMonth[2][13] = {
  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
  { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

bool isLeap(int y)
{
  return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

struct Date
{
  int m, d, y;

  Date(int mm = 1, int dd = 1, int yy = 2000)
    : m(mm), d(dd), y(yy) { }

  bool operator<(const Date &date) const
  {
    if (y != date.y) return y < date.y;
    if (m != date.m) return m < date.m;
    return d < date.d;
  }

  bool operator==(const Date &date) const
  {
    return y == date.y && m == date.m && d == date.d;
  }
  
  void inc()
  {
    if (d++ == daysInMonth[isLeap(y)][m]) {
      d = 1;
      if (m++ == 12) {
	m = 1;
	y++;
      }
    }
  }

  void dec()
  {
    if (d-- == 1) {
      if (m-- == 1) {
	m = 12;
	y--;
      }
      d = daysInMonth[isLeap(y)][m];
    }
  }
};

istream &operator>>(istream &is, Date &date)
{
  char c;
  return is >> date.m >> c >> date.d >> c >> date.y;
}

ostream &operator<<(ostream &os, const Date &date)
{
  return os << date.m << '/' << date.d << '/' << date.y;
}

typedef pair<Date, Date> pdd;

bool intrip(const Date &d, pdd trips[], int N)
{
  for (int i = 0; i < N; i++) {
    if (trips[i].first <= d && d <= trips[i].second) {
      return true;
    }
  }
  return false;
}
	    
bool solve()
{
  Date reside, landing;
  if (!(cin >> reside >> landing)) {
    return false;
  }
  
  int N;
  pdd trips[MAX_TRIPS];

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> trips[i].first >> trips[i].second;
  }

  // start is the first date to be counted in the window
  // app is the application date to be considered
  // len is the number of days in [start, app)
  // count is twice the number of days to be counted
  Date start = landing;
  int len = 0;
  while (len < 730 && reside < start) {
    start.dec();
    len++;
  }
  Date app = landing;     // first date of application is 2 years from landing
  for (int i = 0; i < 730; i++) {
    app.inc();
  }
  len += 730;

  int count = 0;
  for (Date d = start; d != app; d.inc()) {
    if (!intrip(d, trips, N)) {
      count += (d < landing) ? 1 : 2;
    }
  }

  while (count < 1095*2) {
    // move application forward by 1
    if (!intrip(app, trips, N)) {
      count += 2;
    }
    app.inc();
    len++;
    while (len > 1460) {
      // move start date forward by 1
      if (!intrip(start, trips, N)) {
	count -= (start < landing) ? 1 : 2;
      }
      start.inc();
      len--;
    }
  }
  cout << app << endl;
  return true;
}

int main()
{
  while (solve())
    ;
  return 0;
}
