def solution(brown, yellow):
    total = brown + yellow

    for h in range(3, total):
        if total % h == 0:
            w = total // h  # 나누기(/) 대신 몫 구하기(//) 사용
            
            if (w - 2) * (h - 2) == yellow:
                return [w, h]