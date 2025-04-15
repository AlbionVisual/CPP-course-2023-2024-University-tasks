#include <iostream>

using namespace std;

struct coord {
	float x, y;
};

class Triangle {
	coord a, b, c;
	float area;
	float distance(coord, coord);
	void calcArea();
	bool set;

public:
	Triangle() { set = false; };
	Triangle(coord a0, coord b0, coord c0) { a = a0; b = b0; c = c0; set = true; calcArea(); };
	void getVertices();
	bool hasVertex(coord);
	float getArea();
	void setVertices();

	bool isConstructable();
};

int main() {

	int n = 0; cout << "Enter amount of triangles: "; cin >> n; cout << endl;
	Triangle* trigs = new Triangle[n];
	for (int i = 0; i < n; i++) {
		cout << "Triangle number " << i << ":\n";
		trigs[i].setVertices();
	}
	
	bool printed = false;
	for (int i = 0; i < n; i++) {
		if (trigs[i].isConstructable()) {
			if (!printed) {
				cout << "You can construct triangles with this vertices:" << endl;
				printed = true;
			}
			trigs[i].getVertices();
		}
	}
	if (!printed) cout << "No constructable triangles!" << endl;
	cout << endl;

	int maxArea = 0, hasVertex = -1;
	coord d;
	cout << "Enter point to search (x, y): "; cin >> d.x >> d.y;
	for (int i = 0; i < n; i++) {
		if (trigs[maxArea].getArea() < trigs[i].getArea()) maxArea = i;
		if (hasVertex == -1 and trigs[i].hasVertex(d)) hasVertex = i;
	}

	cout << "Max area has triangle with index: " << maxArea << "\n";
	if (hasVertex != -1) cout << "Your point first appear in triangle with index: " << hasVertex << endl;
	else cout << "Your triangles doesn't have your point!\n";
	

	delete[] trigs;

	return 0;
}

float Triangle::distance(coord a, coord b) {
	return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}
void Triangle::getVertices() {
	if (set) cout << "A(" << a.x << ", " << a.y << "), B(" << b.x << ", " << b.y << "), C(" << c.x << ", " << c.y << ")" << endl;
}
float Triangle::getArea() {
	if (set) return area;
	else return 0.0;
}
bool Triangle::isConstructable() {
	if (set) {
		coord v1, v2;
		v1.x = b.x - a.x; v1.y = b.y - a.y;
		v2.x = c.x - a.x; v2.y = c.y - a.y;
		if (v1.x * v2.y - v1.y * v2.x == 0) return false;
		else return true;
	}
	else {
		return false;
	}
}
void Triangle::calcArea() {
	float AB, BC, CA;

	AB = distance(a, b);
	BC = distance(b, c);
	CA = distance(c, a);

	float p = (AB + BC + CA) / 2;

	area = sqrt(p * (p - AB) * (p - BC) * (p - CA));
}
void Triangle::setVertices() {
	cout << "Enter coords of A (x, y): "; cin >> a.x >> a.y;
	cout << "Enter coords of B (x, y): "; cin >> b.x >> b.y;
	cout << "Enter coords of C (x, y): "; cin >> c.x >> c.y;
	calcArea();
	cout << endl;
	set = true;
}
bool Triangle::hasVertex(coord d) {
	coord cords[3] = { a, b, c };

	for (int i = 0; i < 3; i++)
		if (cords[i].x == d.x and cords[i].y == d.y) return true;

	return false;
}