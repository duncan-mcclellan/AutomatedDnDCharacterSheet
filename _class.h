#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED

//Included Libraries
#include <iostream>
#include <vector>
#include <boost/algorithm/string/predicate.hpp>

//Included Headers
#include "main.h"
#include "languages.h"

class _class{
  private:

  protected:
    int level = 1;
    int hitDie;

  public:
    virtual void setStats(int* stats) = 0;
    virtual void setSaves(vector<string> *saves) = 0;
    virtual int getHitDie() = 0;
    virtual void setProfs(vector<string> *armorProf, vector<string> *weaponProf, vector<string> *toolProf) = 0;
    virtual void setStartingEquipment(vector<string> *equipment){};
    virtual void addSkills(vector<string> *skills){};
    virtual void addLanguages(vector<string> *languages){};
};

class Barbarian : public _class{
  protected:
    int hitDie = 12;

  public:
    void setStats(int* stats){
      int sorted[6];
      sorted[str] = *(stats + 5);
      sorted[con] = *(stats + 4);
      sorted[dex] = *(stats + 3);
      sorted[wis] = *(stats + 2);
      sorted[cha] = *(stats + 1);
      sorted[intel] = *stats;

      for(int i = 0; i < 6; i++)
        *(stats + i) = sorted[i];
    }

    void setSaves(vector<string> *saves){
      (*saves).push_back(stat[str]);
      (*saves).push_back(stat[con]);
    }

    int getHitDie(){return hitDie;}

    void setProfs(vector<string> *armorProf, vector<string> *weaponProf, vector<string> *toolProf){
      (*armorProf).push_back("Light");
      (*armorProf).push_back("Medium");
      (*armorProf).push_back("Shields");
      (*weaponProf).push_back("Simple");
      (*weaponProf).push_back("Martial");
    }

    void addSkills(vector<string> *skills){
      string s[] = {"Animal_Handling", "Athletics", "Intimidation", "Nature", "Perception", "Survival"};
      string skip = "";
      for(int i = 0; i < 2; i++){
        bool c = false;
        do{
          cout << "["
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip)){
              cout << s[j];
              if(j != (sizeof(s)/sizeof(*s) - 1)
                cout << ", ";
            }
          cout << "]: "
          string skill;
          cin >> skill;
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip))
              if(boost::iequals(skill, s[j])){
                skip = s[j]
                c = true;
              }
        }while(!c);
        (*skills).push_back(skill);
      }
    }
};

class Bard : public _class{
  protected:
    int hitDie = 8;

  public:
    void setStats(int* stats){
      int sorted[6];
      sorted[cha] = *(stats + 5);
      sorted[dex] = *(stats + 4);
      sorted[con] = *(stats + 3);
      sorted[wis] = *(stats + 2);
      sorted[str] = *(stats + 1);
      sorted[intel] = *stats;

      for(int i = 0; i < 6; i++)
        *(stats + i) = sorted[i];
    }

    void setSaves(vector<string> *saves){
      (*saves).push_back(stat[dex]);
      (*saves).push_back(stat[cha]);
    }

    int getHitDie(){return hitDie;}

    void setProfs(vector<string> *armorProf, vector<string> *weaponProf, vector<string> *toolProf){
      string instruments[] = {"Bagpipes", "Drum", "Dulcimer", "Flute", "Lute", "Lyre", "Horn", "Pan_flute", "Shawm", "Viol"};
      string tool;
      (*armorProf).push_back("Light");
      (*weaponProf).push_back("Simple");
      (*weaponProf).push_back("Hand crossbows");
      (*weaponProf).push_back("Longswords");
      (*weaponProf).push_back("Rapiers");
      (*weaponProf).push_back("Shortswords");

      for(int i = 0; i < 3; i++){
        bool c = false;
        int tracker = sizeof(instruments)/sizeof(*instruments) - (i + 1), counter = 0;
        do{
          cout << "[";
          for(int j = 0; j < sizeof(instruments)/sizeof(*instruments); j++)
            if(i == 0 || (i == 1 && (i > 0 && !boost::iequals((*toolProf).at(0), instruments[j]))) || ((i > 0 && !boost::iequals((*toolProf).at(0), instruments[j])) && (i > 1 && !boost::iequals((*toolProf).at(1), instruments[j])))){
            cout << instruments[j];
              if(counter++ != tracker){
                cout << ", ";
              }
            }
          cout << "]: ";
          cin >> tool;
          for(int j = 0; j < sizeof(instruments)/sizeof(*instruments); j++)
            if(boost::iequals(tool, instruments[j]))
              c = true;
        }while(!c);

        (*toolProf).push_back(tool);
      }
      cout << endl;
    }

