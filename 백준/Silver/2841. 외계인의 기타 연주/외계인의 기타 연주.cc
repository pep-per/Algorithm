#include <iostream>
#include <stack>

using namespace std;

int main() {
  int n, p;
  cin >> n >> p;

  stack<int> s[7];
  int move = 0;

  int num, fret;
  for (int i = 0; i < n; i++) {
    cin >> num >> fret;

    while (!s[num].empty() && s[num].top() > fret) {
      s[num].pop();
      move++;
    }

    if (s[num].empty() || s[num].top() != fret) {
      s[num].push(fret);
      move++;
    }
  }

  cout << move << endl;
  return 0;
}
