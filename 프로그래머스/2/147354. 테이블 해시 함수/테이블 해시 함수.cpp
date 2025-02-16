#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int stand;

bool cmp(vector<int> a, vector<int> b) {
    if (a[stand - 1] != b[stand - 1])
        return a[stand - 1] < b[stand - 1];
    else
        return a[0] > b[0];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    stand = col;
    
    sort(data.begin(), data.end(), cmp);  

    for (int i = row_begin - 1; i < row_end; i++) {
        long long sum = 0;
        for (int j = 0; j < data[i].size(); j++) {
            sum += data[i][j] % (i + 1);
        }
        cout << sum << endl;
        answer ^= sum;
    }
    return answer;
}