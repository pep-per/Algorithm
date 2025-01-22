#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define X first
#define Y second

int main() {
  int r, c, t;
  cin >> r >> c >> t;

  vector<vector<int>> map(r, vector<int>(c, 0));
  pair<int, int> puriUp;
  pair<int, int> puriDown;
  bool isMinus = false;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> map[i][j];
      if (map[i][j] == -1) {
        if (!isMinus) {
          puriUp = {i, j};
          isMinus = true;
        } else
          puriDown = {i, j};
      }
    }
  }

  vector<pair<int, int>> direct = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  while (t-- > 0) {
    // 먼지 확산
    vector<vector<int>> temp = map;

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (map[i][j] <= 0) continue;

        int dust = map[i][j] / 5;
        int count = 0;

        for (auto& [dx, dy] : direct) {
          int nx = i + dx, ny = j + dy;
          if (nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] != -1) {
            temp[nx][ny] += dust;
            count++;
          }
        }
        temp[i][j] -= dust * count;
      }
    }
    map = temp;

    // 위쪽 공기청정기 순환
    for (int i = puriUp.X - 1; i > 0; i--) map[i][0] = map[i - 1][0];
    for (int i = 0; i < c - 1; i++) map[0][i] = map[0][i + 1];
    for (int i = 0; i < puriUp.X; i++) map[i][c - 1] = map[i + 1][c - 1];
    for (int i = c - 1; i > 1; i--) map[puriUp.X][i] = map[puriUp.X][i - 1];

    // 아래쪽 공기청정기 순환
    for (int i = puriDown.X + 1; i < r - 1; i++) map[i][0] = map[i + 1][0];
    for (int i = 0; i < c - 1; i++) map[r - 1][i] = map[r - 1][i + 1];
    for (int i = r - 1; i > puriDown.X; i--) map[i][c - 1] = map[i - 1][c - 1];
    for (int i = c - 1; i > 1; i--) map[puriDown.X][i] = map[puriDown.X][i - 1];

    // 공청기 바람 나오는 자리
    map[puriUp.X][1] = 0;
    map[puriDown.X][1] = 0;
  }

  long long totalDust = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (map[i][j] > 0) totalDust += map[i][j];
    }
  }

  cout << totalDust << endl;
  return 0;
}