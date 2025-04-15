#include <iostream>
#include "header.h"
#include <chrono>
#include <string>
#include <fstream>

using namespace std;

struct point { float x, y; };
struct side {
	point p0, p1, p2, p3;
	float a, b, c;
	int id;
	float veclen;
};
struct vec { float x, y; };
struct square {
	point p1, p2;
	side* sides;
	int n;
	float size;
};
struct Field {
	point p1, p2;
	float size;
	square*** tree;
	int depth;
	int dia;
};
float veclen(vec);
int sign(float num);
side* divide_into_sides(point* vertices, int n);
square init_square(point p1, point p2, side* sides, int n);
void field_chars(point* vertices, point* points, int vert_size, int p_size, point& min, point& max, float& size);
void add_layer(Field& field);
Field init_field(point p1, point p2, side* sides);
float calcDistance(side s, point p);
point distPoint(side s, point p, float dist);
Field init_field(square sqr);
float min(float[4]);
float max(float arr[4]);
float sqrlen(vec v);
void getCells(float radius, point p, point p1, float size, int level, point* cells, int& amount);
bool contains(int* arr, int n, int num);
void sideIndcsFromRadius(float radius, point p, Field field, int level, int* indcs, int& n);
void checkPoint(Field field, point p, float& mindist, point& nPoint);
void sideIndcsRightToPoint(point p, Field field, int* indcs, int& n);
bool isInPolygon(side* sides, int n, point p);
void read_test(ifstream& input, point*& verts, point*& points, int& vert_size, int& p_size) {
	string buffer;

	input >> buffer;
	int n = stoi(buffer);
	vert_size = n;
	verts = new point[n];

	for (int j = 0; j < n; j++) {
		input >> buffer;
		verts[j].x = stof(buffer);
		input >> buffer;
		verts[j].y = stof(buffer);
	}

	input >> buffer;
	int N = stoi(buffer);
	p_size = N;
	points = new point[N];
	for (int j = 0; j < N; j++) {
		input >> buffer;
		points[j].x = stof(buffer);
		input >> buffer;
		points[j].y = stof(buffer);
	}
}
void read_tests(string path, point**& vertices, point**& points, int*& vert_sizes, int*& p_sizes, int& t) {
	ifstream input(path);
	string buffer;

	input >> buffer;
	t = stoi(buffer);

	vertices = new point * [t];
	points = new point * [t];
	vert_sizes = new int[t];
	p_sizes = new int[t];

	for (int i = 0; i < t; i++) {
		read_test(input, vertices[i], points[i], vert_sizes[i], p_sizes[i]);
	}
	input.close();
}

int main() {

	/*string buff;
	cin >> buff;
	int t = stoi(buff);
	
	for (int k = 0; k < t; k++) {
		read_test(vertices[k], points[k], vert_len[k], p_len[k]);
	}//*/

	point** vertices;
	point** points;
	int* vert_len;
	int* p_len;
	int t;
	read_tests("F:\\University\\C++\\iRunner Competition\\big-tests.txt", vertices, points, vert_len, p_len, t);

	auto start = chrono::high_resolution_clock::now();

	for (int k = 0; k < t; k++) {
		side* sides = divide_into_sides(vertices[k], vert_len[k]);
		point min, max;
		float size;
		field_chars(vertices[k], points[k], vert_len[k], p_len[k], min, max, size);
		Field field = init_field(min, max, sides);
		for (int i = 0; i < p_len[k]; i++) {
			float dist;
			point m;
			checkPoint(field, points[k][i], dist, m);
			int* indcs = new int[vert_len[k]];
			int n = 0;
			sideIndcsRightToPoint(points[k][i], field, indcs, n);
			side* sidesToTest = new side[n];
			for (int j = 0; j < n; j++) {
				sidesToTest[j] = sides[indcs[j]];
			}
			isInPolygon(sidesToTest, n, points[k][i]);
			//cout << dist * dist * pow(-1, not /*Paste is in polygon here*/) << " " << m.x << " " << m.y << endl;
		}
		delete[]vertices[k];
		delete[]points[k];
		delete[]sides;
	}
	

	
	auto end = chrono::high_resolution_clock::now();
	auto ans = chrono::duration_cast<chrono::nanoseconds>(end - start);

	printf("Time measured: %.3f seconds.\n", ans.count() * 1e-9);

	return 0;
}

