#include <iostream>
#include "squares.h"

using namespace std;

struct Field {
	point p1, p2;
	float size;
	square*** tree;
	int depth;
	int dia;
};

void add_layer(Field& field) {
	field.depth += 1;
	int dia = 0;
	field.tree[field.depth] = new square* [pow(2, field.depth)];
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
Field init_field(point p1, point p2, side* sides) {
	Field field;
	field.p1 = p1;
	field.p2 = p2;
	field.size = p2.x - p1.x;
	field.tree = new square** [8];
	field.tree[0] = new square*[1];
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

int main() {

	point* vertices = new point[5];
	vertices[0] = { 0,0 };
	vertices[1] = { 1,0 };
	vertices[2] = { 4,6 };
	vertices[3] = { -2,7 };
	vertices[4] = { -3,8 };

	point* points = new point[5];
	points[0] = { 1,1 };
	points[1] = { 3,2 };
	points[2] = { 7,-2 };
	points[3] = { -4,4 };
	points[4] = { 0,6 };

	side* sides = divide_into_sides(vertices, 5);

	point min, max;
	float size;
	field_chars(vertices, points, 5, 5, min, max, size);
	Field field = init_field(min, max, sides);

	cout << "Layers: " << field.depth << endl;
	cout << "Diameter: " << field.dia << endl << endl;

	for (int i = 0; i < field.depth; i++) {
		for (int j = 0; j < pow(2, i); j++) {
			for (int k = 0; k < pow(2, i); k++) {
				square sqr = field.tree[i][j][k];
				cout << "x: " << sqr.p1.x << " y: " << sqr.p1.y << endl;
				cout << "x: " << sqr.p2.x << " y: " << sqr.p2.y << endl;
				cout << "size: " << sqr.size << endl;
				cout << "n: " << sqr.n << endl;
				for (int i = 0; i < sqr.n; i++) {
					cout << i << ": (" << sqr.sides[i].p1.x << ", " << sqr.sides[i].p1.y << "), (" << sqr.sides[i].p2.x << ", " << sqr.sides[i].p2.y << ")" << endl;
				}
			}
			cout << endl;
		}
		cout << endl << "------" << endl << endl;
	}

	return 0;
}