#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct point {
	float x, y;
};
struct vec {
	float x, y;
};
struct side {
	point p0, p1, p2, p3;
	float a, b, c;
	int id;
	float veclen;
};

float veclen(vec v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

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

side* divide_into_sides(point* vertices, int n) {
	side* sides = new side[n];
	for (int i = 0; i < n; i++) {
		sides[i].p1 = vertices[i];
		if (i < n - 1) sides[i].p2 = vertices[i + 1];
		else sides[i].p2 = vertices[0];
		// vec v;
		// v.x = vertices[i + 1].x - vertices[i].x;
		// v.y = vertices[i + 1].y - vertices[i].y;
		sides[i].id = i;
		sides[i].a = -sides[i].p2.y + sides[i].p1.y;
		sides[i].b = sides[i].p2.x - sides[i].p1.x;
		sides[i].veclen = veclen({ sides[i].a, sides[i].b });
		sides[i].c = - sides[i].a * sides[i].p1.x - sides[i].b * sides[i].p1.y;
		if (i > 0) sides[i].p0 = vertices[i - 1];
		else sides[i].p0 = vertices[n - 1];
		if (i < n - 2) sides[i].p3 = vertices[i + 1];
		else if (i < n - 1) sides[i].p3 = vertices[0];
		else sides[i].p3 = vertices[1];
		/*
		x   0 -1 x'
		y   1  0 y'		
		*/
	}
	return sides;
}

int main() {
	point** vertices;
	point** points;
	int* vert_sizes;
	int* p_sizes;
	int t;
	read_tests("F:\\University\\C++\\iRunner Competition\\visioned-tests.txt", vertices, points, vert_sizes, p_sizes, t);

	side** sides = new side * [t];
	for (int i = 0; i < t; i++) {
		sides[i] = divide_into_sides(vertices[i], vert_sizes[i]);
		cout << i << ":\n";
		for (int j = 0; j < vert_sizes[i]; j++) {
			cout << sides[i][j].id << ": ";
			cout << sides[i][j].a << ' ' << sides[i][j].b << ' ' << sides[i][j].c << "; ";
			cout << sides[i][j].p1.x << " - " << sides[i][j].p1.y << "; ";
			cout << sides[i][j].p2.x << " - " << sides[i][j].p2.y << "; ";
			cout << sides[i][j].veclen << endl;
		}
	}

	for (int i = 0; i < t; i++) {
		delete[]vertices[i];
		delete[]sides[i];
		delete[]points[i];
	}
	delete[]vertices;
	delete[]sides;
	delete[]points;

	return 0;
}