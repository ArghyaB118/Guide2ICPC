#include <iostream>
using namespace std;

enum class MonsterType {
	OGRE,
	DRAGON,
	ORC,
	SPIDER
};

struct Monster {
	MonsterType type;
	string name;
	int health;
};

string getMonsterType(Monster monster) {
	if(monster.type == MonsterType::OGRE) return "Ogre";
	if(monster.type == MonsterType::DRAGON) return "Dragon";
	if(monster.type == MonsterType::ORC) return "Orc";
	if(monster.type == MonsterType::SPIDER) return "Spider";
	else return "Unknown";
}

void printMonster(Monster monster) {
	cout << getMonsterType(monster) << "\n";
	cout << monster.name << "\n";
	cout << monster.health << "\n";
}

int main() {
	Monster ogre = {MonsterType::OGRE, "Torg", 145};
	printMonster(ogre);
}