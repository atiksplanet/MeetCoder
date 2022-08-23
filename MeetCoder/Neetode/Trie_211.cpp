// https://leetcode.com/problems/design-add-and-search-words-data-structure/

#include <iostream>

using namespace std;

struct Node {
	bool isEnd;
	Node *child[26];
	Node() {}
	void init() {
		isEnd = false;
		for (int i = 0; i < 26; i++) {
			child[i] = NULL;
		}
	}
};

Node nodes[250000];
int hasher;

Node *newNode() {
	auto n = &nodes[hasher++];
	n->init();
	return n;
}

class WordDictionary {
	Node *root;

	bool doSearch(Node *node, string &word, int wordIndex) {
		if (node == NULL) return false;
		if (word.length() == wordIndex) {
			return node->isEnd;
		}
		if (word[wordIndex] != '.') {
			int index = word[wordIndex] - 'a';
			return doSearch(node->child[index], word, wordIndex + 1);
		}
		for (int i = 0; i < 26; i++) {
			if (doSearch(node->child[i], word, wordIndex + 1)) {
				return true;
			}
		}
		return false;
	}
public:
	WordDictionary() {
		hasher = 0;
		root = newNode();
	}

	void addWord(string word) {
		auto run = root;
		for (auto x : word) {
			int index = x - 'a';
			if (run->child[index] == NULL) {
				run->child[index] = newNode();
			}
			run = run->child[index];
		}
		run->isEnd = true;
	}

	bool search(string word) {
		auto run = root;

		return doSearch(run, word, 0);
	}

	void test() {
		addWord("bad");
		addWord("dad");
		addWord("mad");

		cout << search("pad") << endl;
		cout << search("bad") << endl;
		cout << search(".ad") << endl;
		cout << search("b..") << endl;

		auto t = sizeof(nodes) / (1024 * 1024);
		cout << t << endl;
	}
};

int main() {
	WordDictionary *obj = new WordDictionary();
	obj->test();
}