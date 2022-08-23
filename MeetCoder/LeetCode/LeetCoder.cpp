#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
	void test1() {
		vector<int> nums = { 3, 3 };
		auto result = twoSum(nums, 6);
		for (auto v : result) {
			cout << v << ", ";
		}
		cout << endl;
	}
	
	unordered_multimap<int, int> index;

	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			//cout << nums.at(i) << ", ";
			auto it = index.insert({ nums.at(i),i });
			//cout << it.second << endl;
		}
		for (auto value_index : index) {
			int t = target - (value_index.first);
			auto f = index.find(t);
			
			if (f != index.end() && value_index.second != f->second) {
				result.push_back(value_index.second);
				result.push_back(f->second);
				break;
			}
		}
		return result;
	}
};

class Solution1338 {
public:
	void test() {
		//vector<int> arr = { 9, 77, 63, 22, 92, 9, 14, 54, 8, 38, 18, 19, 38, 68, 58, 19 };
		//vector<int> arr = { 9, 9, 9, 9 };
		vector<int> arr = { 3,3,3,3,5,5,5,2,2,7 };
		cout << minSetSize(arr) << endl;
	}

	int minSetSize(vector<int>& arr) {
		unordered_map<int, int> smap;
		for (auto a : arr) {
			smap[a]++;
		}
		priority_queue<int> pq;
		for (auto p : smap) {
			pq.push(p.second);
		}
		
		int removeCounter = 0;
		int counter = 0;
		while (!pq.empty()) {
			counter++;
			removeCounter += pq.top();
			if (removeCounter >= (arr.size() / 2)) {
				break;
			}
			pq.pop();
		}
		return counter;
	}
};

struct Node {
	unordered_map<char, Node*> child;
	bool isWord;

	void init() {
		isWord = false;
		child.clear();
	}
};

Node nodes[99];

class Trie {
	Node *head;
	int hasher = 0;
public:
	Node *newNode() {
		Node *node = &nodes[hasher++];
		node->init();
		return node;
	}

	Trie() {
		head = newNode();
	}

	void insert(string word) {
		Node *run = head;
		for (char c : word) {
			if (run->child.find(c) == run->child.end()) {
				run->child[c] = newNode();
			}
			run = run->child[c];
		}
		run->isWord = true;
	}

	bool search(string word) {
		Node *run = head;
		for (char c : word) {
			if (run->child.find(c) == run->child.end()) {
				return false;
			}
			run = run->child[c];
		}
		return run->isWord;
	}

	bool startsWith(string prefix) {
		Node *run = head;
		for (char c : prefix) {
			if (run->child.find(c) == run->child.end()) {
				return false;
			}
			run = run->child[c];
		}
		return true;
	}

	void test() {
		insert("atik");
		insert("atikul");
		insert("gazi");
		insert("md");

		cout << search("atikul") << endl;

		cout << startsWith("zati") << endl;
		cout << startsWith("atik") << endl;
		cout << startsWith("atiku") << endl;
		cout << startsWith("atikuls") << endl;
	}
};

int main() {
	Trie().test();

	return 0;
}