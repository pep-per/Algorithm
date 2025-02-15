#include <string>
#include <vector>
using namespace std;

bool isWin(const vector<vector<int>>& map) {
    // 행 검사
    for (int i = 0; i < 3; i++) {
        if (map[i][0] == 1 && map[i][1] == 1 && map[i][2] == 1)
            return true;
    }
    // 열 검사
    for (int j = 0; j < 3; j++) {
        if (map[0][j] == 1 && map[1][j] == 1 && map[2][j] == 1)
            return true;
    }
    // 대각선 검사
    if (map[0][0] == 1 && map[1][1] == 1 && map[2][2] == 1)
        return true;
    if (map[0][2] == 1 && map[1][1] == 1 && map[2][0] == 1)
        return true;
    
    return false;
}

int solution(vector<string> board) {
    vector<vector<int>> ov(3, vector<int>(3, 0));
    vector<vector<int>> xv(3, vector<int>(3, 0));
    
    int o = 0, x = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'O') {
                o++;
                ov[i][j] = 1;
            } else if (board[i][j] == 'X') {
                x++;
                xv[i][j] = 1;
            }
        }
    }
    
    if (x > o || o > x + 1)
        return 0;
    
    bool winO = isWin(ov);
    bool winX = isWin(xv);
    
    if (winO && winX)
        return 0;    
    else if (winO && o != x + 1)
        return 0;
    else if (winX && o != x)
        return 0;
    else
        return 1;
}
