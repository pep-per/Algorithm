import sys

input = sys.stdin.readline
n = int(input().strip())
struct = {}

# 1. 트라이 구조 만들기
for _ in range(n):
    foods = input().split()
    floor = int(foods[0])

    curfloor = struct
    for i in range(floor):
        if foods[i+1] not in curfloor:
            curfloor[foods[i+1]] = {}
        curfloor = curfloor[foods[i+1]]

# 2. 정렬하며 출력
def print_struct(struct, depth):
    for food in sorted(struct.keys()):
        print("--" * depth + food)
        print_struct(struct[food], depth + 1)

print_struct(struct, 0)