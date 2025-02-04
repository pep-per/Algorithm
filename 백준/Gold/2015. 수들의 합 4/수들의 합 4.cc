#include <iostream>
#include <unordered_map>
#include <vector>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<ll, int> prefix_count;
    ll prefix_sum = 0;
    ll result = 0;

    prefix_count[0] = 1;

    for (int i = 0; i < n; i++) {
        prefix_sum += a[i];

        if (prefix_count.find(prefix_sum - k) != prefix_count.end()) {
            result += prefix_count[prefix_sum - k];
        }

        prefix_count[prefix_sum]++;
    }

    cout << result << '\n';
    return 0;
}
