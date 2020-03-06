/* Author: Duncan McClellan
 * Created: 01/13/2020
 * Tested: Untested
 * Version: 0.1.1
 * Updated: 03/06/2020
 *
 * Desc: 
 * A D&D 5e character sheet that fills your stats, proficiencies, etc. to allow a character to be created with minimal effort.
 * This should lower the barrier of entry for new players.
 * Not recommended for experienced players that wish to trail off the beaten path.
 * 
 * Changelog:
 * 0.1.0: Auto rolls stats, organizes stats for class, sets save roll stats, sets armor and weapon proficiencies, sets hit die, boosts stats based on race, sets starting health.
 * 0.1.1: Saves are displayed as the stat name rather than their array location. Languages are assigned and extra languages can be choosen when appropriate.
 * 0.2.0: Refactored code.
 *
 * Known Issues:
 * Proficiency assignment doesn't work for Bard due to instrument selection not working yet.
 * Proficiency assignment doesn't work for Monk due to not allowing selection between artisan tool or instrument and the selections that will come after.
 */

//Included Libraries
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>

using namespace std;

//Included Headers
#include "main.h"
#include "_player.h"
#include "toString.h"
#include "heapSort.h"

/* Takes cClass string and reference to playerClass
 * Sets playerClass to cClass
 */
void setClass(string cClass, _class*& playerClass){
  if(cClass == "Barbarian"){
    playerClass = new Barbarian();
  }else if(cClass == "Bard"){
    playerClass = new Bard();
  }else if(cClass == "Cleric"){
    playerClass = new Cleric();
  }else if(cClass == "Druid"){
    playerClass = new Druid();
  }else if(cClass == "Fighter"){
    playerClass = new Fighter();
  }else if(cClass == "Monk"){
    playerClass = new Monk();
  }else if(cClass == "Paladin"){
    playerClass = new Paladin();
  }else if(cClass == "Ranger"){
    playerClass = new Ranger();
  }else if(cClass == "Rogue"){
    playerClass = new Rogue();
  }else if(cClass == "Sorcerer"){
    playerClass = new Sorcerer();
  }else if(cClass == "Warlock"){
    playerClass = new Warlock();
  }else if(cClass == "Wizard"){
    playerClass = new Wizard();
  }else{
    cout << "Invalid class option made" << endl;
  }
}

/* Takes race string and reference to playerRace
 * Sets playerRace to race
 */
void setRace(string race, _race*& playerRace){
  if(race == "Dragonborn"){
    playerRace = new Dragonborn();
  }else if(race == "Dwarf"){
    playerRace = new Dwarf();
  }else if(race == "Elf"){
    playerRace = new Elf();
  }else if(race == "Gnome"){
    playerRace = new Gnome();
  }else if(race == "Half-Elf"){
    playerRace = new HalfElf();
  }else if(race == "Halfling"){
    playerRace = new Halfling();
  }else if(race == "Half-Orc"){
    playerRace = new HalfOrc();
  }else if(race == "Human"){
    playerRace = new Human();
  }else if(race == "Tiefling"){
    playerRace = new Tiefling();
  }else{
    cout << "Invalid race option made" << endl;
  }
}

/* Takes background string and reference to playerBackground
 * Sets playerBackground to background
 */
void setBackground(string background, _background*& playerBackground){
  if(background == "Acolyte"){
    playerBackground = new Acolyte();
  }else if(background == "Criminal"){
    playerBackground = new Criminal();
  }else if(background == "Folk_Hero"){
    playerBackground = new FolkHero();
  }else if(background == "Haunted_One"){
    playerBackground = new HauntedOne();
  }else if(background == "Noble"){
    playerBackground = new Noble();
  }else if(background == "Sage"){
    playerBackground = new Sage();
  }else if(background == "Soldier"){
    playerBackground = new Soldier();
  }else{
    cout << "Invalid background option made" << endl;
  }
}

/* Used to test the player class
 * Takes no input and returns nothing
 * Outputs results of functions to console
 */
int main() {
  _player player;

  int* stats = fillStats();
  string cClass;
  string race;
  string background;

  toString(stats);

  cout << "Class: ";
  cin >> cClass;
  setClass(cClass, player.playerClass);
  
  player.setStats(stats);
  cout << "Stats: " << endl;
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
  cin >> race;

  setRace(race, player.playerRace);

  player.buffStats();
  cout << "Stats: " << endl;
  toString(player.getStats());

  player.setTraits();
  cout << "Traits: " << endl;
  vToString(player.getTraits());

  player.setMaxHealth();
  cout << "Max Health: " << player.getMaxHealth() << endl;
  cout << "Current Health: " << player.getCurrentHealth() << endl << endl;

  cout << "Background: ";
  cin >> background;
  setBackground(background, player.playerBackground);

  player.setLanguages();
  cout << "Languages: " << endl;
  vToString(player.getLanguages());

  player.setSkills();
  cout << "Skills: " << endl;
  vToString(player.getSkills());

  return 0;
}

/* Take dice rolls
 * Drop lowest valued roll
 * Return sum of saved rolls
 */
int dropLowest(int dice[4]){
  int lowest = 7; //a die can never have a value larger than 6
  int index;
  int sum = 0;

  for(int i = 0; i < 4; i++){
    if(dice[i] < lowest){
      lowest = dice[i];
      index = i;
    }
  }

  for(int i = 0; i < 4; i++){
    if(i != index){
      sum += dice[i];
    }
  }

  return sum;
}

/* Take no input
 * Roll 4d6 6 times
 * Save the sums of 4d6 drop the lowest
 * Return the sorted pointer array of calculated stats
 */
int* fillStats() {
  static int stats[6];
  int dice[4];

  srand((unsigned)time(NULL));

  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 4; j++){
      dice[j] = ((rand() % D6) + 1);
    }
    stats[i] = dropLowest(dice);
  }

  heapSort(stats, sizeof(stats)/sizeof(stats[0]));

  return stats;
}
