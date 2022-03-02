/*
Description of the game: Hero goes out to defeat monsters.

There are N monsters, each with atk[i] and life[i].

atk[i]: damage per second this monster can deal to the hero.
life[i]: # of seconds the hero needs to kill the monster.

Goal: kill all monsters in the best possible order,
answer the minimum total damage you'll receive in that time.

Clarification: Hero can always kill all the mosters. 
In other words, hero has enough life and atk to kill all the monsters.

Idea: Relation with the job scheduling task.
The optimal online algorithm is SJF (shortest job first).
Here, instead of the job lengths, some other penulty function has to be custom-designed.

Observation: 
1. If all the monsters have the same life values, what is the order?
Hero would like to kill the monsters in the order of decreasing atks.
2. If all the monsters have the same atks, what is the order?
Hero would like to kill the monsters in the order of increasing life values.

From these observations, we design the penulty function for each monster as
antiReward[i] = atk[i] / life[i]
Hero kills the monsters in a decreasing order of antiReward.

Example: (atk[i],life[i])
{(2,1)(2,2)(1,3)}

antiReward[i] = {2, 1, 0.33}

schedules: 1, 2, 3 
damage = 5 * 1 + 3 * 2 + 2 * 2 = 14

different orders: 
i) 3,1,2 damage = 5 * 3 + 4 + 2 * 2 = 23
ii) 1,3,2 -> 5 * 1 + 3 * 3 + 2 * 2 = 18
*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> monster;

class Comparator {
public:
    bool operator() (monster& a, monster& b) {
        return ((a.first / a.second) < (b.first / b.second));
    }
};

int sortedMonstersKill (vector<monster>& monsters) {
    std::priority_queue<monster, vector<monster>, Comparator> pq;
    int sum_atk = 0;
    for (int i = 0; i < monsters.size(); i++) {
        sum_atk += monsters[i].first;
        pq.push(monsters[i]);
    }
    int tot_damage = 0;
    while (!pq.empty()) {
        monster m = pq.top(); pq.pop();
        tot_damage += sum_atk * m.second;
        sum_atk -= m.first;
//        cout << m.first << " " << m.second << endl;
    }
    return tot_damage;
}


int main() {
    vector<monster> monsters{make_pair(2,1),make_pair(2,2),make_pair(1,3)};
    for (monster & m : monsters)
        cout << m.first << " " << m.second << endl;
    cout << "Total damage is: " << sortedMonstersKill(monsters) << endl;
    return 0;
}


