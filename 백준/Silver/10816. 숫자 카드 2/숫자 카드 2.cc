#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, num;
    cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        freq[num]++;
    }

    int m;
    cin >> m;
    vector<int> queries(m);
    for (int i = 0; i < m; i++)
    {
        cin >> queries[i];
    }

    for (int query : queries)
    {
        cout << freq[query] << ' ';
    }

    return 0;
}