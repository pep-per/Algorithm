def multi(a, b, c):
    if b == 1:
        return a % c
    
    temp = multi(a, b // 2, c)
    
    if b % 2 == 0:
        return (temp * temp) % c
    else:
        return (temp * temp * a) % c

a, b, c = map(int, input().split())

print(multi(a, b, c))