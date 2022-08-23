#include <iostream>
#include <time.h>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Node {
	int row, col, energy;
	Node(int ro, int co, int va) {
		row = ro;
		col = co;
		energy = va;
	}
	/*
	bool operator <(const Node &l) const {
		return this->v < l.v;
	}*/
};

// Max energy, low row, low col
struct Max2Min {
	bool operator() (Node &left, Node &right) {
		if (left.energy == right.energy) {
			if (left.row == right.row) {
				return left.col > right.col;
			}
			else {
				return left.row > right.row;
			}
		}
		else {
			return left.energy < right.energy;
		}
	}
};

int main() {
	priority_queue<Node, vector<Node>, Max2Min> pq;
	pq.push(Node(0, 0, 0));
	pq.push(Node(0, 1, 5));
	pq.push(Node(1, 0, 3));
	pq.push(Node(0, 5, 9));
	pq.push(Node(1, 1, 90));
	
	printf("Top: [%d, %d](%d)\n", pq.top().row, pq.top().col, pq.top().energy);
	return 0;
}