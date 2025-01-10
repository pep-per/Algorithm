#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<pair<long long, long long>> lines(N);
  for (int i = 0; i < N; i++) {
    cin >> lines[i].first >> lines[i].second;
  }

  sort(lines.begin(), lines.end());
  vector<pair<long long, long long>> merged;
  merged.push_back(lines[0]);

  for (int i = 1; i < N; i++) {
    if (merged.back().second >= lines[i].first) {
      merged.back().second = max(merged.back().second, lines[i].second);
    } else {
      merged.push_back(lines[i]);
    }
  }

  long long total = 0;
  for (const auto& line : merged) {
    total += line.second - line.first;
  }
  cout << total << endl;
  return 0;
}