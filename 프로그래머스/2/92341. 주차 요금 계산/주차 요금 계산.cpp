#include <bits/stdc++.h>
using namespace std;

int toTime(string timeStr) {
    return stoi(timeStr.substr(0, 2)) * 60 + stoi(timeStr.substr(3, 2));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<int, int> totalTime; 
    map<int, int> inTime;    

    for (const auto& record : records) {
        stringstream ss(record);
        string timeStr, carStr, action;
        ss >> timeStr >> carStr >> action;
        int carNum = stoi(carStr);
        int time = toTime(timeStr);

        if (action == "IN") {
            inTime[carNum] = time;
        } else { 
            totalTime[carNum] += time - inTime[carNum];
            inTime.erase(carNum);
        }
    }

    for (auto& [carNum, time] : inTime) {
        totalTime[carNum] += (23 * 60 + 59) - time;
    }

    vector<int> answer;
    for (auto& [carNum, time] : totalTime) {
        int fee = fees[1]; 
        if (time > fees[0]) {
            fee += ((time - fees[0] + fees[2] - 1) / fees[2]) * fees[3];
        }
        answer.push_back(fee);
    }

    return answer;
}
