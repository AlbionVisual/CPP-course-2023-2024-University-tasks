#include <iostream>

using namespace std;

#define PI 3.14159265359

class Circl {
	int x, y, r;
public:
	Circl(int x0, int y0, int r0) { x = x0; y = y0; r = r0; };
	float square() { return PI * r * r; };
	friend int point(Circl ob, int xp, int yp);
};

int main() {

	int x, y, r;
	cout << "Enter x, y, r: "; cin >> x >> y >> r; cout << endl;
	Circl ob1(x,y,r);

	int xp, yp;
	do {
		cout << "Enter point coordinates (x, y), (" << x << ", " << y << " for end): "; cin >> xp >> yp;
		cout << "Is your point in circle: " << point(ob1, xp, yp) << endl;
	} while (xp != x or yp != y);

	cout << "The area of the circle: " << ob1.square();

	return 0;
}

int point(Circl ob, int xp, int yp) {
	if ( (xp-ob.x)*(xp-ob.x) + (yp-ob.y)*(yp-ob.y) <= ob.r*ob.r) return 1;
	else return 0;
}