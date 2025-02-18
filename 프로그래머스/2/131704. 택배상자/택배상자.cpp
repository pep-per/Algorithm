#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {

    stack<int> s;
    int cnt = 0;
    int num = 1;   
    for (int i = 0; i < order.size(); i++) {
        int target = order[i]; 
        
        while (num <= target) {
            s.push(num);
            num++;
        }
        
        if (!s.empty() && s.top() == target) {
            s.pop();
            cnt++;
        } else {
            break; 
        }
    }
        
    return cnt;
}