#include "header.h"
#include <iostream>
#include <string>

using namespace std;

Field init_field(point p1, point p2, side* sides) {
	Field field;
	field.p1 = p1;
	field.p2 = p2;
	field.size = p2.x - p1.x;
	field.tree = new square * *[8];
	field.tree[0] = new square * [1];
	square* init_sqr = new square;
	init_sqr->p1 = p1;
	init_sqr->p2 = p2;
	init_sqr->size = field.size;
	init_sqr->sides = sides;
	init_sqr->n = 5;
	field.tree[0][0] = init_sqr;
	field.depth = 0;
	field.dia = 5;

	int dia_roof = 2;
	if (5 > 20) dia_roof = 5 / 10;
	while (pow(2, field.depth) < 5 and field.dia > dia_roof) {
		add_layer(field);
	}
	return field;
}

Field init_field(square sqr) { return init_field(sqr.p1, sqr.p2, sqr.sides); }

void add_layer(Field& field) {
	field.depth += 1;
	int dia = 0;
	field.tree[field.depth] = new square * [pow(2, field.depth)];
	for (int i = 0; i < pow(2, field.depth); i++) {
		field.tree[field.depth][i] = new square[pow(2, field.depth)];
		for (int j = 0; j < pow(2, field.depth); j++) {
			point p1, p2;
			p1 = field.tree[field.depth - 1][(i - i % 2) / 2][(j - j % 2) / 2].p1;
			p2 = field.tree[field.depth - 1][(i - i % 2) / 2][(j - j % 2) / 2].p2;
			float size = field.tree[field.depth - 1][(i - i % 2) / 2][(j - j % 2) / 2].size / 2;
			p1.x += (i % 2) * size;
			p1.y += (j % 2) * size;
			p2.x -= (i % 2 == 0) * size;
			p2.y -= (j % 2 == 0) * size;
			field.tree[field.depth][i][j] = init_square(p1, p2, field.tree[field.depth - 1][(i - i % 2) / 2][(j - j % 2) / 2].sides, field.tree[field.depth - 1][(i - i % 2) / 2][(j - j % 2) / 2].n);
			if (field.tree[field.depth][i][j].n > dia) dia = field.tree[field.depth][i][j].n;
		}
	}
	field.dia = dia;
}

float min(float arr[4]) {
	float min = arr[0];
	for (int i = 1; i < 4; i++) {
		if (arr[i] < min) min = arr[i];
	}
	return min;
}

