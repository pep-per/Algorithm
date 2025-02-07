#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>>
      pq;
  vector<vector<int>> map(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
      pq.push({map[i][j], {i, j}});
    }
  }

  vector<vector<int>> dp(n, vector<int>(n, 1));
  vector<vector<bool>> vis(n, vector<bool>(n, false));
  vector<pair<int, int>> direct = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  int result = 0;
  while (!pq.empty()) {
    int x, y, w;
    w = pq.top().first;
    tie(x, y) = pq.top().second;
    pq.pop();
    vis[x][y] = true;

    for (auto &dir : direct) {
      int dx = dir.first;
      int dy = dir.second;
      int nx = x + dx;
      int ny = y + dy;

      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (vis[nx][ny] == true && map[x][y] < map[nx][ny]) {
        dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
      }
    }
    result = std::max(result, dp[x][y]);
  }
  cout << result << '\n';
  return 0;
}
