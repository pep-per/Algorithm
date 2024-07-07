function solution(n, m, section) {
    let count = 0, j = 0;
    for (i = 1; i <= n; i++) {
 
        if (i == section[j]) {
            count++;
            // console.log(i);
            while (i + m> section[j]) {
                j++;
                
            }
            // console.log();
        }
        // if (section[j] > n)
        //     break;
    }
    return count;
}