    void addSkills(vector<string> *skills){
      string s[] = {"Acrobatics", "Animal_Handling", "Arcana", "Athletics", "Deception", "History", "Insight", "Intimidation", "Investigation", "Medicine", "Nature", "Perception", "Performance", "Persuasion", "Religion", "Sleight_of_Hand", "Stealth", "Survival"};
      string skip[] = {"", "", ""};
      for(int i = 0; i < 3; i++){
        bool c = false;
        do{
          cout << "["
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip)){
              cout << s[j];
              if(j != (sizeof(s)/sizeof(*s) - 1)
                cout << ", ";
            }
          cout << "]: "
          string skill;
          cin >> skill;
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip))
              if(boost::iequals(skill, s[j])){
                skip = s[j]
                c = true;
              }
        }while(!c);
        (*skills).push_back(skill);
      }
    }
};

class Cleric : public _class{
  protected:
    int hitDie = 8;

  public:
    void setStats(int* stats){
      int sorted[6];
      sorted[wis] = *(stats + 5);
      sorted[con] = *(stats + 3);
      sorted[cha] = *(stats + 2);
      sorted[intel] = *stats;

      string s;
      bool c = true;
      do{
        c = true;
        cout << "str or dex (str is better for being in the battle, dex is better for being being at a range): ";
        cin >> s;
        if(boost::iequals(s, "str")){
          sorted[str] = *(stats + 4);
          sorted[dex] = *(stats + 1);
        }else if(boost::iequals(s, "dex")){
          sorted[str] = *(stats + 1);
          sorted[dex] = *(stats + 4);
        }else{
          c = false;
        }
      }while(!c);

      for(int i = 0; i < 6; i++)
        *(stats + i) = sorted[i];
    }

    void setSaves(vector<string> *saves){
      (*saves).push_back(stat[wis]);
      (*saves).push_back(stat[cha]);
    }

    int getHitDie(){return hitDie;}

    void setProfs(vector<string> *armorProf, vector<string> *weaponProf, vector<string> *toolProf){
      (*armorProf).push_back("Light");
      (*armorProf).push_back("Medium");
      (*armorProf).push_back("Shields");
      (*weaponProf).push_back("Simple"); 
    }

    void addSkills(vector<string> *skills){
      string s[] = {"History", "Insight", "Medicine", "Persuasion", "Religion"};
      string skip = "";
      for(int i = 0; i < 2; i++){
        bool c = false;
        do{
          cout << "["
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip)){
              cout << s[j];
              if(j != (sizeof(s)/sizeof(*s) - 1)
                cout << ", ";
            }
          cout << "]: "
          string skill;
          cin >> skill;
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip))
              if(boost::iequals(skill, s[j])){
                skip = s[j]
                c = true;
              }
        }while(!c);
        (*skills).push_back(skill);
      }
    }
};

class Druid : public _class{
  protected:
    int hitDie = 8;

  public:
    //Look at for automation improvement
    void setStats(int* stats){
      int sorted[6];
      sorted[wis] = *(stats + 5);
      sorted[dex] = *(stats + 4);
      sorted[con] = *(stats + 3);
      sorted[cha] = *(stats + 2);
      sorted[intel] = *(stats + 1);
      sorted[str] = *stats;

      for(int i = 0; i < 6; i++)
        *(stats + i) = sorted[i];
    }

    void setSaves(vector<string> *saves){
      (*saves).push_back(stat[intel]);
      (*saves).push_back(stat[wis]);
    }

