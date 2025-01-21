#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  while (s.size() < t.size()) {
    if (t.back() == 'A') {
      t.pop_back();
    } else if (t.back() == 'B') {
      t.pop_back();
      reverse(t.begin(), t.end());
    }
  }

  cout << (s == t) << endl;
  return 0;
}