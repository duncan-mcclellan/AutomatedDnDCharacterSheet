#ifndef RACE_H_INCLUDED
#define RACE_H_INCLUDED

#include "languages.h"
#include "listHandler.h"

class _race {
public:
	virtual void buffStats(int *stats) = 0;
	virtual void setLanguage(vector<string> *languages) = 0;
	virtual void setTraits(vector<string> *traits) = 0;
	virtual int getSpeed() = 0;
	virtual bool reduceSpeed() {
		return true;
	};
	virtual void addLanguage(vector<string> *languages){};
	virtual void addSkills(vector<string> *skills){};
};

class Dragonborn : public _race {
public:
	void buffStats(int *stats) {
		*(stats + str) += 2;
		*(stats + cha) += 1;
	}

	void setLanguage(vector<string> *languages) {
		allLangs.remove("Draconic");
		languages->push_back("Draconic");
	}

	void setTraits(vector<string> *traits) {
		traits->push_back("Draconic Ancestry");
		traits->push_back("Breath Weapon");
		traits->push_back("Damage Resistance");
	}

	int getSpeed() {
		return 30;
	}
};

class Dwarf : public _race {
public:
	void buffStats(int *stats) {
		*(stats + con) += 2;
	}

	void setLanguage(vector<string> *languages) {
		allLangs.remove("Dwarf");
		languages->push_back("Dwarf");
	}

	void setTraits(vector<string> *traits) {
		traits->push_back("Darkvision");
		traits->push_back("Dwarven Resilience");
		traits->push_back("Dwarven Combat Training");
		traits->push_back("Stonecunning");
	}

	int getSpeed() {
		return 25;
	}

	bool reduceSpeed() {
		return false;
	}
};

class Elf : public _race {
public:
	void buffStats(int *stats) {
		*(stats + dex) += 2;
	}

	void setLanguage(vector<string> *languages) {
		allLangs.remove("Elvish");
		languages->push_back("Elvish");
	}

	void setTraits(vector<string> *traits) {
		traits->push_back("Darkvision");
		traits->push_back("Keen Senses");
		traits->push_back("Fey Ancestry");
		traits->push_back("Trance");
	}

	int getSpeed() {
		return 30;
	}

	void addSkills(vector<string> *skills) {
		skills->push_back("Perception");
	}
};

class Gnome : public _race {
public:
	void buffStats(int *stats) {
		*(stats + intel) += 2;
	}

	void setLanguage(vector<string> *languages) {
		allLangs.remove("Gnomish");
		languages->push_back("Gnomish");
	}

	void setTraits(vector<string> *traits) {
		traits->push_back("Darkvision");
		traits->push_back("Gnome Cunning");
	}

	int getSpeed() {
		return 25;
	}
};

class HalfElf : public _race {
public:
	void buffStats(int *stats) {
		buffStats(stats, "");
	}

	void setLanguage(vector<string> *languages) {
		languages->push_back("Elvish");
		allLangs.remove("Elvish");
	}

	void addLanguage(vector<string> *languages) {
		outputStringList(allLangs);

		string lang;
		cin >> lang;

		if (!listContains(allLangs, lang)) {
			cout << "Not a valid language!" << endl;
			addLanguage(languages);
			return;
		}

		languages->push_back(lang);
		allLangs.remove(lang);
	}

	void setTraits(vector<string> *traits) {
		traits->push_back("Darkvision");
		traits->push_back("Fey Ancestry");
		traits->push_back("Skill Versatility");
	}

	int getSpeed() {
		return 30;
	}

	void addSkills(vector<string> *skills) {
		list<string> s = {"Acrobatics",
						  "Animal_Handling",
						  "Arcana",
						  "Athletics",
						  "Deception",
						  "History",
						  "Insight",
						  "Intimidation",
						  "Investigation",
						  "Medicine",
						  "Nature",
						  "Perception",
						  "Performance",
						  "Persuasion",
						  "Religion",
						  "Sleight_of_Hand",
						  "Stealth",
						  "Survival"};

		addSkills(skills, s, 2);
	}

private:
	map<string, int> statMap{{"str", str},
							 {"con", con},
							 {"intel", intel},
							 {"wis", wis},
							 {"dex", dex}};

