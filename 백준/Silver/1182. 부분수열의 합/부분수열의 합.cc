#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, s;
int result = 0;
vector<int> nums;
vector<int> curr;

void backtrack(int index) {
  int sum = 0;
  if (!curr.empty()) {
    for (int x : curr) {
      sum += x;
    }
    if (sum == s) {
      result++;
    }
  }

  for (int i = index; i < n; i++) {
    curr.push_back(nums[i]);
    backtrack(i + 1);
    curr.pop_back();
  }
}

int main() {
  cin >> n >> s;

  nums.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  backtrack(0);
  cout << result << endl;

  return 0;
}