    int getHitDie(){return hitDie;}

    void addLanguages(vector<string> *languages){
      (*languages).push_back("Druidic");
      allLangs.remove("Druidic");
    }

    void setProfs(vector<string> *armorProf, vector<string> *weaponProf, vector<string> *toolProf){
      (*armorProf).push_back("Light");
      (*armorProf).push_back("Medium (Nonmetal)");
      (*armorProf).push_back("Shields (Nonmetal)");
      (*weaponProf).push_back("Clubs");
      (*weaponProf).push_back("Daggers");
      (*weaponProf).push_back("Darts");
      (*weaponProf).push_back("Javelins");
      (*weaponProf).push_back("Maces");
      (*weaponProf).push_back("Quarterstaffs");
      (*weaponProf).push_back("Scimitars");
      (*weaponProf).push_back("Sickles");
      (*weaponProf).push_back("Slings");
      (*weaponProf).push_back("Spears");
      (*toolProf).push_back("Herbalism Kit");
    }

    void addSkills(vector<string> *skills){
      string s[] = {"Animal_Handling", "Arcana", "Insight", "Medicine", "Nature", "Perception", "Religion", "Survival"};
      string skip = "";
      for(int i = 0; i < 2; i++){
        bool c = false;
        do{
          cout << "["
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip)){
              cout << s[j];
              if(j != (sizeof(s)/sizeof(*s) - 1)
                cout << ", ";
            }
          cout << "]: "
          string skill;
          cin >> skill;
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip))
              if(boost::iequals(skill, s[j])){
                skip = s[j]
                c = true;
              }
        }while(!c);
        (*skills).push_back(skill);
      }
    }
};

class Fighter : public _class{
  protected:
    int hitDie = 10;

  public:
    void setStats(int* stats){
      int sorted[6];
      std::string subclass;

      std::cout << "Subclass: ";
      std::cin >> subclass;

      if(boost::iequals(subclass, "ELDRITCH_KNIGHT")){
        sorted[con] = *(stats + 3);
        sorted[cha] = *(stats + 2);
        sorted[wis] = *stats;
        sorted[intel] = *(stats + 4);

        string s;
        bool c = true;
        do{
          c = true;
          cout << "str or dex (str is better for being in the battle, dex is better for being being at a range): ";
          cin >> s;
          if(boost::iequals(s, "str")){
            sorted[str] = *(stats + 5);
            sorted[dex] = *(stats + 1);
          }else if(boost::iequals(s, "dex")){
            sorted[str] = *(stats + 1);
            sorted[dex] = *(stats + 5);
          }else{
            c = false;
          }
        }while(!c);
      }else{
        sorted[con] = *(stats + 4);
        sorted[cha] = *(stats + 2);
        sorted[wis] = *(stats + 1);
        sorted[intel] = *stats;

        string s;
        bool c = true;
        do{
          c = true;
          cout << "str or dex (str is better for being in the battle, dex is better for being being at a range): ";
          cin >> s;
          if(boost::iequals(s, "str")){
            sorted[str] = *(stats + 5);
            sorted[dex] = *(stats + 3);
          }else if(boost::iequals(s, "dex")){
            sorted[str] = *(stats + 3);
            sorted[dex] = *(stats + 5);
          }else{
            c = false;
          }
        }while(!c);
      }

      for(int i = 0; i < 6; i++)
        *(stats + i) = sorted[i];
    }

    void setSaves(vector<string> *saves){
      (*saves).push_back(stat[str]);
      (*saves).push_back(stat[con]);
    }

    int getHitDie(){return hitDie;}

    void setProfs(vector<string> *armorProf, vector<string> *weaponProf, vector<string> *toolProf){
      (*armorProf).push_back("Light");
      (*armorProf).push_back("Medium");
      (*armorProf).push_back("Heavy");
      (*weaponProf).push_back("Simple");
      (*weaponProf).push_back("Martial");
    }

