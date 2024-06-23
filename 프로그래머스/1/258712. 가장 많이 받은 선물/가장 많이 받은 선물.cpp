#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<string> friends_;

int findIdx(string name) {
    for (size_t i = 0; i < friends_.size(); i++) {
        if (friends_[i] == name)
            return i;
    }
    return -1;
}

int solution(vector<string> friends, vector<string> gifts) {
    friends_ = friends;
    string give;
    string take;
    int tab[50][50] = {0,};
    for (auto y : gifts)
    {
        give = y.substr(0, y.find(' '));
        take = y.substr(y.find(' ') + 1);
        tab[findIdx(give)][findIdx(take)]++; 
    }
    int idx = 0;
    vector<int> indexes;
    for (size_t i = 0; i < friends.size(); i++) {
        idx = 0;
        for (size_t j = 0; j < friends.size(); j++) {
            if (i == j)
                continue;
            idx += tab[i][j];
            idx -= tab[j][i];
        }
        indexes.push_back(idx);
    }
    int max = 0;
    int result = 0;
    for (size_t i = 0; i < friends.size(); i++) {
        result = 0;
        for (size_t j = 0; j < friends.size(); j++) {
            if (i == j)
                continue;
            if (tab[i][j] > tab[j][i])
                result++;
            else if ((tab[i][j] == 0 && tab[j][i] == 0) || (tab[i][j] == tab[j][i])) {
                if (indexes[i] > indexes[j])
                    result++;                    
            }
        }
        if (result > max)
            max = result;
    }
    return max;
}