float max(float arr[4]) {
	float max = arr[0];
	for (int i = 1; i < 4; i++) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

float veclen(vec v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

float sqrlen(vec v) {
	return v.x * v.x + v.y * v.y;
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
		sides[i].a = -sides[i].p2.y + sides[i].p1.y;
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
				else if (((sides[i].p1.x <= p2.x) == (p1.x <= sides[i].p2.x)) and ((sides[i].p1.y <= p2.y) == (p1.y <= sides[i].p2.y))) {
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

void field_chars(point* vertices, point* points, int vert_size, int p_size, point& min, point& max, float& size) {
	float minx = 10000, miny = 10000, maxx = -10000, maxy = -10000;
	for (int i = 0; i < vert_size; i++) {
		if (vertices[i].x < minx) minx = vertices[i].x;
		if (vertices[i].y < miny) miny = vertices[i].y;
		if (vertices[i].x > maxx) maxx = vertices[i].x;
		if (vertices[i].y > maxy) maxy = vertices[i].y;
	}
	for (int i = 0; i < p_size; i++) {
		if (points[i].x < minx) minx = points[i].x;
		if (points[i].y < miny) miny = points[i].y;
		if (points[i].x > maxx) maxx = points[i].x;
		if (points[i].y > maxy) maxy = points[i].y;
	}
	if (maxx - minx > maxy - miny) {
		size = maxx - minx;
		maxy = miny + size;
	}
	else {
		size = maxy - miny;
		maxx = minx + size;
	}
	min.x = minx - size / 10000;
	min.y = miny - size / 10000;
	max.y = maxy + size / 10000;
	max.x = maxx + size / 10000;
	size += 2 * size / 10000;
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

void getCells(float radius, point p, point p1, float size, int level, point* cells, int& amount) {
	float prev_a = 1, prev_b = 0, cellsize = size / pow(2, level), a, b;
	int phase = 0, loops = 0; amount = 0;
	float angle_45 = sqrt(2) / 2;
	float eps = 1;
	while (!loops) {
		if (abs(prev_a) >= angle_45) {
			if (prev_a > 0) {
				if (phase != 0 and prev_b >= 0) {
					phase = 0; loops += 1; break;
				}
				b = cellsize / radius * eps + prev_b;
				if (b > 1) b = 1;
				a = sqrt(1 - b * b);
			}
			else {
				b = prev_b - cellsize / radius * eps;
				if (b < -1) b = -1;
				a = -sqrt(1 - b * b);
				phase = 2;
			}
		}
		else {
			if (prev_b > 0) {
				a = prev_a - cellsize / radius * eps;
				if (a < -1) a = -1;
				b = sqrt(1 - a * a);
				phase = 1;
			}
			else {
				a = cellsize / radius * eps + prev_a;
				if (a > 1) a = 1;
				b = -sqrt(1 - a * a);
				phase = 3;
			}
		}
		prev_a = a;
		prev_b = b;
		point pi = { p.x + a * radius, p.y + b * radius };
		point cell = { floor(((pi.x - p1.x) * pow(2, level) / size)), floor((pi.y - p1.y) * pow(2, level) / size) };
		if (cell.x >= 0 and cell.y >= 0 and cell.x < pow(2, level) and cell.y < pow(2, level)) cells[amount++] = cell;
	}
}

bool contains(int* arr, int n, int num) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == num) return true;
	}
	return false;
}

void sideIndcsFromRadius(float radius, point p, Field field, int level, int* indcs, int& n) {
	float size = field.size;
	point p1 = field.p1;
	if (radius <= 2 * size / pow(2, level)) {
		point cell = { (int)((p.x - p1.x) * pow(2, level) / size), (int)((p.y - p1.y) * pow(2, level) / size) };
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (cell.x + i >= 0 and cell.x + i < pow(2, level) and cell.y + j >= 0 and cell.y + j < pow(2, level)) {
					for (int k = 0; k < field.tree[level][(int)(cell.x + i)][(int)(cell.y + j)].n; k++) {
						if (not contains(indcs, n, field.tree[level][(int)(cell.x + i)][(int)(cell.y + j)].sides[k].id)) {
							indcs[n++] = field.tree[level][(int)(cell.x + i)][(int)(cell.y + j)].sides[k].id;
						}
					}
				}
			}
		}
	}
	else if (radius <= 3 * size / pow(2, level)) {
		point cell = { (int)((p.x - p1.x) * pow(2, level) / size), (int)((p.y - p1.y) * pow(2, level) / size) };
		for (int i = -2; i < 3; i++) {
			for (int j = -2; j < 3; j++) {
				if (cell.x + i >= 0 and cell.x + i < pow(2, level) and cell.y + j >= 0 and cell.y + j < pow(2, level)) {
					for (int k = 0; k < field.tree[level][(int)(cell.x + i)][(int)(cell.y + j)].n; k++) {
						if (not contains(indcs, n, field.tree[level][(int)(cell.x + i)][(int)(cell.y + j)].sides[k].id)) {
							indcs[n++] = field.tree[level][(int)(cell.x + i)][(int)(cell.y + j)].sides[k].id;
						}
					}
				}
			}
		}
	}
	else {
		int amount = (int)(pow(2, field.depth) * 3.141592);
		point* cells = new point[amount];
		getCells(radius, p, p1, field.size, level, cells, amount);
		for (int i = 0; i < amount; i++) {
			for (int k = 0; k < field.tree[level][(int)(cells[i].x)][(int)(cells[i].y)].n; k++) {
				if (not contains(indcs, n, field.tree[level][(int)(cells[i].x)][(int)(cells[i].y)].sides[k].id)) {
					indcs[n++] = field.tree[level][(int)(cells[i].x)][(int)(cells[i].y)].sides[k].id;
				}
			}
		}

		delete[]cells;
	}
}