    void addSkills(vector<string> *skills){
      string s[] = {"Acrobatics", "Animal_Handling", "Athletics", "History", "Insight", "Intimidation", "Perception", "Survival"};
      string skip = "";
      for(int i = 0; i < 2; i++){
        bool c = false;
        do{
          cout << "["
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip)){
              cout << s[j];
              if(j != (sizeof(s)/sizeof(*s) - 1)
                cout << ", ";
            }
          cout << "]: "
          string skill;
          cin >> skill;
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip))
              if(boost::iequals(skill, s[j])){
                skip = s[j]
                c = true;
              }
        }while(!c);
        (*skills).push_back(skill);
      }
    }
};

class Monk : public _class{
  protected:
    int hitDie = 8;

  public:
    void setStats(int* stats){
      int sorted[6];
      sorted[dex] = *(stats + 5);
      sorted[wis] = *(stats + 4);
      sorted[intel] = *(stats + 1);
      sorted[str] = *stats;

      string s;
      bool c = true;
      do{
        c = true;
        cout << "con or cha (con will provide more health for better battling, con will help avoid battle by talking things out): ";
        cin >> s;
        if(boost::iequals(s, "con")){
          sorted[con = *(stats + 3);
          sorted[cha] = *(stats + 2);
        }else if(boost::iequals(s, "cha")){
          sorted[con] = *(stats + 2);
          sorted[cha] = *(stats + 3);
        }else{
          c = false;
        }
      }while(!c);

      for(int i = 0; i < 6; i++)
        *(stats + i) = sorted[i];
    }

    void setSaves(vector<string> *saves){
      (*saves).push_back(stat[str]);
      (*saves).push_back(stat[dex]);
    }

    int getHitDie(){return hitDie;}

    void setProfs(vector<string> *armorProf, vector<string> *weaponProf, vector<string> *toolProf){
      string tool;
      bool c1 = true, c2 = false;
      (*weaponProf).push_back("Simple"); 
      (*weaponProf).push_back("Shortswords");
      
      do{
        c1 = true;
        cout << "artisan or instrument: ";
        cin >> tool;

        if(boost::iequals(tool, "artisan")){
          string tools[] = {"Alchemist", "Brewer", "Calligrapher", "Carpenter", "Cartographer", "Cobbler", "Cook", "Glassblower", "Jeweler", "Leatherworker", "Mason", "Painter", "Potter", "Smith", "Tinker", "Weaver", "Woodcarver"};
          do{
            cout << "[Alchemist, Brewer, Calligrapher, Carpenter, Cartographer, Cobbler, Cook, Glassblower, Jeweler, Leatherworker, Mason, Painter, Potter, Smith, Tinker, Weaver, Woodcarver]: ";
            cin >> tool;
            for(int i = 0; i < (sizeof(tools)/sizeof(*tools)); i++)
              if(boost::iequals(tool, tools[i]))
                c2 = true;
          }while(!c2);
        }else if(tool == "instrument"){
          string instruments[] = {"Bagpipes", "Drum", "Dulcimer", "Flute", "Lute", "Lyre", "Horn", "Pan_flute", "Shawm", "Viol"};
          do{
            cout << "[Bagpipes, Drum, Dulcimer, Flute, Lute, Lyre, Horn, Pan_flute, Shawm, Viol]: ";
            cin >> tool;
            for(int i = 0; i < (sizeof(instruments)/sizeof(*instruments)); i++)
              if(boost::iequals(tool, instruments[i]))
                c2 = true;
          }while(!c2);
        }else{
          cout << "Invalid selection" << endl;
          c1 = false;
        }
      }while(!c1);
        
      (*toolProf).push_back(tool);
    }

    void addSkills(vector<string> *skills){
      string s[] = {"Acrobatics", "Athletics", "History", "Insight", "Religion", "Stealth"};
      string skip = "";
      for(int i = 0; i < 2; i++){
        bool c = false;
        do{
          cout << "["
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip)){
              cout << s[j];
              if(j != (sizeof(s)/sizeof(*s) - 1)
                cout << ", ";
            }
          cout << "]: "
          string skill;
          cin >> skill;
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip))
              if(boost::iequals(skill, s[j])){
                skip = s[j]
                c = true;
              }
        }while(!c);
        (*skills).push_back(skill);
      }
    }
};

