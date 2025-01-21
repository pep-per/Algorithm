#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
  int v, m;
  cin >> v >> m;

  vector<vector<int>> dist(v + 1, vector<int>(v + 1, INF));
  for (int i = 1; i <= v; i++) {
    dist[i][i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = min(dist[a][b], c);
    dist[b][a] = min(dist[b][a], c);
  }

  for (int k = 1; k <= v; k++) {
    for (int i = 1; i <= v; i++) {
      for (int j = 1; j <= v; j++) {
        if (dist[i][k] != INF && dist[k][j] != INF) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  int j, s;
  cin >> j >> s;

  int minDist = INF;
  int totalDist = 0;

  for (int i = 1; i <= v; i++) {
    if (i == j || i == s) continue;
    if (dist[j][i] == INF || dist[s][i] == INF) continue;

    totalDist = dist[j][i] + dist[s][i];
    minDist = min(minDist, totalDist);
  }

  int minJDist = INF;
  int answer = -1;

  for (int i = 1; i <= v; i++) {
    if (i == j || i == s) continue;

    totalDist = dist[j][i] + dist[s][i];
    if (totalDist != minDist) continue;

    if (dist[j][i] > dist[s][i])
      continue;
    else if (dist[j][i] > minJDist)
      continue;

    minJDist = dist[j][i];
    answer = i;
  }

  cout << answer << endl;
  return 0;
}