#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이진 탐색 함수
int binarySearch(const vector<pair<int, int>>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].first == target) {
            return arr[mid].second;
        }
        if (arr[mid].first < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, num;
    cin >> n;
    vector<int> numbers;
    
    // 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> num;
        numbers.push_back(num);
    }
    
    // 정렬
    sort(numbers.begin(), numbers.end());
    
    // 빈도수 계산
    vector<pair<int, int>> freq;
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (numbers[i] == numbers[i-1]) {
            count++;
        } else {
            freq.push_back({numbers[i-1], count});
            count = 1;
        }
    }
    freq.push_back({numbers[n-1], count});
    
    // 쿼리 처리
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> num;
        cout << binarySearch(freq, num) << " ";
    }
    
    return 0;
}