class Paladin : public _class{
  protected:
    int hitDie = 10;

  public:
    void setStats(int* stats){
      int sorted[6];
      sorted[str] = *(stats + 5);
      sorted[con] = *(stats + 4);
      sorted[cha] = *(stats + 3);
      sorted[dex] = *(stats + 2);
      sorted[wis] = *(stats + 1);
      sorted[intel] = *stats;

      for(int i = 0; i < 6; i++)
        *(stats + i) = sorted[i];
    }

    void setSaves(vector<string> *saves){
      (*saves).push_back(stat[wis]);
      (*saves).push_back(stat[cha]);
    }

    int getHitDie(){return hitDie;}

    void setProfs(vector<string> *armorProf, vector<string> *weaponProf, vector<string> *toolProf){
      (*armorProf).push_back("Light");
      (*armorProf).push_back("Medium");
      (*armorProf).push_back("Heavy");
      (*armorProf).push_back("Shields");
      (*weaponProf).push_back("Simple");
      (*weaponProf).push_back("Martial");
    }

    void addSkills(vector<string> *skills){
      string s[] = {"Athletics", "Insight", "Intimidation", "Medicine", "Perception", "Religion"};
      string skip = "";
      for(int i = 0; i < 2; i++){
        bool c = false;
        do{
          cout << "["
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip)){
              cout << s[j];
              if(j != (sizeof(s)/sizeof(*s) - 1)
                cout << ", ";
            }
          cout << "]: "
          string skill;
          cin >> skill;
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip))
              if(boost::iequals(skill, s[j])){
                skip = s[j]
                c = true;
              }
        }while(!c);
        (*skills).push_back(skill);
      }
    }
};

class Ranger : public _class{
  protected:
    int hitDie = 10;

  public:
    void setStats(int* stats){
      int sorted[6];
      sorted[dex] = *(stats + 5);
      sorted[wis] = *(stats + 4);
      sorted[con] = *(stats + 3);
      sorted[cha] = *(stats + 2);
      sorted[intel] = *(stats + 1);
      sorted[str] = *stats;

      for(int i = 0; i < 6; i++)
        *(stats + i) = sorted[i];
    }

    void setSaves(vector<string> *saves){
      (*saves).push_back(stat[str]);
      (*saves).push_back(stat[dex]);
    }

    int getHitDie(){return hitDie;}

    void setProfs(vector<string> *armorProf, vector<string> *weaponProf, vector<string> *toolProf){
      (*armorProf).push_back("Light");
      (*armorProf).push_back("Medium");
      (*armorProf).push_back("Shields");
      (*weaponProf).push_back("Simple");
      (*weaponProf).push_back("Martial");
    }

    void addSkills(vector<string> *skills){
      string s[] = {"Animal_Handling", "Athletics", "Insight", "Investigation", "Nature", "Perception", "Stealth", "Survival"};
      string skip[] = {"", "", ""};
      for(int i = 0; i < 3; i++){
        bool c = false;
        do{
          cout << "["
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip)){
              cout << s[j];
              if(j != (sizeof(s)/sizeof(*s) - 1)
                cout << ", ";
            }
          cout << "]: "
          string skill;
          cin >> skill;
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip))
              if(boost::iequals(skill, s[j])){
                skip = s[j]
                c = true;
              }
        }while(!c);
        (*skills).push_back(skill);
      }
    }
};

class Sorcerer : public _class{
  protected:
    int hitDie = 6;

  public:
    void setStats(int* stats){
      int sorted[6];
      sorted[con] = *(stats + 5);
      sorted[dex] = *(stats + 4);
      sorted[con] = *(stats + 3);
      sorted[wis] = *(stats + 2);
      sorted[intel] = *(stats + 1);
      sorted[str] = *stats;

      for(int i = 0; i < 6; i++)
        *(stats + i) = sorted[i];
    }

    void setSaves(vector<string> *saves){
      (*saves).push_back(stat[con]);
      (*saves).push_back(stat[cha]);
    }

    int getHitDie(){return hitDie;}

