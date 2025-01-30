#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int to;
  int isDown;
};

int primBest(vector<vector<Edge>>& graph, int N) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>
      pq;

  vector<bool> visited(N, false);
  int count = 0;
  visited[0] = true;
  for (const auto& edge : graph[0]) {
    pq.push({edge.isDown, edge.to});
  }

  while (!pq.empty()) {
    auto [isDown, curr] = pq.top();
    pq.pop();

    if (visited[curr]) continue;
    visited[curr] = true;

    if (isDown == 0) count++;

    for (Edge& edge : graph[curr]) {
      if (!visited[edge.to]) {
        pq.push({edge.isDown, edge.to});
      }
    }
  }
  return count * count;
}

int primWorst(vector<vector<Edge>>& graph, int N) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  vector<bool> visited(N, false);
  int count = 0;

  visited[0] = true;
  for (const auto& edge : graph[0]) {
    pq.push({edge.isDown, edge.to});
  }

  while (!pq.empty()) {
    auto [isDown, curr] = pq.top();
    pq.pop();

    if (visited[curr]) continue;
    visited[curr] = true;

    if (isDown == 0) count++;

    for (Edge& edge : graph[curr]) {
      if (!visited[edge.to]) {
        pq.push({edge.isDown, edge.to});
      }
    }
  }
  return count * count;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<Edge>> graph(n + 1);

  int from, to, isDown;
  for (int i = 0; i <= m; i++) {
    cin >> from >> to >> isDown;
    graph[from].push_back({to, isDown});
    graph[to].push_back({from, isDown});
  }

  int worst = primWorst(graph, n + 1);
  int best = primBest(graph, n + 1);

  cout << worst - best << '\n';
  return 0;
}