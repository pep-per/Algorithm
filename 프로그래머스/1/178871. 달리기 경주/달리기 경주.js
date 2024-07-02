function solution(players, callings) {
    const playerMap = new Map();
    players.forEach((player, i) => {
        playerMap.set(player, i);
    });

    callings.forEach((call) => {
        const i = playerMap.get(call);
        const prev = players[i-1];
        players[i-1] = call;
        players[i] = prev;
        playerMap.set(call, i-1);
        playerMap.set(prev, i);
    });
    return players;
}
