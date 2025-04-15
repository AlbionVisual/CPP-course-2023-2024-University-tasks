#include <iostream>

using namespace std;

struct vec {
	float x, y;
};
struct point { float x, y; };
struct side {
	point p0, p1, p2, p3;
	float a, b, c;
	int id;
	float veclen;
};

int sign(float num) {
	if (num > 0) return 1;
	else if (num < 0) return -1;
	else return 0;
}

float veclen(vec v) {
	return sqrt(v.x * v.x + v.y * v.y);
}
float sqrlen(vec v) {
	return v.x * v.x + v.y * v.y;
}

float calcDistance(side s, point p) {
	return abs(s.a * p.x + s.b * p.y + s.c) / s.veclen;
}

point distPoint(side s, point p, float dist) {
	point m;
	m.x = p.x - sign(s.c + s.a * p.x + s.b * p.y) * dist * s.a / s.veclen;
	m.y = p.y - sign(s.c + s.a * p.x + s.b * p.y) * dist * s.b / s.veclen;
	return m;
}


int main() {

	for (int i = 0; i < 10; i++) {
		vec v;
		v.x = rand() - RAND_MAX / 2;
		v.y = rand() - RAND_MAX / 2;
		cout << v.x << ", " << v.y << ": " << veclen(v) << ", " << sqrlen(v) << endl;
	}

	return 0;
}