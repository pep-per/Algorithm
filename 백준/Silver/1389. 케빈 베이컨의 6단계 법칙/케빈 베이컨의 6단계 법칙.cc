#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a][b] = 1;
    adj[b][a] = 1;
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

  int minVal = 1e9;
  int minIdx = 1;
  vector<int> vals(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      vals[i] += dist[i][j];
    }
    if (vals[i] < minVal) {
      minVal = vals[i];
      minIdx = i;
    }
  }
  cout << minIdx << endl;
  return 0;
}