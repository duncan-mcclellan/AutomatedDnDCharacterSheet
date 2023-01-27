#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include "languages.h"
#include "listHandler.h"

class _background {
protected:
	void addLanguages(vector<string> *languages, int numLangs) {
		if (numLangs <= 0)
			return;

		outputStringList(allLangs);

		string lang;
		cin >> lang;

		if (!listContains(allLangs, lang)) {
			cout << "Not a valid language!" << endl;
			addLanguages(languages, numLangs);
			return;
		}

		languages->push_back(lang);
		allLangs.remove(lang);
		addLanguages(languages, --numLangs);
	}

public:
	virtual void addSkills(vector<string> *skills) = 0;
	virtual void addLanguages(vector<string> *languages){};
};

class Acolyte : public _background {
public:
	void addSkills(vector<string> *skills) {
		skills->push_back("Insight");
		skills->push_back("Religion");
	}

	void addLanguages(vector<string> *languages) {
		_background::addLanguages(languages, 2);
	}
};

class Sage : public _background {
public:
	void addSkills(vector<string> *skills) {
		skills->push_back("Arcana");
		skills->push_back("History");
	}

	void addLanguages(vector<string> *languages) {
		_background::addLanguages(languages, 2);
	}
};

class HauntedOne : public _background {
private:
	void addSkills(vector<string> *skills, list<string> s, int numSkills) {
		if (numSkills <= 0)
			return;

		outputStringList(s);

		string skill;
		cin >> skill;

		if (!listContains(s, skill)) {
			cout << "Not a valid skill!" << endl;
			addSkills(skills, s, numSkills);
			return;
		}

		skills->push_back(skill);
		s.remove(skill);
		addSkills(skills, s, --numSkills);
	}

public:
	void addSkills(vector<string> *skills) {
		list<string> s = {"Arcana", "Investigation", "Religion", "Survival"};

		addSkills(skills, s, 2);
	}

	void addLanguages(vector<string> *languages) {
		_background::addLanguages(languages, 1);
	}
};

class Noble : public _background {
public:
	void addSkills(vector<string> *skills) {
		skills->push_back("Persuasion");
		skills->push_back("History");
	}

	void addLanguages(vector<string> *languages) {
		_background::addLanguages(languages, 1);
	}
};

class Criminal : public _background {
public:
	void addSkills(vector<string> *skills) {
		skills->push_back("Deception");
		skills->push_back("Stealth");
	}
};

class FolkHero : public _background {
public:
	void addSkills(vector<string> *skills) {
		skills->push_back("Animal Handling");
		skills->push_back("Survival");
	}
};

class Soldier : public _background {
public:
	void addSkills(vector<string> *skills) {
		skills->push_back("Athletics");
		skills->push_back("Intimidation");
	}
};

#endif
