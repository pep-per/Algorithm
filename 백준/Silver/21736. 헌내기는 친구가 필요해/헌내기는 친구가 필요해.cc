#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> campus(n, vector<char>(m));
  pair<int, int> start;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> campus[i][j];
      if (campus[i][j] == 'I') start = {i, j};
    }
  }

  vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  queue<pair<int, int>> q;

  visited[start.first][start.second] = true;
  q.push(start);
  int count = 0;
  while (!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    int x = curr.first;
    int y = curr.second;
    if (campus[x][y] == 'P') count++;
    for (auto &dir : direction) {
      int dx = x + dir.first;
      int dy = y + dir.second;
      if (dx >= 0 && dx < n && dy >= 0 && dy < m && campus[dx][dy] != 'X' &&
          visited[dx][dy] == false) {
        q.push({dx, dy});
        visited[dx][dy] = true;
      }
    }
  }
  if (count)
    cout << count << endl;
  else
    cout << "TT" << endl;
  return 0;
}