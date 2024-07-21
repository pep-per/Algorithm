#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> goods(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> goods[i].first >> goods[i].second;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= k; w++)
        {
            if (goods[i].first <= w)
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-goods[i].first] + goods[i].second);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    cout << dp[n][k] << endl;
    return 0;
}