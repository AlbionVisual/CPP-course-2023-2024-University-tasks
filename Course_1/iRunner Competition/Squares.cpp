#include <iostream>

using namespace std;

struct point { float x, y; };

struct side {
	point p0, p1, p2, p3;
	float a, b, c;
	int id;
	float veclen;
};

struct vec { float x, y; };

struct square{
	point p1, p2;
	side* sides;
	int n;
	float size;
};

float veclen(vec v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

int sign(float num) {
	if (num > 0) return 1;
	else if (num < 0) return -1;
	else return 0;
}

side* divide_into_sides(point* vertices, int n) {
	side* sides = new side[n];
	for (int i = 0; i < n; i++) {
		sides[i].p1 = vertices[i];
		if (i < n - 1) sides[i].p2 = vertices[i + 1];
		else sides[i].p2 = vertices[0];
		sides[i].id = i;
		sides[i].a = - sides[i].p2.y + sides[i].p1.y;
		sides[i].b = sides[i].p2.x - sides[i].p1.x;
		sides[i].veclen = veclen({ sides[i].a, sides[i].b });
		sides[i].c = -sides[i].a * sides[i].p1.x - sides[i].b * sides[i].p1.y;
		if (i > 0) sides[i].p0 = vertices[i - 1];
		else sides[i].p0 = vertices[n - 1];
		if (i < n - 2) sides[i].p3 = vertices[i + 2];
		else if (i < n - 1) sides[i].p3 = vertices[i + 1];
		else sides[i].p3 = vertices[1];
	}
	return sides;
}

square init_square(point p1, point p2, side* sides, int n) {
	square sqr;
	sqr.p1 = p1;
	sqr.p2 = p2;
	sqr.size = p2.x - p1.x;
	if (n > 0) {
		int sign1, sign2, sign3, sign4;
		int amount = 0;
		int* side_indcs = new int[n];
		for (int i = 0; i < n; i++) {

			sign1 = sign(sides[i].c + sides[i].a * p1.x + sides[i].b * p1.y);
			sign2 = sign(sides[i].c + sides[i].a * p1.x + sides[i].b * p2.y);
			sign3 = sign(sides[i].c + sides[i].a * p2.x + sides[i].b * p2.y);
			sign4 = sign(sides[i].c + sides[i].a * p2.x + sides[i].b * p1.y);

			if (sign1 != sign2 or sign1 != sign4 or sign3 != sign4 or sign2 != sign3) {
				if (((p1.x <= sides[i].p1.x) == (sides[i].p1.x <= p2.x)) and ((p1.y <= sides[i].p1.y) == (sides[i].p1.y <= p2.y))) {
					side_indcs[amount++] = i;
				}
				else if (((p1.x <= sides[i].p2.x) == (sides[i].p2.x <= p2.x)) and ((p1.y <= sides[i].p2.y) == (sides[i].p2.y <= p2.y))) {
					side_indcs[amount++] = i;
				}
			}
		}

		sqr.n = amount;
		if (amount != 0) {
			sqr.sides = new side[amount];
			for (int i = 0; i < amount; i++) {
				sqr.sides[i] = sides[side_indcs[i]];
			}
		}
		delete[]side_indcs;
	}
	else { sqr.n = 0; }
	return sqr;
}

int main() {

	point* vertices = new point[5];
	vertices[0] = { 0,0 };
	vertices[1] = { 1,0 };
	vertices[2] = { 3,4 };
	vertices[3] = { -4,7 };
	vertices[4] = { -3,8 };

	side* sides = divide_into_sides(vertices, 5);
	
	square sqr = init_square(point{0, 0}, point{5, 5}, sides, 5);

	cout << "x: " << sqr.p1.x << " y: " << sqr.p1.y << endl;
	cout << "x: " << sqr.p2.x << " y: " << sqr.p2.y << endl;
	cout << "size: " << sqr.size << endl;
	cout << "n: " << sqr.n << endl;
	for (int i = 0; i < sqr.n; i++) {
		cout << i << ": (" << sqr.sides[i].p1.x << ", " << sqr.sides[i].p1.y << "), (" << sqr.sides[i].p2.x << ", " << sqr.sides[i].p2.y << ")" << endl;
	}

	return 0;
}