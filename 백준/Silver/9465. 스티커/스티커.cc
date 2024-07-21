#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<vector<int>>& stickers, int n) {
    if (n == 1) {
        return max(stickers[0][0], stickers[1][0]);
    }

    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[0][0] = stickers[0][0];
    dp[1][0] = stickers[1][0];
    dp[0][1] = stickers[1][0] + stickers[0][1];
    dp[1][1] = stickers[0][0] + stickers[1][1];

    for (int i = 2; i < n; i++) {
        dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + stickers[0][i];
        dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + stickers[1][i];
    }

    return max(dp[0][n-1], dp[1][n-1]);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<vector<int>> stickers(2, vector<int>(n));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> stickers[i][j];
            }
        }

        cout << solve(stickers, n) << endl;
    }
    return 0;
}