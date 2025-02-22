#include <bits/stdc++.h>

using namespace std;

const int fatigue[3][3] = {
    {1, 1, 1},  // 다이아몬드 곡괭이
    {5, 1, 1},  // 철 곡괭이
    {25, 5, 1}  // 돌 곡괭이
};

struct Group {
    int diamondFatigue, ironFatigue, stoneFatigue;
    int maxFatigue; // 그룹 내 가장 높은 피로도를 기준으로 정렬
};

bool compare(const Group &a, const Group &b) {
    return a.maxFatigue > b.maxFatigue;
}

int solution(vector<int> picks, vector<string> minerals) {
    int totalPicks = picks[0] + picks[1] + picks[2];
    int numGroups = min(totalPicks, (int)(minerals.size() + 4) / 5);
    
    vector<Group> groups;
    
    // 5개씩 그룹화하여 각 곡괭이로 캘 때 피로도를 계산
    for (int i = 0; i < numGroups; ++i) {
        int diamond = 0, iron = 0, stone = 0;
        for (int j = 0; j < 5; ++j) {
            int index = i * 5 + j;
            if (index >= minerals.size()) break;
            if (minerals[index] == "diamond") diamond++;
            else if (minerals[index] == "iron") iron++;
            else if (minerals[index] == "stone") stone++;
        }
        
        groups.push_back({
            diamond * fatigue[0][0] + iron * fatigue[0][1] + stone * fatigue[0][2], // 다이아 곡괭이 피로도
            diamond * fatigue[1][0] + iron * fatigue[1][1] + stone * fatigue[1][2], // 철 곡괭이 피로도
            diamond * fatigue[2][0] + iron * fatigue[2][1] + stone * fatigue[2][2], // 돌 곡괭이 피로도
            max({
                diamond * fatigue[0][0] + iron * fatigue[0][1] + stone * fatigue[0][2], // 다이아 피로도
                diamond * fatigue[1][0] + iron * fatigue[1][1] + stone * fatigue[1][2], // 철 피로도
                diamond * fatigue[2][0] + iron * fatigue[2][1] + stone * fatigue[2][2]  // 돌 피로도
            }) 
        });
    }
    
    sort(groups.begin(), groups.end(), compare);
    
    int fatigueSum = 0;
    
    // 곡괭이 사용 순서: 다이아몬드 -> 철 -> 돌
    for (Group &g : groups) {
        if (picks[0] > 0) { // 다이아몬드 곡괭이 사용
            fatigueSum += g.diamondFatigue;
            picks[0]--;
        } else if (picks[1] > 0) { // 철 곡괭이 사용
            fatigueSum += g.ironFatigue;
            picks[1]--;
        } else if (picks[2] > 0) { // 돌 곡괭이 사용
            fatigueSum += g.stoneFatigue;
            picks[2]--;
        } else {
            break; // 더 이상 곡괭이가 없음
        }
    }
    
    return fatigueSum;
}