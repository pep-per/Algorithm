#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> map(n, vector<int>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m,false));
    vector<pair<int,int>> direct = {{0,1},{1,0},{0,-1},{-1,0}};
    queue<pair<int,int>> q;
    pair<int,int> goal;

     for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') {
                q.push({i,j});
                vis[i][j] = true;
            }
            else if (board[i][j] == 'D')
                map[i][j] = 1;
            else if (board[i][j] == 'G')
                goal = {i,j};
        }                            
    }                            

    int move = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x == goal.first && y == goal.second)
                return move;

            for (auto &dir : direct) {
                int dx = dir.first;
                int dy = dir.second;
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != 1) {
                    while (nx + dx >= 0 && nx + dx < n && ny + dy >= 0 && ny + dy < m && map[nx+dx][ny+dy] != 1) {
                        nx += dx;
                        ny += dy;
                    }
                    if (!vis[nx][ny]) {
                        q.push({nx,ny});
                        vis[nx][ny] = true;
                    }
                }
            }
        }
        move++;

    }
    return -1;
}