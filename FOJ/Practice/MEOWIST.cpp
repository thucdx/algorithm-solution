#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Meo {
   string name;
   int age;

   Meo(){}

   Meo(string _n, int _a) {
      name = _n, age = _a;
   }

   bool operator<(const Meo& other) const {
      if (age != other.age) return age > other.age;
      return name < other.name;
   }
};

vector<Meo> v;

int main() {
   /*
   freopen("in", "r", stdin);
   freopen("out", "w", stdout);
   //*/
   int age;
   string s;
   while (cin >> s) {
         cin >> age;
         v.push_back(Meo(s, age));
   }
   sort(v.begin(), v.end());
   for (int i = 0; i < v.size(); ++i) {
      cout << v[i].name << endl;
   }
}

