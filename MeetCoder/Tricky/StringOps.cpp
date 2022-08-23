#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> getSubString(string str, int len) {
	vector<string> subs;
	int strLen = str.length();

	if (strLen == len) {
		subs.push_back(str);
		return subs;
	} else if (strLen < len) {
		return subs;
	}
	for (int i = 0; i <= strLen - len; i++) {
		string sub = str.substr(i, len);
		//cout << sub << endl;
		subs.push_back(sub);
	}
	return subs;
}

int main() {
	auto subs = getSubString("members", 3);
	string str = "chambers";

	for (auto sub : subs) {
		cout << sub << endl;
		//cout << str.compare(sub) << endl; -1 or 1
		cout << str.find(sub) << endl; // match position or npos
		//cout << str.contains(sub);
	}
}