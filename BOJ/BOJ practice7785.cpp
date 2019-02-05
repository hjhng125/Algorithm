#include <iostream>
#include <map>
#include <string>

using namespace std;

int n;
map<string, string, greater<string> > person;

int main(int argc, const char * argv[]) {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string name, el;
		cin >> name >> el;
		if (!el.compare("enter"))
			person.insert(make_pair(name, el));
		else
			person.erase(name);
	}
	for (auto it = person.begin(); it != person.end(); ++it)
		cout << it->first << '\n';

	return 0;
}