	void buffStats(int *stats, string s, int i = 2) {
		if (i <= 0)
			return;

		outputStats(s);
		cin >> s;
		transform(s.begin(), s.end(), s.begin(), ::tolower);

		if (statMap.find(s) == statMap.end()) {
			cout << "Not a valid stat!" << endl;
			buffStats(stats, s, i);
			return;
		}

		*(stats + cha) += 1; // needs to increase by 2 which will happen since
							 // this function gets called twice
		*(stats + statMap[s]) += 1;

		buffStats(stats, s, --i);
	}

	void outputStats(string skip) {
		cout << "[";
		for (int i = 0; i < 5; i++) {
			if (stat[i] == skip)
				continue;

			cout << stat[i];

			if (i == 4) {
				cout << "]: ";
				continue;
			}

			cout << ", ";
		}
	}

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
};

class Halfling : public _race {
public:
	void buffStats(int *stats) {
		*(stats + dex) += 2;
	}

	void setLanguage(vector<string> *languages) {
		allLangs.remove("Halfling");
		languages->push_back("Halfling");
	}

	void setTraits(vector<string> *traits) {
		traits->push_back("Lucky");
		traits->push_back("Brave");
		traits->push_back("Halfling");
		traits->push_back("Nimbleness");
	}

	int getSpeed() {
		return 25;
	}
};

class HalfOrc : public _race {
public:
	void buffStats(int *stats) {
		*(stats + str) += 2;
		*(stats + con) += 1;
	}

	void setLanguage(vector<string> *languages) {
		allLangs.remove("Orc");
		languages->push_back("Orc");
	}

	void setTraits(vector<string> *traits) {
		traits->push_back("Darkvision");
		traits->push_back("Menacing");
		traits->push_back("Relentless Endurance");
		traits->push_back("Savage Attacks");
	}

	int getSpeed() {
		return 30;
	}

	void addSkills(vector<string> *skills) {
		skills->push_back("Intimidation");
	}
};

class Human : public _race {
public:
	void buffStats(int *stats) {
		*(stats + str) += 1;
		*(stats + dex) += 1;
		*(stats + con) += 1;
		*(stats + intel) += 1;
		*(stats + wis) += 1;
		*(stats + cha) += 1;
	}

	void setLanguage(vector<string> *languages) {
	}

	void addLanguage(vector<string> *languages) {
		outputStringList(allLangs);

		string lang;
		cin >> lang;

		if (!listContains(allLangs, lang)) {
			cout << "Not a valid language!" << endl;
			addLanguage(languages);
			return;
		}

		languages->push_back(lang);
		allLangs.remove(lang);
	}

	void setTraits(vector<string> *traits) {
		traits->push_back("Extra Language");
	}

	int getSpeed() {
		return 30;
	}

	void addSkills(vector<string> *skills) {
		list<string> s = {"Acrobatics",
						  "Animal_Handling",
						  "Arcana",
						  "Athletics",
						  "Deception",
						  "History",
						  "Insight",
						  "Intimidation",
						  "Investigation",
						  "Medicine",
						  "Nature",
						  "Perception",
						  "Performance",
						  "Persuasion",
						  "Religion",
						  "Sleight_of_Hand",
						  "Stealth",
						  "Survival"};

		outputStringList(s);

		string skill;
		cin >> skill;

		if (!listContains(s, skill)) {
			cout << "Not a valid skill!" << endl;
			addSkills(skills);
			return;
		}

		skills->push_back(skill);
	}
};

class Tiefling : public _race {
public:
	void buffStats(int *stats) {
		*(stats + cha) += 2;
		*(stats + intel) += 1;
	}

	void setLanguage(vector<string> *languages) {
		allLangs.remove("Infernal");
		languages->push_back("Infernal");
	}

	void setTraits(vector<string> *traits) {
		traits->push_back("Darkvision");
		traits->push_back("Hellish Resistance");
		traits->push_back("Infernal Legacy");
	}

	int getSpeed() {
		return 30;
	}
};

#endif
