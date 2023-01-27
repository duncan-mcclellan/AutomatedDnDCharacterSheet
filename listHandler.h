#ifndef LIST_HANDLER_H_INCLUDED
#define LIST_HANDLER_H_INCLUDED

void outputStringList(list<string> s) {
	cout << "[";
	for (auto iter = s.cbegin(); iter != s.cend(); ++iter) {
		cout << *iter;
		if (iter != s.cend())
			cout << ", ";
	}
	cout << "]:" << endl;
}

bool listContains(list<string> l, string s) {
	for (auto iter = l.cbegin(); iter != l.cend(); ++iter)
		if (*iter == s)
			return true;

	return false;
}

#endif