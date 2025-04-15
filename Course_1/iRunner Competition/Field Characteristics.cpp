#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct point {
	float x, y;
};

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

int main() {

	point** vertices;
	point** points;
	int* vert_sizes;
	int* p_sizes;
	int t;
	read_tests("F:\\University\\C++\\iRunner Competition\\visioned-tests.txt", vertices, points, vert_sizes, p_sizes, t);


	for (int i = 0; i < t; i++) {
		point min, max; float size;
		field_chars(vertices[i], points[i], vert_sizes[i], p_sizes[i], min, max, size);
		cout << i << ": (" << min.x << ", " << min.y << "), " << "(" << max.x << ", " << max.y << "); " << size << endl;
	}


	for (int i = 0; i < t; i++) {
		delete[]vertices[i];
		delete[]points[i];
	}
	delete[]vertices;
	delete[]points;
	return 0;

}