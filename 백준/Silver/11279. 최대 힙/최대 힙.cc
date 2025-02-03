#include <stdio.h>

#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  priority_queue<int, vector<int>> pq;

  int n;
  cin >> n;

  while (n--) {
    int x;
    cin >> x;

    if (x != 0) {
      pq.push(x);
    } else if (pq.empty()) {
      cout << 0 << '\n';
    } else {
      cout << pq.top() << '\n';
      pq.pop();
    }
  }
  return 0;
}