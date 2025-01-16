#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, x;
  cin >> n >> m >> x;

  vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a][b] = c;
  }

  vector<vector<int>> dist(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        dist[i][j] = 0;
      else if (adj[i][j] != 0)
        dist[i][j] = adj[i][j];
      else
        dist[i][j] = 1e9;
    }
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int maxTime = -1;
  vector<int> times(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    times[i] += dist[i][x];
    times[i] += dist[x][i];
    if (times[i] > maxTime) {
      maxTime = times[i];
    }
  }
  cout << maxTime << endl;
  return 0;
}