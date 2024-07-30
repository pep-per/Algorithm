#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, num;
    cin >> n;
    map<int, int> freq;
    
    for (int i = 0; i < n; i++) {
        cin >> num;
        freq[num]++;
    }
    
    vector<int> keys;
    for (const auto& pair : freq) {
        keys.push_back(pair.first);
    }
    sort(keys.begin(), keys.end());
    
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num;
        if (binary_search(keys.begin(), keys.end(), num)) {
            cout << freq[num] << ' ';
        } else {
            cout << "0 ";
        }
    }
    return 0;
}