void checkPoint(Field field, point p, float& mindist, point& nPoint) {
	int depth = 0, i = 0, j = 0;
	int n = field.tree[0][0][0].n;
	int* indcs = new int[n];
	n = 0;
	while (field.tree[depth][i][j].n > 0 and depth < field.depth) {
		depth += 1;
		i = (int)((p.x - field.p1.x) * pow(2, depth) / field.size);
		j = (int)((p.y - field.p1.y) * pow(2, depth) / field.size);
	}

	if (field.tree[depth][i][j].n > 0) {
		sideIndcsFromRadius(field.size / pow(2, depth), p, field, depth, indcs, n);
		for (int k = 0; k < field.tree[depth][i][j].n; k++) {
			if (not contains(indcs, n, field.tree[depth][i][j].sides[k].id))
				indcs[n++] = field.tree[depth][i][j].sides[k].id;
		}
	}
	else {
		float cellsize = field.size / pow(2, depth);
		float dists[4] = {
			fmod(p.x - field.p1.x, cellsize),
			fmod(p.y - field.p1.y, cellsize),
			cellsize - fmod(p.x - field.p1.x, cellsize),
			cellsize - fmod(p.y - field.p1.y, cellsize)
		};
		float radius = min(dists);
		while (n == 0) {
			radius += cellsize / 2;
			sideIndcsFromRadius(radius, p, field, depth, indcs, n);
		}
		sideIndcsFromRadius(radius + max(dists), p, field, depth, indcs, n);
		radius -= cellsize / 2 - min(dists);

		while (n > field.dia + 1 and depth < field.depth) {
			depth += 1;
			cellsize = field.size / pow(2, depth);
			n = 0;
			while (n == 0) {
				radius += cellsize / 2;
				sideIndcsFromRadius(radius, p, field, depth, indcs, n);
			}
			sideIndcsFromRadius(radius + max(dists), p, field, depth, indcs, n);
			radius -= cellsize / 2;
		}
	}

	mindist = 1e10;

	for (int i = 0; i < n; i++) {
		side s = field.tree[0][0][0].sides[indcs[i]];
		float dist = calcDistance(s, p);
		point m = distPoint(s, p, dist);
		if (((s.p1.x <= m.x) != (m.x <= s.p2.x)) or ((s.p1.y <= m.y) != (m.y <= s.p2.y))) {
			if (sqrlen({ s.p1.x - p.x, s.p1.y - p.y }) > sqrlen({ s.p2.x - p.x, s.p2.y - p.y })) {
				dist = veclen({ s.p2.x - p.x, s.p2.y - p.y });
				m = s.p2;
			}
			else {
				dist = veclen({ s.p1.x - p.x, s.p1.y - p.y });
				m = s.p1;
			}
		}
		if (dist < mindist) {
			mindist = dist;
			nPoint = m;
		}
	}
}

void sideIndcsRightToPoint(point p, Field field, int* indcs, int& n) {

	point cell = { (int)((p.x - field.p1.x) * pow(2, field.depth) / field.size),
				  (int)((p.y - field.p1.y) * pow(2, field.depth) / field.size) };

	while (cell.x < pow(2, field.depth)) {
		for (int i = 0; i < field.tree[field.depth][(int)cell.x][(int)cell.y].n; i++) {
			if (not contains(indcs, n, field.tree[field.depth][(int)cell.x][(int)cell.y].sides[i].id)) {
				indcs[n++] = field.tree[field.depth][(int)cell.x][(int)cell.y].sides[i].id;
			}
		}
		cell.x += 1;
	}
}

bool isInPolygon(side* sides, int n, point p) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		side s = sides[i];
		if (s.a == 0) {
			if (s.c + s.b * p.y == 0) {
				if ((s.p0.y > p.y) != (s.p3.y > p.y) and s.p3.x > p.x) {
					count += 1;
				}
			}
		}
		else {
			float xi = (-s.c - s.b * p.y) / s.a;
			if (xi > p.x and xi == s.p1.x and p.y == s.p1.y) {
				if ((s.p0.y > p.y) != (s.p2.y > p.y) and s.p0.y != p.y and s.p2.y != p.y) {
					count += 1;
				}
			}
			else if (xi > p.x and (s.p2.y > p.y) == (s.p1.y < p.y) and s.p2.y != p.y and s.p1.y != p.y) {
				count += 1;
			}
		}
	}
	return not (count % 2 == 0);
}