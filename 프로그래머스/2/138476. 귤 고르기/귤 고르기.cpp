#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<int> tangerine) {
    // 1. 크기별 빈도수 계산
    unordered_map<int,int> freq; 
    for(int t : tangerine) {
        freq[t]++;
    }

    // 2. (빈도수, 크기) 정보를 우선순위 큐(빈도수 큰 순)로
    priority_queue<pair<int,int>> pq;
    for(auto &p : freq) {
        pq.push({p.second, p.first}); 
    }

    // 3. 빈도수 큰 것부터 합치며 k개 이상 될 때까지
    int sum = 0;
    int distinct = 0;
    while(!pq.empty()) {
        sum += pq.top().first;
        pq.pop();
        distinct++;
        if(sum >= k) break;
    }
    return distinct;
}