    void setProfs(vector<string> *armorProf, vector<string> *weaponProf, vector<string> *toolProf){
      (*weaponProf).push_back("Daggers");
      (*weaponProf).push_back("Darts");
      (*weaponProf).push_back("Slings");
      (*weaponProf).push_back("Quarterstaffs");
      (*weaponProf).push_back("Light crossbows");
    }

    void addSkills(vector<string> *skills){
      string s[] = {"Arcana", "Deception", "Insight", "Intimidation", "Persuasion", "Religion"};
      string skip = "";
      for(int i = 0; i < 2; i++){
        bool c = false;
        do{
          cout << "["
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip)){
              cout << s[j];
              if(j != (sizeof(s)/sizeof(*s) - 1)
                cout << ", ";
            }
          cout << "]: "
          string skill;
          cin >> skill;
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip))
              if(boost::iequals(skill, s[j])){
                skip = s[j]
                c = true;
              }
        }while(!c);
        (*skills).push_back(skill);
      }
    }
};

class Warlock : public _class{
  protected:
    int hitDie = 8;

  public:
    void setStats(int* stats){
      int sorted[6];
      sorted[cha] = *(stats + 5);
      sorted[intel] = *stats;

      string pact;
      bool c1 = true;
      do{
        c1 = true;
        cout << "Pick a pact (Chain, Tome, or Blade): "
        cin >> pact;
        if(boost::iequals(pact, "chain") || boost::iequals(pact, "tome")){
          sorted[con] = *(stats + 4);
          sorted[dex] = *(stats + 3);
          sorted[wis] = *(stats + 2);
          sorted[str] = *(stats + 1);
        }else if(boost::iequals(pact, "blade")){
          sorted[con] = *(stats + 3);
          
          string s;
          bool c2 = true;
          do{
            c2 = true;
            cout << "str or dex (str is better for melee weapons, dex is better for ranged weapons):";
            cin >> s;
            if(boost::iequals(s, "str")){
              sorted[dex] = *(stats + 2);
              sorted[wis] = *(stats + 1);
              sorted[str] = *(stats + 4);
            }else if(boost::iequals(s, "dex")){
              sorted[dex] = *(stats + 4);
              sorted[wis] = *(stats + 2);
              sorted[str] = *(stats + 1);
            }else{
              c2 = false;
            }
          }while(!c2);
        }else{
          c1 = false;
        }
      }while(!c1);

      for(int i = 0; i < 6; i++)
        *(stats + i) = sorted[i];
    }

    void setSaves(vector<string> *saves){
      (*saves).push_back(stat[wis]);
      (*saves).push_back(stat[cha]);
    }

    int getHitDie(){return hitDie;}

    void setProfs(vector<string> *armorProf, vector<string> *weaponProf, vector<string> *toolProf){
      (*armorProf).push_back("Light");
      (*weaponProf).push_back("Simple");
    }

    void addSkills(vector<string> *skills){
      string s[] = {"Arcana", "Deception", "History", "Intimidation", "Investigation", "Nature", "Religion"};
      string skip = "";
      for(int i = 0; i < 2; i++){
        bool c = false;
        do{
          cout << "["
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip)){
              cout << s[j];
              if(j != (sizeof(s)/sizeof(*s) - 1)
                cout << ", ";
            }
          cout << "]: "
          string skill;
          cin >> skill;
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip))
              if(boost::iequals(skill, s[j])){
                skip = s[j]
                c = true;
              }
        }while(!c);
        (*skills).push_back(skill);
      }
    }
};

class Wizard : public _class{
  protected:
    int hitDie = 6;

  public:
    //Allow for more customization? 
    void setStats(int* stats){
      int sorted[6];
      sorted[intel] = *(stats + 5);
      sorted[con] = *(stats + 4);
      sorted[dex] = *(stats + 3);
      sorted[wis] = *(stats + 2);
      sorted[cha] = *(stats + 1);
      sorted[str] = *stats;

      for(int i = 0; i < 6; i++)
        *(stats + i) = sorted[i];
    }

