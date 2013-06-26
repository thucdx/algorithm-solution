#include <iostream>
#include <set>
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <cassert>

using namespace std;

void cleanname(string &s)
{
  string::iterator it;

  it = remove(s.begin(), s.end(), '\'');
  it = remove(s.begin(), it, '-');
  s.resize(it - s.begin());
}

bool solve(int id)
{
  unsigned num, maxlen;
  string line;

  cin >> num >> maxlen;
  if (!num && !maxlen) return false;

  getline(cin, line);
  
  cout << "Case " << id << endl;

  set<string> usernames;
  for (unsigned i = 0; i < num; i++) {
    getline(cin, line);
    istringstream iss(line);
    
    string first, last, temp;
    iss >> first;
    while (iss >> temp) {
      last = temp;
    }

    cleanname(first);
    cleanname(last);
    
    string name;
    bool done = false;
    name += tolower(first[0]);
    for (unsigned int i = 0; i < last.length() && name.length() < maxlen;
	 i++) {
      name += tolower(last[i]);
    }

    if (usernames.count(name) == 0) {
      usernames.insert(name);
      cout << name << endl;
      done = true;
    }

    for (int i = 1; i <= 9 && !done; i++) {
      string name2 = name;
      if (name2.length() == maxlen) {
	name2.erase(maxlen-1);
      }
      name2 += (char)('0'+i);

      if (usernames.count(name2) == 0) {
	usernames.insert(name2);
	cout << name2 << endl;
	done = true;
      }
    }

    for (int i = 10; i <= 99 && !done; i++) {
      string name2 = name;
      if (name2.length() == maxlen) {
	name2.erase(maxlen-1);
      }
      if (name2.length() == maxlen-1) {
	name2.erase(maxlen-2);
      }
      
      name2 += (char)('0'+ (i/10));
      name2 += (char)('0'+ (i%10));

      if (usernames.count(name2) == 0) {
	usernames.insert(name2);
	cout << name2 << endl;
	done = true;
      }
    }

    assert(done);
  }


  return true;
}

int main()
{
  int id = 1;
  while (solve(id++))
    ;
  
  return 0;
}
