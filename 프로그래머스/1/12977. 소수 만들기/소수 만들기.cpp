#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int count = 0;

bool isPrime(int num) {
    int x = 2;
    while (x<=num/sqrt(2)) {
        if (num%x == 0)
            return false;
        else
            x++;
    }
    return true;
}

void combination(int idx, vector<int> nums, vector<int> comb) {
    if (comb.size() == 3) {
        int sum = 0;
        for (auto x : comb)
            sum += x;
        if (isPrime(sum))
            count++;
        return;
    }
    for (int i = idx+1; i < nums.size(); i++) {
        comb.push_back(nums[i]);
        combination(i, nums, comb);
        comb.pop_back();
    }
}

int solution(vector<int> nums) {
    vector<int> comb;
    combination(-1, nums, comb);
    return count;
}