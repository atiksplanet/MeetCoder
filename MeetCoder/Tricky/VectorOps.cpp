#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	vector<string> names;
	//names[0] = "Atik";
	names.push_back("Gazi");
	names[0] = "Atik";
	

	for (auto n : names) {
		cout << n << endl;
	}
}