    void setSaves(vector<string> *saves){
      (*saves).push_back(stat[intel]);
      (*saves).push_back(stat[wis]);
    }

    int getHitDie(){return hitDie;}

    void setProfs(vector<string> *armorProf, vector<string> *weaponProf, vector<string> *toolProf){
      (*weaponProf).push_back("Daggers");
      (*weaponProf).push_back("Darts");
      (*weaponProf).push_back("Slings");
      (*weaponProf).push_back("Quarterstaffs");
      (*weaponProf).push_back("Light crossbows");
    }

    void addSkills(vector<string> *skills){
      string s[] = {"Arcana", "History", "Insight", "Investigation", "Medicine", "Religion"};
      string skip = "";
      for(int i = 0; i < 2; i++){
        bool c = false;
        do{
          cout << "["
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip)){
              cout << s[j];
              if(j != (sizeof(s)/sizeof(*s) - 1)
                cout << ", ";
            }
          cout << "]: "
          string skill;
          cin >> skill;
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip))
              if(boost::iequals(skill, s[j])){
                skip = s[j]
                c = true;
              }
        }while(!c);
        (*skills).push_back(skill);
      }
    }
};

class Rogue : public _class{
  protected:
    int hitDie = 8;

  public:
    void setStats(int* stats){
      int sorted[6];
      std::string subclass;

      std::cout << "Subclass: ";
      std::cin >> subclass;

      if(boost::iequals(subclass, "Thief")){
        sorted[dex] = *(stats + 5);
        sorted[cha] = *(stats + 4);
        sorted[str] = *(stats + 3);
        sorted[con] = *(stats + 2);
        sorted[wis] = *(stats + 1);
        sorted[intel] = *stats;
      }else if(boost::iequals(subclass, "Assassin")){
        sorted[dex] = *(stats + 5);
        sorted[cha] = *(stats + 4);
        sorted[wis] = *(stats + 3);
        sorted[con] = *(stats + 2);
        sorted[str] = *(stats + 1);
        sorted[intel] = *stats;
      }else if(boost::iequals(subclass, "Arcane")){
        sorted[dex] = *(stats + 5);
        sorted[intel] = *(stats + 4);
        sorted[con] = *(stats + 3);
        sorted[cha] = *(stats + 2);
        sorted[wis] = *(stats + 1);
        sorted[str] = *stats;
      }

      for(int i = 0; i < 6; i++)
        *(stats + i) = sorted[i];
    }

    void setSaves(vector<string> *saves){
      (*saves).push_back(stat[dex]);
      (*saves).push_back(stat[intel]);
    }

    int getHitDie(){return hitDie;}

    void addLanguages(vector<string> *languages){
      (*languages).push_back("Thieves' Cant");
      allLangs.remove("Thieves' Cant");
    }

    void setProfs(vector<string> *armorProf, vector<string> *weaponProf, vector<string> *toolProf){
      (*armorProf).push_back("Light");
      (*weaponProf).push_back("Simple");
      (*weaponProf).push_back("Hand crossbows");
      (*weaponProf).push_back("Longswords");
      (*weaponProf).push_back("Rapiers");
      (*weaponProf).push_back("Shortswords");
      (*toolProf).push_back("Thieves' Tools");
    }

    void addSkills(vector<string> *skills){
      string s[] = {"Acrobatics", "Athletics", "Deception", "Insight", "Intimidation", "Investigation", "Perception", "Performance", "Persuasion", "Sleight_of_Hand", "Stealth"};
      string skip[] = {"", "", "", ""};
      for(int i = 0; i < 4; i++){
        bool c = false;
        do{
          cout << "["
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip)){
              cout << s[j];
              if(j != (sizeof(s)/sizeof(*s) - 1)
                cout << ", ";
            }
          cout << "]: "
          string skill;
          cin >> skill;
          for(int j = 0; j < (sizeof(s)/sizeof(*s)); j++)
            if(boost::iequals(s[j], skip))
              if(boost::iequals(skill, s[j])){
                skip = s[j]
                c = true;
              }
        }while(!c);
        (*skills).push_back(skill);
      }
    }
};

#endif
