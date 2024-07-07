function solution(n, m, section) {
    let count = 0, j = 0;
    for (i = 1; i <= n; i++) {
        if (i == section[j]) {
            count++;
            while (i + m> section[j])
                j++;
        }
    }
    return count;
}