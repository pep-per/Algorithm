#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int stotime(string str) {
    istringstream iss(str);
    int start, end;
    char c;
    iss >> start >> c >> end;
    return start * 60 + end;
}

bool cmp(vector<string> a, vector<string> b) {
    return stotime(a[0]) < stotime(b[0]);
}

int solution(vector<vector<string>> book_time) {

    sort(book_time.begin(), book_time.end(), cmp);
    
    //각 방의 사용가능 시간 저장
    vector<vector<string>> rooms;
    
    int answer = 0;
    for (auto &booking : book_time) {

        bool isAssigned = false;
        int i = 0;
        while (i < rooms.size()) {
            int end = stotime(rooms[i][rooms[i].size() - 1]) + 10;
            if (end <= stotime(booking[0])) {
                isAssigned = true;
                rooms[i].push_back(booking[1]);
                break;
            }
            i++;
        }
        if (!isAssigned)
            rooms.push_back({booking[1]});
    }
    return rooms.size();
}