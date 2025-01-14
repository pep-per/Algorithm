#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> dp(n + 1, 1e9);
  vector<int> path(n + 1);

  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (dp[i] > dp[i - 1] + 1) {
      dp[i] = dp[i - 1] + 1;
      path[i] = i - 1;
    }
    if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
      dp[i] = dp[i / 2] + 1;
      path[i] = i / 2;
    }
    if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
      dp[i] = dp[i / 3] + 1;
      path[i] = i / 3;
    }
  }
  cout << dp[n] << endl;

  int x = n;
  while (x >= 1) {
    cout << x << " ";
    if (x == 1) break;
    x = path[x];
  }
  return 0;
}