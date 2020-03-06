#ifndef RACE_H_INCLUDED
#define RACE_H_INCLUDED

#include "languages.h"

class _race{
  public:
    virtual void buffStats(int* stats) = 0;
    virtual void addLanguages(vector<string> *languages) = 0;
    virtual void setTraits(vector<string> *traits) = 0;
};

class Dragonborn : public _race{
  public:
    void buffStats(int* stats){
      *(stats + str) += 2;
      *(stats + cha) += 1;
    }

    void addLanguages(vector<string> *languages){
      (*languages).push_back("Draconic");
    }

    void setTraits(vector<string> *traits){
      (*traits).push_back("Draconic Ancestry");
      (*traits).push_back("Breath Weapon");
      (*traits).push_back("Damage Resistance");
    }
};

class Dwarf : public _race{
  public:
    void buffStats(int* stats){
      *(stats + con) += 2;
    }

    void addLanguages(vector<string> *languages){
      (*languages).push_back("Dwarf");
    }

    void setTraits(vector<string> *traits){
      (*traits).push_back("Darkvision");
      (*traits).push_back("Dwarven Resilience");
      (*traits).push_back("Dwarven Combat Training");
      (*traits).push_back("Stonecunning");
    }
};

class Elf : public _race{
  public:
    void buffStats(int* stats){
      *(stats + dex) += 2;
    }

    void addLanguages(vector<string> *languages){
      (*languages).push_back("Elvish");
    }

    void setTraits(vector<string> *traits){
      (*traits).push_back("Darkvision");
      (*traits).push_back("Keen Senses");
      (*traits).push_back("Fey Ancestry");
      (*traits).push_back("Trance"); 
    }
};

class Gnome : public _race{
  public:
    void buffStats(int* stats){
      *(stats + intel) += 2;
    }

    void addLanguages(vector<string> *languages){
      (*languages).push_back("Gnomish");
    }

    void setTraits(vector<string> *traits){
      (*traits).push_back("Darkvision");
      (*traits).push_back("Gnome Cunning");
    }
};

class HalfElf : public _race{
  public:
    void buffStats(int* stats){
      string st1, st2;
      *(stats + cha) += 2;

      for(int i = 0; i < 5; i++){
        cout << stat[i];
        if(i != 4){
          cout << ", ";
        }else{
          cout << ": ";
        }
      }

      cin >> st1;

      for(int i = 0; i < 5; i++){
        if(stat[i] != st1){
          cout << stat[i];
        
          if(i != 4){
            cout << ", ";
          }else{
            cout << ": ";
          }
        }
      }

      cin >> st2;

      if(st1 == "str" || st2 == "str"){
        *(stats + str) += 1;
      }
      if(st1 == "con" || st2 == "con"){
        *(stats + con) += 1;
      }
      if(st1 == "intel" || st2 == "intel"){
        *(stats + intel) += 1;
      }
      if(st1 == "wis" || st2 == "wis"){
        *(stats + wis) += 1;
      }
      if(st1 == "dex" || st2 == "dex"){
        *(stats + dex) += 1;
      }
    }

    void addLanguages(vector<string> *languages){
      cout << "addLanguages - _race" << endl;
      (*languages).push_back("Elvish");
      allLangs.remove("Elvish");
      string lang;
      for (auto it = allLangs.cbegin(); it != allLangs.cend(); ++it)
        std::cout << ' ' << *it;
      std::cout << ": " << endl;
      std::cin >> lang;
      (*languages).push_back(lang);
      allLangs.remove(lang);
    }

    void setTraits(vector<string> *traits){
      (*traits).push_back("Darkvision");
      (*traits).push_back("Fey Ancestry");
      (*traits).push_back("Skill Versatility");
    }
};

class Halfling : public _race{
  public:
    void buffStats(int* stats){
      *(stats + dex) += 2;
    }

    void addLanguages(vector<string> *languages){
      (*languages).push_back("Halfling");
    }

    void setTraits(vector<string> *traits){
      (*traits).push_back("Lucky");
      (*traits).push_back("Brave");
      (*traits).push_back("Halfling");
      (*traits).push_back("Nimbleness"); 
    }
};

class HalfOrc : public _race{
  public:
    void buffStats(int* stats){
      *(stats + str) += 2;
      *(stats + con) += 1;
    }

    void addLanguages(vector<string> *languages){
      (*languages).push_back("Orc");
    }

    void setTraits(vector<string> *traits){
      (*traits).push_back("Darkvision");
      (*traits).push_back("Menacing");
      (*traits).push_back("Relentless Endurance");
      (*traits).push_back("Savage Attacks");
    }
};

class Human : public _race{
  public:
    void buffStats(int* stats){
      *(stats + str) += 1;
      *(stats + dex) += 1;
      *(stats + con) += 1;
      *(stats + intel) += 1;
      *(stats + wis) += 1;
      *(stats + cha) += 1;
    }

    void addLanguages(vector<string> *languages){
      string lang;
      for (auto it = allLangs.cbegin(); it != allLangs.cend(); ++it)
        std::cout << ' ' << *it;
      std::cout << ": " << endl;
      std::cin >> lang;
      (*languages).push_back(lang);
      allLangs.remove(lang);
    }

    void setTraits(vector<string> *traits){
      (*traits).push_back("Extra Language"); 
    }
};

class Tiefling : public _race{
  public:
    void buffStats(int* stats){
      *(stats + cha) += 2;
      *(stats + intel) += 1;
    }

    void addLanguages(vector<string> *languages){
      (*languages).push_back("Infernal");
    }

    void setTraits(vector<string> *traits){
      (*traits).push_back("Darkvision");
      (*traits).push_back("Hellish Resistance");
      (*traits).push_back("Infernal Legacy");
    }
};

#endif
