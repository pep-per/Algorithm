#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;

    int min = 1e9;
    int start = 0;
    int end = 0;
    int sum = sequence[0];

    while (start <= end && end < sequence.size()) {
        if (sum < k) {
            end++;
            sum += sequence[end];            
        } else if (sum > k) {
            sum -= sequence[start];            
            start++;
        } else if (sum == k) {
            if (min > end - start) {
                answer = {start, end};
                min = end - start;
            }
            end++;
            sum += sequence[end];
        }
    }
    
    return answer;
}