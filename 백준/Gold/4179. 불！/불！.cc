#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> maze(r, vector<char>(c));
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    queue<pair<int, int>> jQueue, fQueue;
    int jTime = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'J') {
                jQueue.push({i, j});
                visited[i][j] = true;
            } else if (maze[i][j] == 'F') {
                fQueue.push({i, j});
            }
        }
    }

    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!jQueue.empty()) {
        jTime++;

        // 불 확산
        int fSize = fQueue.size();
        for (int i = 0; i < fSize; i++) {
            auto [fx, fy] = fQueue.front();
            fQueue.pop();
            for (auto& [dx, dy] : directions) {
                int nx = fx + dx, ny = fy + dy;
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && maze[nx][ny] == '.') {
                    maze[nx][ny] = 'F';
                    fQueue.push({nx, ny});
                }
            }
        }

        // J 이동
        int jSize = jQueue.size();
        for (int i = 0; i < jSize; i++) {
            auto [jx, jy] = jQueue.front();
            jQueue.pop();
            if (jx == 0 || jx == r - 1 || jy == 0 || jy == c - 1) {
                cout << jTime << endl;
                return 0;
            }

            for (auto& [dx, dy] : directions) {
                int nx = jx + dx, ny = jy + dy;
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny] && maze[nx][ny] == '.') {
                    visited[nx][ny] = true;
                    jQueue.push({nx, ny});
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}