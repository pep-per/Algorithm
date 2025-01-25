#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> num(m);
  for (int i = 0; i < m; i++) {
    cin >> num[i];
  }

  deque<int> dq;
  for (int i = 1; i <= n; i++) {
    dq.push_back(i);
  }

  int move = 0;
  for (int i = 0; i < m; i++) {
    // num의 인덱스를 찾아서 idx에 저장
    int idx = 0;
    for (int j = 0; j < dq.size(); j++) {
      if (dq[j] == num[i]) {
        idx = j;
        break;
      }
    }

    // 최소 move를 위해 앞/뒤 어디에서 뽑을지 idx를 비교
    if (idx < dq.size() - idx) {
      // 앞에서 뽑는 경우
      while (dq.front() != num[i]) {
        int front = dq.front();
        dq.pop_front();
        dq.push_back(front);
        move++;
      }
      dq.pop_front();
    } else {
      // 뒤에서 뽑는 경우
      while (dq.front() != num[i]) {
        int back = dq.back();
        dq.pop_back();
        dq.push_front(back);
        move++;
      }
      dq.pop_front();
    }
  }

  cout << move << endl;
  return 0;
}
