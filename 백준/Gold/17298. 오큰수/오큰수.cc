#include <stdio.h>

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> arr;
  stack<int> s;

  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr.push_back(x);
  }

  vector<int> nge(n, -1);

  for (int i = 0; i < n; i++) {
    while (!s.empty() && arr[s.top()] < arr[i]) {
      nge[s.top()] = arr[i];
      s.pop();
    }
    s.push(i);
  }

  for (int i = 0; i < n; i++) {
    cout << nge[i] << " ";
  }
  cout << "\n";

  return 0;
}