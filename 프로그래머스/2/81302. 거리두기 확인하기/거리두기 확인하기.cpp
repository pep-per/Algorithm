#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    
    int n = 5; 
    vector<int> answer(5,1);
    vector<pair<int,int>> direct = {{-1,0},{1,0},{0,-1},{0,1}};
                                
    int idx = 0;
    for (auto &place : places) {
        vector<vector<int>> map(n,vector<int>(n,0));
        vector<vector<bool>> vis(n, vector<bool>(n,false));
        queue<pair<int,int>> q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (place[i][j] == 'P') {
                    map[i][j] = -1;
                    q.push({i, j});
                } else if (place[i][j] == 'X')
                    map[i][j] = 1;
            }    
        }

        while (!q.empty()) {
   
            auto [x, y] = q.front();
            q.pop();
            for (auto &dir : direct) {
                int dx = dir.first, dy = dir.second;                    
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (map[nx][ny] == -1) {
                        answer[idx] = 0;
                        break;
                    } else if (map[nx][ny] != 1) {
                        bool isFind = false;
                        for (auto &dir : direct) {
                            int dxx = dir.first, dyy = dir.second;                    
                            int nxx = nx + dxx, nyy = ny + dyy;

                            if (nxx == x && nyy == y)
                                continue;
                            if (nxx >= 0 && nxx < n && nyy >= 0 && nyy < n) {
                                if (map[nxx][nyy] == -1) {
                                    answer[idx] = 0;
                                    isFind = true;
                                    break;
                                }
                            }
                        }
                        if (isFind)
                            break;
                    }
                }
            }   
        }
        idx++;
    }
    
    return answer;
}