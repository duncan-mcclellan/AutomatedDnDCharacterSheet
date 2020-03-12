/* Author: Duncan McClellan
 * Created: 01/13/2020
 * Tested: Untested
 * Version: 0.1.1
 * Updated: 03/12/2020
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
 * 0.2.1: Race, Class, and Background selection are no longer case-sensitive. Bard can now choose 3 Instruments. Monk can now choose an Artisan's Tool or an Instrument. Stats output now shows the order of stats.
 * 0.2.2: Speed now gets assigned. When selecting languages, only valid options will be accepted and languages provided by race no longer show up as an option when choosing background language(s). Fixed instrument list for Bard.
 * 0.2.3: Provided Cleric, Fighter, Monk, and Warlock much needed customization options. Skills are now assigned.
 *
 * Known Issues:
 * Skills need to remove options already selected.
 * Starting Equipment is not assigned.
 * Starting Spells are not assigned.
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

/* Takes reference to playerClass
 * Gets user input for cClass
 * Sets playerClass to cClass
 */
void setClass(_class*& playerClass){
  bool c;
  do{
    c = true;

    string cClass;
    cout << "Class: ";
    cin >> cClass;
    transform(cClass.begin(), cClass.end(), cClass.begin(), ::tolower);

    if(cClass == "barbarian"){
      playerClass = new Barbarian();
    }else if(cClass == "bard"){
      playerClass = new Bard();
    }else if(cClass == "cleric"){
      playerClass = new Cleric();
    }else if(cClass == "druid"){
      playerClass = new Druid();
    }else if(cClass == "fighter"){
      playerClass = new Fighter();
    }else if(cClass == "monk"){
      playerClass = new Monk();
    }else if(cClass == "paladin"){
      playerClass = new Paladin();
    }else if(cClass == "ranger"){
      playerClass = new Ranger();
    }else if(cClass == "rogue"){
      playerClass = new Rogue();
    }else if(cClass == "sorcerer"){
      playerClass = new Sorcerer();
    }else if(cClass == "warlock"){
      playerClass = new Warlock();
    }else if(cClass == "wizard"){
      playerClass = new Wizard();
    }else{
      cout << "Invalid class option made." << endl << "Selection must be Barbarian, Bard, Cleric, Druid, Fighter, Monk, Paladin, Ranger, Rogue, Sorcerer, Warlock, or Wizard" << endl;
      c = false;
    }
  }while(!c);
  cout << endl;
}

/* Takes reference to playerRace
 * Gets user input for race
 * Sets playerRace to race
 */
void setRace(_race*& playerRace){
  bool c;
  do{
    c = true;

    string race;
    cout << "Race: ";
    cin >> race;
    transform(race.begin(), race.end(), race.begin(), ::tolower);

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
    }
  }while(!c);
  cout << endl;
}

/* Takes reference to playerBackground
 * Gets user input for background
 * Sets playerBackground to background
 */
void setBackground(_background*& playerBackground){
  bool c;
  do{
    c = true;

    string background;
    cout << "Background: ";
    cin >> background;
    transform(background.begin(), background.end(), background.begin(), ::tolower);

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
    }
  }while(!c);
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

  setBackground(player.playerBackground);

  player.setLanguages();
  cout << endl << "Languages: " << endl;
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