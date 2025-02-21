#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> nums)
{
    map<int,int> m;
    for (auto &n : nums) {
        m[n]++;
    }
    int max = nums.size() / 2;
    int answer = m.size() > max ? max : m.size(); 
    return answer;
}