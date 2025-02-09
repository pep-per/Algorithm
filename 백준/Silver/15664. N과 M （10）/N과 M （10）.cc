#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  vector<int> bit(n, 0);
  fill(bit.end() - m, bit.end(), 1);

  set<vector<int>> combs;

  do {
    vector<int> comb;
    for (int i = 0; i < n; i++) {
      if (bit[i]) comb.push_back(arr[i]);
    }
    combs.insert(comb);
  } while (next_permutation(bit.begin(), bit.end()));

  for (const auto& comb : combs) {
    for (int num : comb) {
      cout << num << " ";
    }
    cout << '\n';
  }

  return 0;
}
