#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>  // abs() 함수에 필요

using namespace std;

vector<int> arr(10001, 0);
map<pair<int,int>, double> dp;

double integral(int a, int b) {
    if (dp.find({a,b}) != dp.end()) {
        return dp[{a,b}];
    }
    if (a + 1 == b) {
        dp[{a,b}] = fabs(arr[a] - arr[b]) / 2.0 + min(arr[a], arr[b]);
        return dp[{a,b}];
    }
    double sumVal = 0.0;
    for (int i = a; i < b; i++) {
        sumVal += integral(i, i + 1);
    }
    dp[{a,b}] = sumVal;
    return sumVal;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    // arr 초기화
    arr[0] = k;
    int n = 1;

    while (k > 1) {
        if (k % 2 == 0)
            k /= 2;
        else
            k = k * 3 + 1;
        arr[n++] = k;
    }
    n--;

    vector<double> answer(ranges.size(), 0.0);
    dp[{0,0}] = 0.0;

    for (int i = 0; i < (int)ranges.size(); i++) {
        int a = ranges[i][0];
        int b = n + ranges[i][1];

        if (a > b) {
            answer[i] = -1;
        }else if (a == b) {
            answer[i] = 0.0;
        } else {
            answer[i] = integral(a, b);
        }
    }
    return answer;
}
