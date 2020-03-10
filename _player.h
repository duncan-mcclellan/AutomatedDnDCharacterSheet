#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include "toString.h"
#include "_class.h"
#include "_race.h"
#include "_background.h"

class _player{
  private:
    int* stats;
    int hitDie;
    int level;
    int speed;
    int maxHealth;
    int currentHealth;
    int profBonus = 2;
    vector<string> saves;
    vector<string> traits;
    vector<string> armorProf;
    vector<string> weaponProf;
    vector<string> toolProf;
    vector<string> equipment;
    vector<string> skills;
    vector<string> languages;

  public:
    _class *playerClass;
    _race *playerRace;
    _background *playerBackground;

    void setStats(int *stats){
      playerClass->setStats(stats);
      this->stats = stats;
    }

    int* getStats(){return this->stats;}

    void buffStats(){playerRace->buffStats(this->stats);}

    void setHitDie(){this->hitDie = playerClass->getHitDie();}

    int getHitDie(){return this->hitDie;}

    void setSaves(){playerClass->setSaves(&saves);}

    vector<string> getSaves(){return this->saves;}

    void setProfs(){playerClass->setProfs(&armorProf, &weaponProf, &toolProf);}

    vector<string> getArmorProf(){return this->armorProf;}

    vector<string> getWeaponProf(){return this->weaponProf;}
    
    vector<string> getToolProf(){return this->toolProf;}

    void setStartingEquipment(){playerClass->setStartingEquipment(&equipment);}

    void setSpeed(){this->speed = playerClass->calcSpeed();}

    void setTraits(){playerRace->setTraits(&traits);}

    vector<string> getTraits(){return this->traits;}

    void setLanguages(){
      for(int i = 0; i < (sizeof langs) / (sizeof *langs); i++){
        allLangs.push_back(langs[i]);
      }
      this->languages.push_back("Common");
      this->playerClass->addLanguages(&languages);
      //this->playerRace->setLanguages(&languages);
      this->playerBackground->addLanguages(&languages);
      this->playerRace->addLanguages(&languages);
    }

    vector<string> getLanguages(){return this->languages;}

    void setSkills(){
      this->playerClass->addSkills(&skills);
      this->playerBackground->addSkills(&skills);
    }

    vector<string> getSkills(){return this->skills;}

    void setStartingSpells(){}

    void setMaxHealth(){
      this->maxHealth = this->hitDie + ((*(this->stats + con))/2 - 5);
      this->currentHealth = this->maxHealth;
    }

    int getMaxHealth(){return this->maxHealth;}

    int getCurrentHealth(){return this->currentHealth;}

    void levelUp(){}
};

#endif
