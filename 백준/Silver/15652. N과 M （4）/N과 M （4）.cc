#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
vector<int> v;

void func(int idx) {
  if (v.size() == m) {
    for (auto &num : v) {
      cout << num << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = idx; i < n; i++) {
    v.push_back(arr[i]);
    func(i);
    v.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie();

  cin >> n >> m;
  arr.resize(n);

  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
  func(0);
  return 0;
}