#include <iostream>
#include <chrono>

using namespace std;

struct side {
	float c;
	float nor[2];
	float veclen;
};

float veclen(float cords[2]) {
	return sqrt(cords[0] * cords[0] + cords[1] * cords[1]);
}

float calcDist(side side, float point[2]) {
	return abs(side.c + side.nor[0] * point[0] + side.nor[1] * point[1]) / side.veclen;
}

float* distPoint(side side, float point[2], float dist) {
	float arr[2] = {
		point[0] - dist * side.nor[0] * (side.c + side.nor[0] * point[0] + side.nor[1] * point[1]) / (side.veclen * abs(side.c + side.nor[0] * point[0] + side.nor[1] * point[1])),
		point[1] - dist * side.nor[1] * (side.c + side.nor[0] * point[0] + side.nor[1] * point[1]) / (side.veclen * abs(side.c + side.nor[0] * point[0] + side.nor[1] * point[1]))
	};
	return arr;
}

int main() {

	side sides[200];
	for (int i = 0; i < 200; i++) {
		sides[i].c = rand() - RAND_MAX / 2;
		sides[i].nor[0] = rand() - RAND_MAX / 2;
		sides[i].nor[1] = rand() - RAND_MAX / 2;
		sides[i].veclen = veclen(sides[i].nor);
	}
	float* res;
	float dist = 0.0;
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 900*500; i++) {
		float arr[2] = {rand(), rand()};
		int ind = rand() % 200;
		dist = calcDist(sides[ind], arr);
		res = distPoint(sides[ind], arr, dist);
	}
	auto end = chrono::high_resolution_clock::now();
	auto ans = chrono::duration_cast<chrono::nanoseconds>(end - start);

	printf("Time measured: %.3f seconds.\n", ans.count() * 1e-9);

	return 0;
}