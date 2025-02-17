#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> land)
{
    int n = land.size();
    vector<vector<int>> dp(n, vector<int>(4, 0));
    for (int i = 0; i < 4; i++)
        dp[0][i] = land[0][i];
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            int maxPrev = 0;
            for (int k = 0; k < 4; k++) {
                if (k == j)
                    continue;
                maxPrev = max(dp[i-1][k], maxPrev);
            }
            dp[i][j] = maxPrev + land[i][j];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < 4; i++)
        ans = max(dp[n-1][i], ans);
    return ans;
}