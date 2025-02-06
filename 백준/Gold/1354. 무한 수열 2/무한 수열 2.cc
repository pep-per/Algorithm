#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<long long, long long> a;
long long n, p, q, x, y;

long long recursive(long long i) {
  if (i <= 0) return 1;
  if (a[i] == 0) {
    a[i] = recursive(i / p - x) + recursive(i / q - y);
  }
  return a[i];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> p >> q >> x >> y;

  a[0] = 1;
  recursive(n);
  cout << a[n] << '\n';
  return 0;
}