#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

struct Node {
	Node *child[26];
	bool isWord;
	int counter;

	void init() {
		counter = 0;
		isWord = false;
		for (int i = 0; i < 26; i++) {
			child[i] = nullptr;
		}
	}
};

Node nodes[999999];
int hasher = 0;

Node *newNode() {
	Node *node = &nodes[hasher++];
	node->init();
	return node;
}

class Trie {
	Node *head;
public:
	Trie() {
		hasher = 0;
		head = newNode();
	}

	void insert(string word) {
		Node *run = head;
		for (char c : word) {
			int index = c - 'a';
			if (run->child[index] == nullptr) {
				run->child[index] = newNode();
			}
			run = run->child[index];
			run->counter++;
		}
		run->isWord = true;
	}

	bool search(string word) {
		Node *run = head;
		for (char c : word) {
			int index = c - 'a';
			if (run->child[index] == nullptr) {
				return false;
			}
			run = run->child[index];
		}
		return run->isWord;
	}

	bool startsWith(string prefix) {
		Node *run = head;
		for (char c : prefix) {
			int index = c - 'a';
			if (run->child[index] == nullptr) {
				return false;
			}
			run = run->child[index];
		}
		return true;
	}
};

class WordDictionary {
	Node *head;
public:
	WordDictionary() {
		hasher = 0;
		head = newNode();
	}

	void addWord(string word) {
		Node *run = head;
		for (char c : word) {
			int index = c - 'a';
			if (run->child[index] == nullptr) {
				run->child[index] = newNode();
			}
			run = run->child[index];
			run->counter++;
		}
		run->isWord = true;
	}

	bool doSearch(string word) {
		Node *run = head;
		for (char c : word) {
			int index = c - 'a';
			if (run->child[index] == nullptr) {
				return false;
			}
			run = run->child[index];
		}
		return run->isWord;
	}

	bool search(string word) {
		if (word.find(".") != word.npos) {
			cout << "have .\n";
			return 0;
		} 
		else {
			return doSearch(word);
		}
	}

	void test() {
		addWord("bad");
		addWord("dad");
		addWord("mad");

		cout << search("pad") << endl;
		cout << search("bad") << endl;
		cout << search(".ad") << endl;
		cout << search("b..") << endl;
	}
};

int main() {
	WordDictionary().test();
	return 0;
}