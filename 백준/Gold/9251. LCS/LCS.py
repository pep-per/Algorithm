import sys
input = sys.stdin.readline

# 문자열 입력 받기 (빠른 입력은 끝에 줄바꿈 \n이 붙으므로 .strip()으로 제거해 줍니다)
word1 = input().strip()
word2 = input().strip()

# 세로(N), 가로(M) 길이
N = len(word1)
M = len(word2)

# 1. (N+1) x (M+1) 크기의 2차원 DP 테이블을 0으로 초기화
dp = [[0] * (M + 1) for _ in range(N + 1)]

# 2. 이중 for문을 돌며 표 채우기
for i in range(1, N + 1):
    for j in range(1, M + 1):
        
        # 규칙 1: 두 글자가 서로 같다면 (인덱스는 0부터 시작하므로 -1을 해줍니다)
        if word1[i-1] == word2[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
            
        # 규칙 2: 두 글자가 서로 다르다면
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

# 3. 표의 가장 오른쪽 아래 칸에 있는 값이 최종적인 LCS의 길이
print(dp[N][M])