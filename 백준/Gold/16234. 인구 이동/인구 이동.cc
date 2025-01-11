#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n, l, r;
  cin >> n >> l >> r;

  vector<vector<int>> map(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  vector<pair<int, int>> direct = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int days = 0;

  while (true) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    bool moved = false;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (visited[i][j]) continue;

        queue<pair<int, int>> q;
        vector<pair<int, int>> united;
        int total = map[i][j];

        q.push({i, j});
        united.push_back({i, j});
        visited[i][j] = true;

        while (!q.empty()) {
          auto [x, y] = q.front();
          q.pop();

          for (auto& [dx, dy] : direct) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
              int diff = abs(map[x][y] - map[nx][ny]);
              if (diff >= l && diff <= r) {
                q.push({nx, ny});
                united.push_back({nx, ny});
                visited[nx][ny] = true;
                total += map[nx][ny];
                moved = true;
              }
            }
          }
        }

        if (united.size() > 1) {
          int population = total / united.size();
          for (auto& [ux, uy] : united) {
            map[ux][uy] = population;
          }
        }
      }
    }

    if (!moved) break;
    days++;
  }

  cout << days << endl;
  return 0;
}