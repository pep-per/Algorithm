#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
  int v, e, k;
  cin >> v >> e >> k;

  vector<vector<pair<int, int>>> graph(v + 1);
  vector<int> dist(v + 1, INF);

  for (int i = 0; i < e; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  dist[k] = 0;
  pq.push({0, k});

  while (!pq.empty()) {
    int cost = pq.top().first;
    int curr = pq.top().second;
    pq.pop();

    if (cost > dist[curr]) continue;

    for (auto &edge : graph[curr]) {
      int next = edge.first;
      int weight = edge.second;

      if (dist[curr] + weight < dist[next]) {
        dist[next] = dist[curr] + weight;
        pq.push({dist[next], next});
      }
    }
  }

  for (int i = 1; i <= v; i++) {
    if (dist[i] == INF) {
      cout << "INF\n";
    } else {
      cout << dist[i] << '\n';
    }
  }
  return 0;
}
