/* Author: Duncan McClellan
 * Created: 01/13/2020
 * Tested: Untested
 * Version: 0.2.3
 * Updated: 06/07/2022
 *
 * Desc: 
 * A D&D 5e character sheet that fills your stats, proficiencies, etc. to allow a character to be created with minimal effort.
 * This should lower the barrier of entry for new players and help players that just want to make a character really fast.
 * Not recommended for experienced players that wish to trail off the beaten path.
 */

//Included Libraries
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>

//This will get removed in a later version. I'm being lazy for the initial creation
using namespace std;

//Included Headers
#include "main.h"
#include "_player.h"
#include "toString.h"
#include "heapSort.h"

string processInput(){
  string input;
  cin >> string;
  
  transform(string.begin(), string.end(), string.begin(), ::tolower);
  
  return string;
}

/* Takes reference to playerClass
 * Gets user input for cClass
 * Sets playerClass to cClass
 */
void setClass(_class*& playerClass){
  string cClass = processInput();

  if(cClass.strncmp("barbarian")){
    playerClass = new Barbarian();
  }else if(cClass.strncmp("bard")){
    playerClass = new Bard();
  }else if(cClass.strncmp("cleric")){
    playerClass = new Cleric();
  }else if(cClass.strncmp("druid")){
    playerClass = new Druid();
  }else if(cClass.strncmp("fighter")){
    playerClass = new Fighter();
  }else if(cClass.strncmp("monk")){
    playerClass = new Monk();
  }else if(cClass.strncmp("paladin")){
    playerClass = new Paladin();
  }else if(cClass.strncmp("ranger")){
    playerClass = new Ranger();
  }else if(cClass.strncmp("rogue")){
    playerClass = new Rogue();
  }else if(cClass.strncmp("sorcerer")){
    playerClass = new Sorcerer();
  }else if(cClass.strncmp("warlock")){
    playerClass = new Warlock();
  }else if(cClass.strncmp("wizard")){
    playerClass = new Wizard();
  }else{
    cout << "Invalid class option made." << endl << "Selection must be Barbarian, Bard, Cleric, Druid, Fighter, Monk, Paladin, Ranger, Rogue, Sorcerer, Warlock, or Wizard" << endl;
    setClass(playerClass);
  }
  cout << endl;
}

/* Takes reference to playerRace
 * Gets user input for race
 * Sets playerRace to race
 */
void setRace(_race*& playerRace){
  string race = processInput();

  if(race == "dragonborn"){
    playerRace = new Dragonborn();
  }else if(race == "dwarf"){
    playerRace = new Dwarf();
  }else if(race == "elf"){
    playerRace = new Elf();
  }else if(race == "gnome"){
    playerRace = new Gnome();
  }else if(race == "half-elf"){
    playerRace = new HalfElf();
  }else if(race == "halfling"){
    playerRace = new Halfling();
  }else if(race == "half-orc"){
    playerRace = new HalfOrc();
  }else if(race == "human"){
    playerRace = new Human();
  }else if(race == "tiefling"){
    playerRace = new Tiefling();
  }else{
    cout << "Invalid race option made." << endl << "Selection must be Dragonborn, Dwarf, Elf, Gnome, Half-Elf, Halfling, Half-Orc, Human, or Tiefling" << endl;
    setRace(playerRace);
  }
  cout << endl;
}

/* Takes reference to playerBackground
 * Gets user input for background
 * Sets playerBackground to background
 */
void setBackground(_background*& playerBackground){
  string background = processInput();

  if(background == "acolyte"){
    playerBackground = new Acolyte();
  }else if(background == "criminal"){
    playerBackground = new Criminal();
  }else if(background == "folk_hero"){
    playerBackground = new FolkHero();
  }else if(background == "haunted_one"){
    playerBackground = new HauntedOne();
  }else if(background == "noble"){
    playerBackground = new Noble();
  }else if(background == "sage"){
    playerBackground = new Sage();
  }else if(background == "soldier"){
    playerBackground = new Soldier();
  }else{
    cout << "Invalid background option made" << endl << "Selection must be Acolyte, Criminal, Folk_Hero, Haunted_One, Noble, Sage, or Soldier" << endl;
    setBackground(playerBackground);
  }
  cout << endl;
}

/* Used to test the player class
 * Takes no input and returns nothing
 * Outputs results of functions to console
 */
int main() {
  _player player;

  int* stats = fillStats();

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
  cout << "Skills: " << endl;
  vToString(player.getSkills());

  return 0;
}

/* Take no input
 * Roll 4d6 6 times
 * Save the sums of 4d6 drop the lowest
 * Return the sorted pointer array of calculated stats
 */
int* fillStats() {
  static int stats[6];

  srand((unsigned)time(NULL));

  for(int i = 0; i < 6; i++){
    int sum = 0;
    int lowest = 7;
    
    for(int j = 0; j < 4; j++){
      int value = ((rand() % D6) + 1);
      sum += value;
      
      if(value < lowest)
        lowest = value;
    }
    
    stats[i] = sum - value;
  }

  heapSort(stats, sizeof(stats)/sizeof(stats[0]));

  return stats;
}
