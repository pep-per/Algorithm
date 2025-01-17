#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> lis;
  lis.push_back(arr[0]);

  for (int i = 1; i < n; i++) {
    if (lis.back() < arr[i]) {
      lis.push_back(arr[i]);
    } else {
      auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
      *it = arr[i];
    }
  }

  cout << lis.size() << endl;
  return 0;
}