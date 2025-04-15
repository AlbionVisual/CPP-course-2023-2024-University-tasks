#include <iostream>
#include "field.h"

using namespace std;

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
		point pi = {p.x + a * radius, p.y + b * radius};
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
	//n = 0;
	float size = field.size;
	point p1 = field.p1;
	if (radius <= 2 * size / pow(2, level)) {
		point cell = {(int)((p.x - p1.x) * pow(2, level) / size), (int)((p.y - p1.y) * pow(2, level) / size)};
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
		for (int i = 0; i < field.tree[depth][i][j].n; i++) {
			if (not contains(indcs, n, field.tree[depth][i][j].sides[i].id))
				indcs[n++] = field.tree[depth][i][j].sides[i].id;
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

	while (cell.x < pow(2, field.depth)){
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
			if (s.c + s.a * p.x + s.b * p.y == 0) {
				if ((s.p0.y > p.y) != (s.p3.y > p.y) and s.p3.x > p.x) {
					count += 1;
				}
			}
		}
		else {
			float xi = (-s.c - s.b * p.y) / s.a;
			/*if (s.id == n - 1 and xi > p.x and xi == s.p2.x and p.y == s.p2.y) {
				if ((s.p1.y > p.y) != (s.p3.y > p.y) and s.p1.y != p.y and s.p3.y != p.y) {
					count += 1;
				}
			}
			else*/ if (xi > p.x and xi == s.p1.x and p.y == s.p1.y) {
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

	for (int i = 0; i < 5; i++) {
		float dist;
		point m;
		checkPoint(field, points[i], dist, m);
		int* indcs = new int[5];
		int n = 0;
		sideIndcsRightToPoint(points[i], field, indcs, n);
		side* sidesToTest = new side[n];
		for (int j = 0; j < n; j++) {
			sidesToTest[j] = sides[indcs[j]];
		}
		cout << i << ": " << dist * pow(-1, not isInPolygon(sidesToTest, n, points[i])) << ", (" << m.x << ", " << m.y << ")\n";
	}

	return 0;
}