#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, n, m;
  cin >> t >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  unordered_map<int, int> sums;
  vector<int> prefixA(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    prefixA[i] = prefixA[i - 1] + a[i - 1];
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int sum = prefixA[j] - prefixA[i];
      sums[sum]++;
    }
  }

  vector<int> prefixB(m + 1, 0);

  for (int i = 1; i <= m; i++) {
    prefixB[i] = prefixB[i - 1] + b[i - 1];
  }

  long long result = 0;
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j <= m; j++) {
      int sum = prefixB[j] - prefixB[i];
      auto it = sums.find(t - sum);
      if (it != sums.end()) {
        result += it->second;
      }
    }
  }

  cout << result << endl;
  return 0;
}