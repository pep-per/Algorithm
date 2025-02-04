#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> top(n);
  for (int i = 0; i < n; i++) {
    cin >> top[i];
  }

  stack<int> idx;
  for (int i = 0; i < n; i++) {
    while (!idx.empty() && top[idx.top()] < top[i]) {
      idx.pop();
    }

    if (idx.empty()) {
      cout << 0 << " ";
    } else {
      cout << idx.top() + 1 << " ";
    }

    idx.push(i);
  }
  cout << '\n';
  return 0;
}
