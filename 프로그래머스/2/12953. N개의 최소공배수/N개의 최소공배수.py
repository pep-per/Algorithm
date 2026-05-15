from math import gcd # 최대공약수를 찾는 함수

def solution(arr):
    lcm = arr[0] # 첫번째 원소
    for x in arr[1:]: # 두번째 원소부터 기존 lcm과 연산
        lcm = (lcm * x) // gcd(lcm, x)

    return lcm