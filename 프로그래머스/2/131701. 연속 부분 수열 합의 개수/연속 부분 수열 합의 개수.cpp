#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) {
    
    map<int,int> sum;
    int n = elements.size();
    for (int i = 0; i < n; i++) {
        int prefix = 0;
        for (int j = 0; j < n; j++) {
            prefix += elements[(i + j)%n];
            sum[prefix]++;
        }
    }

    return sum.size();
}