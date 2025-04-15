#include <iostream>

using namespace std;

const int SIZE = 10, LAND = 1, WATER = 0;

class world {
public:
	int map[SIZE][SIZE];

	void removeIsland(int x, int y) {
		if (map[x][y] == LAND) {
			map[x][y] = WATER;
			int minX = x >= 1 ? x - 1 : 0;
			int minY = y >= 1 ? y - 1 : 0;
			int maxX = x <= SIZE ? x + 1 : x;
			int maxY = y <= SIZE ? y + 1 : y;
			for (int i = minX; i <= maxX; i++) {
				for (int k = minY; k <= maxY; k++) {
					if (map[i][k] == LAND) removeIsland(i, k);
				}
			}
		}
	}
};








int main() {
	
	int defaultMap[SIZE][SIZE] = {
		{1,0,1,1},
		{0,0,1,1},
		{1,1,0,0,1,1},
		{0,0,0,0},
		{1,0,1,0},
		{0,1,0,1}
	};
	int counter = 0;

	world world1;
	for (int i = 0; i < SIZE; i++) {
		for (int k = 0; k < SIZE; k++) {
			world1.map[i][k] = defaultMap[i][k];
		}
	}

	for (int i = 0; i < SIZE; i++) {
		for (int k = 0; k < SIZE; k++) {
			cout << world1.map[i][k];
		}
		cout << endl;
	}

	for (int i = 0; i < SIZE; i++) {
		for (int k = 0; k < SIZE; k++) {
			if (world1.map[i][k] == 1) {
				counter++;
				world1.removeIsland(i, k);
			}
		}
	}

	cout << endl << "Number of islands: " << counter << endl << endl;

	return 0;
}