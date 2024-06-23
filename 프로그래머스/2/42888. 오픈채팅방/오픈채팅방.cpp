#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    map<string,string> m;
    string cmd, id, nick;
    for (auto x : record) {
        istringstream iss;
        iss.str(x);
        iss >> cmd;
        iss >> id;
        if (cmd == "Enter" || cmd == "Change") {
            iss >> nick;
            m[id] = nick;               
        }
    }
    vector<string> answer;
    for (auto x : record) {
        istringstream iss;
        iss.str(x);
        iss >> cmd;
        iss >> id;
        if (cmd == "Enter")
            answer.push_back(m[id] + "님이 들어왔습니다.");
        else if (cmd == "Leave")
            answer.push_back(m[id] + "님이 나갔습니다.");
    }    
    return answer;
}