#include <iostream>
#include <time.h>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define maxN 100
#define targetN 30

class Solution {
private:
	struct Node {
		int row, col, val;
		Node(int r, int c, int v) {
			row = r;
			col = c;
			val = v;
		}
	};
	int grid2d[maxN][maxN];
	unordered_map<int, unordered_map<int, bool>> isVisited;

public:

	void init2DGrid() {
		srand(time(0));
		for (int i = 0; i < targetN; i++) {
			for (int j = 0; j < targetN; j++) {
				int r = rand() % 2;
				//cout << r << " ";
				grid2d[i][j] = r;
			}
			//cout << endl;
		}
		//cout << endl;
	}

	void printer(int grid2d[maxN][maxN]) {
		cout << "-----------Data in 2d-----------\n";
		for (int i = 0; i < targetN; i++) {
			for (int j = 0; j < targetN; j++) {
				if (grid2d[i][j] == 0) {
					cout << "X" << " ";
				}
				else if(grid2d[i][j] == 4) {
					cout << " " << " ";
				}
				else {
					cout << "+" << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}

	struct SetHasher {
		size_t operator()(const Node &node) const {
			int hashV = node.row * targetN + node.col;
			printf("[%d, %d] = %d\n", node.row, node.col, hashV);
			return hashV;
		}
	};

	struct SetEquality {
		bool operator()(const Node &lhs, const Node &rhs) const {
			return lhs.val == rhs.val && lhs.row == rhs.row && lhs.col == rhs.col;
		}
	};


	void setTest() {
		unordered_set<Node, SetHasher, SetEquality> isVisited;
		auto ii = isVisited.insert(Node(5, 0, 0));
		cout << ii.second << endl;
		ii = isVisited.insert(Node(0, 0, 1));
		cout << ii.second << endl;
		ii = isVisited.insert(Node(0, 9, 2));
		cout << ii.second << endl;
		ii = isVisited.insert(Node(9, 0, 2));
		cout << ii.second << endl;

		ii = isVisited.insert(Node(9, 9, 2));
		cout << ii.second << endl;
		ii = isVisited.insert(Node(2, 8, 2));
		cout << ii.second << endl;
		ii = isVisited.insert(Node(7, 6, 2));
		cout << ii.second << endl;
	}

	void mapTest() {
		unordered_map<int, unordered_map<int, bool>> map2d;// take huge time when data is heavy
		map2d[0][3] = true;
		cout << map2d[0][3] << endl;
		cout << map2d[3][3] << endl;
		if (map2d[6][3] == false) {

		}
		cout << map2d[6][4] << endl;
		cout << map2d[6][5] << endl;

		int r = 0;
		int c = 3;

		auto rsi = map2d.find(r);
		if (rsi == map2d.end()) {
			cout << "Row Not exist\n";
		}
		else {
			auto csi = rsi->second.find(c);
			if (csi == rsi->second.end()) {
				cout << "Col Not exist\n";
			}
			else {
				cout << "Exist\n";
			}
		}
	}

	bool isReallyVisited(int r, int c) {
		return isVisited[r][c];
	}

	void makeVisited(int r, int c) {
		isVisited[r][c] = true;
		grid2d[r][c] = 4;
	}

	void searchTest() {
		init2DGrid();
		printer(grid2d);

		// For BFS
		queue<Node> qu;
		isVisited.clear();

		int rx[4] = { 0, 1, -1, 0 }; // [R, D, U, L]
		int ry[4] = { 1, 0, 0, -1 };

		int row = 13;
		int col = 15;
		//printf("Starting from (%d)[%d, %d]\n", grid2d[row][col], row, col);
		qu.push(Node(row, col, grid2d[row][col]));
		// Mark this node visited
		makeVisited(row, col);

		while (!qu.empty()) {
			auto front = qu.front();
			qu.pop();
			//printf("Popped (%d)[%d, %d]\n", back.val, back.row, back.col);
			for (int a = 0; a < 4; a++) {
				int adjX = front.row + rx[a];
				int adjY = front.col + ry[a];

				if (adjX >= 0 && adjX < targetN && adjY >= 0 && adjY < targetN) {
					auto val = grid2d[adjX][adjY];
					if (val == 1 && !isReallyVisited(adjX, adjY)) { // check is not visited
						//printf("Adding (%d)[%d, %d]\n", val, adjX, adjY);
						qu.push(Node(adjX, adjY, val));
						// Mark node visited
						makeVisited(adjX, adjY);
					}
					else {
						//printf("Blocked (%d)[%d, %d]\n", val, adjX, adjY);
					}
				}
				else {
					//printf("Index out of bound[%d, %d]\n", adjX, adjY);
				}
			}
		}
		printer(grid2d);
	}
};

int main() {
	Solution sl;
	sl.searchTest();
	//sl.setTest();
	//sl.mapTest();
	return 0;
}