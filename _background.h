#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include "languages.h"

class _background{
  public:
    virtual void addSkills(vector<string> *skills) = 0;
    virtual void addLanguages(vector<string> *languages){};
};

class Acolyte : public _background{
  public:
    void addSkills(vector<string> *skills){
      (*skills).push_back("Insight");
      (*skills).push_back("Religion");
    }

    void addLanguages(vector<string> *languages){
      string lang;
      bool c = false;
      do{
        cout << "[";
        for (auto it = allLangs.cbegin(); it != allLangs.cend(); ++it){
          std::cout << *it;
          if(*it != allLangs.back())
            cout << ", ";
        }
        cout << "]: ";
        std::cin >> lang;
        for(std::list<string>::iterator it = allLangs.begin(); it != allLangs.end(); it++)
          if(boost::iequals(lang, *it))
            c = true;
      }while(!c);
      (*languages).push_back(lang);
      allLangs.remove(lang);

      c = false;
      do{
        cout << "[";
        for (auto it = allLangs.cbegin(); it != allLangs.cend(); ++it){
          std::cout << *it;
          if(*it != allLangs.back())
            cout << ", ";
        }
        cout << "]: ";
        std::cin >> lang;
        for(std::list<string>::iterator it = allLangs.begin(); it != allLangs.end(); it++)
          if(boost::iequals(lang, *it))
            c = true;
      }while(!c);
      (*languages).push_back(lang);
      allLangs.remove(lang);
    }
};

class Sage : public _background{
  public:
    void addSkills(vector<string> *skills){
      (*skills).push_back("Arcana");
      (*skills).push_back("History");
    }

    void addLanguages(vector<string> *languages){
      string lang;
      bool c = false;
      do{
        cout << "[";
        for (auto it = allLangs.cbegin(); it != allLangs.cend(); ++it){
          std::cout << *it;
          if(*it != allLangs.back())
            cout << ", ";
        }
        cout << "]: ";
        std::cin >> lang;
        for(std::list<string>::iterator it = allLangs.begin(); it != allLangs.end(); it++)
          if(boost::iequals(lang, *it))
            c = true;
      }while(!c);
      (*languages).push_back(lang);
      allLangs.remove(lang);
      
      c = false;
      do{
        cout << "[";
        for (auto it = allLangs.cbegin(); it != allLangs.cend(); ++it){
          std::cout << *it;
          if(*it != allLangs.back())
            cout << ", ";
        }
        cout << "]: ";
        std::cin >> lang;
        for(std::list<string>::iterator it = allLangs.begin(); it != allLangs.end(); it++)
          if(boost::iequals(lang, *it))
            c = true;
      }while(!c);
      (*languages).push_back(lang);
      allLangs.remove(lang);
    }
};

class HauntedOne : public _background{
  public:
    void addSkills(vector<string> *skills){
      string s[] = {"Arcana", "Investigation", "Religion", "Survival"};
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

    void addLanguages(vector<string> *languages){
      string lang;
      bool c = false;
      do{
        cout << "[";
        for (int i = 0; i < (sizeof(exotics)/sizeof(*exotics)); i++){
          std::cout << exotics[i];
          if(i != 7)
            cout << ", ";
        }
        cout << "]: ";
        std::cin >> lang;
        for(int i = 0; i < (sizeof(exotics)/sizeof(*exotics)); i++)
          if(boost::iequals(lang, exotics[i]))
            c = true;
      }while(!c);
      (*languages).push_back(lang);
      allLangs.remove(lang);
    }
};

class Noble : public _background{
  public:
    void addSkills(vector<string> *skills){
      (*skills).push_back("Persuasion");
      (*skills).push_back("History");
    }

    void addLanguages(vector<string> *languages){
      string lang;
      bool c = false;
      do{
        cout << "[";
        for (auto it = allLangs.cbegin(); it != allLangs.cend(); ++it){
          std::cout << *it;
          if(*it != allLangs.back())
            cout << ", ";
        }
        cout << "]: ";
        std::cin >> lang;
        for(std::list<string>::iterator it = allLangs.begin(); it != allLangs.end(); it++)
          if(boost::iequals(lang, *it))
            c = true;
      }while(!c);
      (*languages).push_back(lang);
      allLangs.remove(lang);
    }
};

class Criminal : public _background{
  public:
    void addSkills(vector<string> *skills){
      (*skills).push_back("Deception");
      (*skills).push_back("Stealth");
    }
};

class FolkHero : public _background{
  public:
    void addSkills(vector<string> *skills){
      (*skills).push_back("Animal Handling");
      (*skills).push_back("Survival");
    }
};

class Soldier : public _background{
  public:
    void addSkills(vector<string> *skills){
      (*skills).push_back("Athletics");
      (*skills).push_back("Intimidation");
    }
};

#endif
