#include <iostream>
#include <cstring>

using namespace std;

class Plane {
	int flight;
	int code;
	char surname[100] = "";
	int weight;
public:
	Plane() {};
	Plane(int flight0, int code0, char surname0[100], int weight0) { flight = flight0; code = code0; strcat_s(surname, surname0); weight = weight0; };
	void set();
	void get();
	int get_flight();
	int get_weight();
};

void sort(Plane* pass, int n);

int main() {

	int n; cout << "Enter full amount of passangers: "; cin >> n; cout << endl;
	Plane* pass = new Plane[n];
	for (int i = 0; i < n; i++) {
		cout << "Passanger " << i << endl;
		pass[i].set();
	}

	sort(pass, n);

	cout << "Sorted passangers : " << endl;
	for (int i = 0; i < n; i++) {
		pass[i].get();
	}

	int choice; cout << "\nEnter flight number to filter: "; cin >> choice;
	Plane* filtered = new Plane[n];
	int n2 = 0, max = 0;
	for (int i = 0; i < n; i++) {
		if (pass[i].get_flight() == choice) {
			filtered[n2] = pass[i];
			n2 += 1;
		}
		if (pass[i].get_weight() > pass[max].get_weight()) max = i;
	}

	cout << endl << "Filtered passangers:" << endl;
	int avg = 0;
	for (int i = 0; i < n2; i++) {
		filtered[i].get();
		avg += filtered[i].get_weight();
	}
	avg /= n2;

	cout << "\nMax weight has this passenger: ";
	pass[max].get();

	cout << "\nSelected flight avg weight is: " << avg;

	delete[]pass;
	delete[]filtered;

	return 0;
}

void Plane::set() {
	cout << "Enter flight number: "; cin >> flight;
	cout << "Enter passanger code: "; cin >> code;
	cout << "Enter surname: "; cin >> surname;
	cout << "Enter package weight: "; cin >> weight;
	cout << endl;
}
void Plane::get() {
	cout << flight << "\t" << surname << "\t" << code << "\t" << weight << endl;
}
int Plane::get_flight() {
	return flight;
}
int Plane::get_weight() {
	return weight;
}

void sort(Plane* pass, int n) {
	for (int i = 0; i < n; i++) {
		bool is_sorted = true;
		for (int j = 0; j < n - i - 1; j++) {
			if (pass[j].get_flight() > pass[j + 1].get_flight()) {
				Plane temp = pass[j];
				pass[j] = pass[j + 1];
				pass[j + 1] = temp;
				is_sorted = false;
			}
		}
		if (is_sorted) break;
	}
}