#include "field.h"
#include <iostream>

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