#include <iostream>
using namespace std;

class cord {
public:
	int x = 0;
	int y = 0;
};

class line {
public:
	double a, b;
	bool isZoneBelow = false;

	void setKoffs(cord cord1, cord cord2) {
		if ((cord1.x - cord2.x) == 0) a = 0;
		else a = (cord1.y - cord2.y) / (cord1.x - cord2.x);
		b = cord1.y - a * cord1.x;
	}

	void setIsBelow(cord cord3) {
		if (cord3.x * a + b > cord3.y) isZoneBelow = true;
	}

	bool isInZone(cord cord4) {
		if (isZoneBelow) {
			if (cord4.x * a + b >= cord4.y) return true;
			else return false;
		}
		else {
			if (cord4.x * a + b <= cord4.y) return true;
			else return false;
		}
	}
};

int main() {

	cord cord1, cord2, cord3, toReserch;

	cout << "Enter 1st value x, y: "; cin >> cord1.x >> cord1.y;
	cout << "Enter 2nd value x, y: "; cin >> cord2.x >> cord2.y;
	cout << "Enter 3rd value x, y: "; cin >> cord3.x >> cord3.y;
	cout << "Enter dot to find value x, y: "; cin >> toReserch.x >> toReserch.y;

	line line1; line1.setKoffs(cord1, cord2);
	line line2; line2.setKoffs(cord2, cord3);
	line line3; line3.setKoffs(cord3, cord1);

	line1.setIsBelow(cord3);
	line2.setIsBelow(cord1);
	line3.setIsBelow(cord2);

	if (line1.isInZone(toReserch) && line2.isInZone(toReserch) && line3.isInZone(toReserch)) cout << "Your dot is in zone!";
	else cout << "The zone doesn`t cover this dot!";

	return 0;
}

/*

y = ax + b
cord1.y = a * cord1.x + b
b = cord1.y - a * cord1.x = cord2.y - cord2.x * a
a * cord1.x - a * cord2.x = cord1.y - cord2.y
a = (cord1.y - cord2.y) / (cord1.x - cord2.x)
b = cord1.y - a * cord1.x


*/