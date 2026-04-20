import sys

input = sys.stdin.readline
n = int(input())
# 중복 단어를 제거하고 리스트로 변환
words = list(set(input().strip() for _ in range(n)))

# 1. 사전순으로 정렬 (핵심!)
words.sort()

count = 0
for i in range(len(words)):
    # 2. 현재 단어가 다음 단어의 접두사인지 확인
    # 사전순 정렬 덕분에 바로 뒤(i+1)만 확인하면 됨
    if i < len(words) - 1 and words[i + 1].startswith(words[i]):
        continue
    else:
        count += 1

print(count)