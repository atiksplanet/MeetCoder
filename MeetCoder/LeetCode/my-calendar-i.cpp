#include <iostream>
#include <vector>

using namespace std;

class MyCalendar {
	struct Book {
		int start, end;
		Book(int s, int e) {
			start = s;
			end = e;
		}
	};
public:
	vector<Book> booking;

	MyCalendar() {
		booking.clear();
	}

	bool book(int start, int end) {
		bool result = true;
		
		return result;
	}

	bool obook(int start, int end) {
		bool result = true;
		for (auto x : booking) {
			if ((start < x.start && end <= x.start) || (start >= x.end && end > x.end)) {

			}
			else {
				result = false;
				break;
			}
		}
		if (result) {
			booking.push_back(Book(start, end));
		}
		return result;
	}
};

int main1() {
	MyCalendar* obj = new MyCalendar();
	int start = 10;
	int end = 20;
	bool param_1 = obj->book(start, end);
	cout << param_1 << endl;

	start = 9;
	end = 10;
	param_1 = obj->book(start, end);
	cout << param_1 << endl;

	start = 20;
	end = 70;
	param_1 = obj->book(start, end);
	cout << param_1 << endl;

	return 0;
}

#include <unordered_map>

class Solution {
	unordered_map<char, pair<int, int>> cmap;
public:
	int firstUniqChar(string s) {
		int index = 0;
		for (auto x : s) {
			auto fi = cmap.find(x);
			if (fi == cmap.end()) {
				cmap.insert({ x, make_pair(1, index) });
			}
			else {
				fi->second.first++;
			}
			index++;
		}
		auto se = make_pair(0, 100001);
		for (auto m : cmap) {
			if (m.second.first == 1 && m.second.second < se.second) {
				se = m.second;
				if (se.second == 0) break;
			}
		}
		return se.second == 100001 ? -1 : se.second;
	}
};

int main() {
	cout << Solution().firstUniqChar("isratjahanmim") << endl;
	cout << Solution().firstUniqChar("leetcode") << endl;
	cout << Solution().firstUniqChar("loveleetcode") << endl;
	cout << Solution().firstUniqChar("aabb") << endl;
	return 0;
}