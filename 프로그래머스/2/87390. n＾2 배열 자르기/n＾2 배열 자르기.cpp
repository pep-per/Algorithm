#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> solution(int n, long long left, long long right) {

    ll limit = right - left + 1;
    vector<int> answer(limit, 0);

    for (ll i = 0; i < limit; i++) {
        answer[i] = max((left+i)/n, (left+i)%n)+1;
    }

    return answer;
}