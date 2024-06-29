#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    if (s < n) {
        return {-1};  // s가 n보다 작으면 모든 원소의 합이 s가 될 수 없음
    }
    
    vector<int> result(n, s / n);  // 각 원소를 s / n으로 초기화
    int remainder = s % n;         // 나머지를 계산
    
    for (int i = 0; i < remainder; ++i) {
        result[i]++;
    }
    sort(result.begin(), result.end());
    return result;
}
