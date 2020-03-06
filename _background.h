#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include "languages.h"

class _background{
  public:
    virtual void addLanguages(vector<string> *languages){};
    virtual void addSkills(vector<string> *skills){};
};

class Acolyte : public _background{
  public:
    void addLanguages(vector<string> *languages){
      string lang;
      for (auto it = allLangs.cbegin(); it != allLangs.cend(); ++it)
        std::cout << ' ' << *it;
      std::cout << ": " << endl;
      std::cin >> lang;
      (*languages).push_back(lang);
      allLangs.remove(lang);

      for (auto it = allLangs.cbegin(); it != allLangs.cend(); ++it)
        std::cout << ' ' << *it;
      std::cout << ": " << endl;
      std::cin >> lang;
      (*languages).push_back(lang);
      allLangs.remove(lang);
    }
};

class Sage : public _background{
  public:
    void addLanguages(vector<string> *languages){
      string lang;
      for (auto it = allLangs.cbegin(); it != allLangs.cend(); ++it)
        std::cout << ' ' << *it;
      std::cout << ": " << endl;
      std::cin >> lang;
      (*languages).push_back(lang);
      allLangs.remove(lang);
      
      for (auto it = allLangs.cbegin(); it != allLangs.cend(); ++it)
        std::cout << ' ' << *it;
      std::cout << ": " << endl;
      std::cin >> lang;
      (*languages).push_back(lang);
      allLangs.remove(lang);
    }
};

class HauntedOne : public _background{
  public:
    void addLanguages(vector<string> *languages){
      string lang;
      for (auto it = allLangs.cbegin(); it != allLangs.cend(); ++it)
        std::cout << ' ' << *it;
      std::cout << ": " << endl;
      std::cin >> lang;
      (*languages).push_back(lang);
      allLangs.remove(lang);
    }
};

class Noble : public _background{
  public:
    void addLanguages(vector<string> *languages){
      string lang;
      for (auto it = allLangs.cbegin(); it != allLangs.cend(); ++it)
        std::cout << ' ' << *it;
      std::cout << ": " << endl;
      std::cin >> lang;
      (*languages).push_back(lang);
      allLangs.remove(lang);
    }
};

class Criminal : public _background{

};

class FolkHero : public _background{

};

class Soldier : public _background{

};

#endif
