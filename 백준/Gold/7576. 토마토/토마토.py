from collections import deque
import sys

input = sys.stdin.readline
M, N = map(int, input().split())

q = deque()
box = []

is_all_one = True

for i in range(N):
    row = list(map(int, input().split()))
    box.append(row)
    
    for j in range(M):
        if box[i][j] == 1:
            q.append((i, j))
        elif box[i][j] == 0:
            is_all_one = False

if is_all_one:
    print(0)
    exit(0)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

while q:
    x, y = q.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < N and 0 <= ny < M and box[nx][ny] == 0:
            box[nx][ny] = box[x][y] + 1
            q.append((nx, ny))

ans = 0
for i in box:
    for j in i:
        if j == 0:
            print(-1)
            exit(0)
        ans = max(ans, j)

print(ans - 1)