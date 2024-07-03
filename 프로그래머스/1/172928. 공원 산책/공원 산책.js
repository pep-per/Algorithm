function solution(park, routes) {
    let startX, startY;
    for (let i = 0; i < park.length; i++) {
        for (let j = 0; j < park[i].length; j++) {
            if (park[i][j] === 'S') {
                startX = i;
                startY = j;
                break;
            }
        }
    }

    let x = startX, y = startY;
    for (const route of routes) {
        const [dir, distance] = route.split(' ');
        const dist = Number(distance);
        let dx = 0, dy = 0;
        if (dir === 'E') dy = 1;
        else if (dir === 'W') dy = -1;
        else if (dir === 'N') dx = -1;
        else if (dir === 'S') dx = 1;

        let nextX = x, nextY = y;
        let valid = true;
        for (let step = 0; step < dist; step++) {
            nextX += dx;
            nextY += dy;

            if (nextX < 0 || nextY < 0 || nextX >= park.length || nextY >= park[0].length) {
                valid = false;
                break;
            }
            if (park[nextX][nextY] === 'X') {
                valid = false;
                break;
            }
        }
        if (valid) {
            x = nextX;
            y = nextY;
        }
    }    
    return [x, y];
}