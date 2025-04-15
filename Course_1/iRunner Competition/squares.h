#pragma once

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
float veclen(vec);
int sign(float num);
side* divide_into_sides(point* vertices, int n);
square init_square(point p1, point p2, side* sides, int n);
void field_chars(point* vertices, point* points, int vert_size, int p_size, point& min, point& max, float& size);