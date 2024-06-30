#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int lastAttack = attacks.back()[0];
    int healTime = bandage[0];
    int healPerSec = bandage[1];
    int healPlus = bandage[2];
    int damage, attackTime, heal;
    int sec = 1;
    int hp = health;
    int i = 0;
    int healCount = 0;

    while (sec <= lastAttack) {
        if (sec == attacks[i][0]) {
            damage = attacks[i][1];
            hp -= damage;
            healCount = 0;
            if (hp <= 0)
                return -1;
            i++;
        } else {
            healCount++;
            if (hp < health) {
                if (healCount < healTime) {
                    heal = healPerSec;
                }
                else if (healCount == healTime) {
                    heal = healPerSec + healPlus;
                    healCount = 0;
                }
                hp += heal;
                if (hp > health)
                    hp = health;
            }
        }
        sec++;
    }
    return hp;
}