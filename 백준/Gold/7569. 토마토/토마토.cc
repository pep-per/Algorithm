#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int map[102][102][102] = {
      0,
  };
  int dist[102][102][102];
  int m, n, h;
  int dx[6] = {-1, 0, 1, 0, 0, 0};
  int dy[6] = {0, -1, 0, 1, 0, 0};
  int dz[6] = {0, 0, 0, 0, 1, -1};

  cin >> m >> n >> h;

  for (int i = 0; i < h; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < m; k++) dist[i][j][k] = -1;

  queue<pair<pair<int, int>, int>> q;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        cin >> map[i][j][k];
        if (map[i][j][k] == 1) {
          q.push({{i, j}, k});
          dist[i][j][k] = 0;
        } else if (map[i][j][k] == -1) {
          dist[i][j][k] = 0;
        }
      }
    }
  }

  while (!q.empty()) {
    int z = q.front().first.first;
    int y = q.front().first.second;
    int x = q.front().second;
    q.pop();

    for (int dir = 0; dir < 6; dir++) {
      int nz = z + dz[dir];
      int ny = y + dy[dir];
      int nx = x + dx[dir];

      if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
      if (map[nz][ny][nx] == -1 || dist[nz][ny][nx] != -1) continue;

      dist[nz][ny][nx] = dist[z][y][x] + 1;
      q.push({{nz, ny}, nx});
    }
  }

  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (dist[i][j][k] == -1) {
          cout << -1;
          return 0;
        }
        ans = max(ans, dist[i][j][k]);
      }
    }
  }

  cout << ans;
  return 0;
}
