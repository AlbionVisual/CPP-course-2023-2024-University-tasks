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

int main() {

	point** vertices;
	point** points;
	int* vert_sizes;
	int* p_sizes;
	int t;
	read_tests("F:\\University\\C++\\iRunner Competition\\visioned-tests.txt", vertices, points, vert_sizes, p_sizes, t);

	cout << t << endl;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < vert_sizes[i]; j++) {
			cout << vertices[i][j].x << ", " << vertices[i][j].y << "; ";
		}
		cout << endl;
		for (int j = 0; j < p_sizes[i]; j++) {
			cout << points[i][j].x << ", " << points[i][j].y << "; ";
		}
		cout << endl;
	}

	int** dists = new int* [t];
	point** min_points = new point * [t];
	
	// Check your files here

	/*
	ofstream output("F:\\University\\C++\\iRunner Competition\\output.txt");
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < p_sizes[i]; j++) {
			output << dists[i][j] << ' ' << min_points[i][j].x << ' ' << min_points[i][j].y;
		}
	}//*/

	for (int i = 0; i < t; i++) {
		delete[]vertices[i];
		//delete[]dists[i];
		//delete[]min_points[i];
		delete[]points[i];
	}
	delete[]vertices;
	delete[]dists;
	delete[]min_points;
	delete[]points;

	return 0;
}