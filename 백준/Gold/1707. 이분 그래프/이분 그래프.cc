#include <iostream>
#include <vector>

#define RED 1
#define BLUE -1

using namespace std;

vector<vector<int>> graph;
vector<int> visited;

void dfs(int node, int color) {
  visited[node] = color;
  for (int next : graph[node]) {
    if (!visited[next]) {
      dfs(next, -1 * color);
    }
  }
}

void solution() {
  int v, e;
  cin >> v >> e;

  graph.assign(v + 1, vector<int>());
  visited.assign(v + 1, 0);

  int a, b;
  for (int i = 0; i < e; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= v; i++) {
    if (!visited[i]) {
      dfs(i, RED);
    }
  }

  bool isBipartite = true;
  for (int i = 1; i <= v; i++) {
    for (int next : graph[i]) {
      if (visited[i] == visited[next]) {
        isBipartite = false;
        break;
      }
    }
  }

  if (isBipartite) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int k;
  cin >> k;

  for (int i = 0; i < k; i++) {
    solution();
  }
  return 0;
}
