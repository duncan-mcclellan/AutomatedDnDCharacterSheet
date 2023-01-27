/* Author: Duncan McClellan
 * Created: 01/13/2020
 * Tested: Untested
 * Version: 0.3.0
 * Updated: 01/27/2023
 *
 * Desc:
 * A D&D 5e character sheet that fills your stats, proficiencies, etc. to allow
 * a character to be created with minimal effort. This should lower the barrier
 * of entry for new players and help players that just want to make a character
 * really fast. Not recommended for experienced players that wish to trail off
 * the beaten path.
 */

// Included Libraries
#include <boost/algorithm/string/predicate.hpp>
#include <ctime>
#include <map>
#include <stdlib.h>
#include <vector>

// This will get removed in a later version. I'm being lazy for the initial
// creation
using namespace std;

// Included Headers
#include "_player.h"
#include "heapSort.h"
#include "toString.h"

map<string, _class *> classes{{"barbarian", new Barbarian()},
							  {"bard", new Bard()},
							  {"cleric", new Cleric()},
							  {"druid", new Druid()},
							  {"fighter", new Fighter()},
							  {"monk", new Monk()},
							  {"paladin", new Paladin()},
							  {"ranger", new Ranger()},
							  {"rogue", new Rogue()},
							  {"sorcerer", new Sorcerer()},
							  {"warlock", new Warlock()},
							  {"wizard", new Wizard()}};

map<string, _race *> races{{"dragonborn", new Dragonborn()},
						   {"dwarf", new Dwarf()},
						   {"elf", new Elf()},
						   {"gnome", new Gnome()},
						   {"half-elf", new HalfElf()},
						   {"halfling", new Halfling()},
						   {"half-orc", new HalfOrc()},
						   {"human", new Human()},
						   {"tiefling", new Tiefling()}};

map<string, _background *> backgrounds{{"acolyte", new Acolyte()},
									   {"criminal", new Criminal()},
									   {"folk_hero", new FolkHero()},
									   {"haunted_one", new HauntedOne()},
									   {"noble", new Noble()},
									   {"sage", new Sage()},
									   {"soldier", new Soldier()}};

/* Gets user input
 * Sets string to all lower case for comparison
 * Returns string
 */
string processInput() {
	string input;
	cin >> input;

	transform(input.begin(), input.end(), input.begin(), ::tolower);

	return input;
}

/* Takes reference to playerClass
 * Sets playerClass to cClass
 */
void setClass(_class *&playerClass) {
	string cClass = processInput();
	playerClass = classes[cClass];
}

/* Takes reference to playerRace
 * Sets playerRace to race
 */
void setRace(_race *&playerRace) {
	string race = processInput();
	playerRace = races[race];
}

/* Takes reference to playerBackground
 * Sets playerBackground to background
 */
void setBackground(_background *&playerBackground) {
	string background = processInput();
	playerBackground = backgrounds[background];
}

/* Used to test the player class
 * Takes no input and returns nothing
 * Outputs results of functions to console
 */
int main() {
	_player player;

	int *stats = fillStats();

	toString(stats);

	cout << "Class: ";
	setClass(player.playerClass);

	player.setStats(stats);
	cout << "Stats [Str, Dex, Con, Int, Wis, Cha]: " << endl;
	toString(player.getStats());

	player.setHitDie();
	cout << "Hit Die: " << player.getHitDie() << endl << endl;

	player.setSaves();
	cout << "Saves: " << endl;
	vToString(player.getSaves());

	player.setProfs();
	cout << "Armor Prof: " << endl;
	vToString(player.getArmorProf());
	cout << "Weapon Prof: " << endl;
	vToString(player.getWeaponProf());
	cout << "Tool Prof: " << endl;
	vToString(player.getToolProf());

	player.setMaxHealth();
	cout << "Max Health: " << player.getMaxHealth() << endl;
	cout << "Current Health: " << player.getCurrentHealth() << endl << endl;

	cout << "Race: ";
	setRace(player.playerRace);

	player.buffStats();
	cout << "Stats [Str, Dex, Con, Int, Wis, Cha]: " << endl;
	toString(player.getStats());

	player.setSpeed();
	cout << "Speed: " << player.getSpeed() << endl << endl;

	player.setTraits();
	cout << "Traits: " << endl;
	vToString(player.getTraits());

	player.setMaxHealth();
	cout << "Max Health: " << player.getMaxHealth() << endl;
	cout << "Current Health: " << player.getCurrentHealth() << endl << endl;

	cout << "Background: ";
	setBackground(player.playerBackground);

	player.setLanguages();
	cout << endl << "Languages: " << endl;
	vToString(player.getLanguages());

	player.setSkills();
	cout << endl << "Skills: " << endl;
	vToString(player.getSkills());

	return 0;
}

/* Take no input
 * Roll 4d6 6 times
 * Saves the sums of 4d6 drop the lowest
 * Returns the sorted pointer array of calculated stats
 */
int *fillStats() {
	static int stats[6];

	srand((unsigned)time(NULL));

	for (int i = 0; i < 6; i++) {
		int sum = 0;
		int lowest = 7;
		int value = 0;

		for (int j = 0; j < 4; j++) {
			value = ((rand() % D6) + 1);
			sum += value;

			if (value < lowest)
				lowest = value;
		}

		stats[i] = sum - value;
	}

	heapSort(stats, sizeof(stats) / sizeof(stats[0]));

	return stats;
}
