#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<long long, long long> a;
long long n, p, q;

long long dfs(long long i) {
  if (a[i] == 0) {
    a[i] = dfs(i / p) + dfs(i / q);
  }
  return a[i];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> p >> q;

  a[0] = 1;
  a[1] = 2;
  dfs(n);
  cout << a[n] << '\n';
  return 0;
}