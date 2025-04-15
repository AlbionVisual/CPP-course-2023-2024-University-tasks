#include <iostream>

using namespace std;

class Complex {
	int r, i;
public:
	Complex() { r = 0; i = 0; };
	Complex(int r0, int i0) { r = r0; i = i0; };
	friend Complex sum(Complex, Complex);
	friend Complex difference(Complex, Complex);
	friend Complex* maxRealPart(Complex*, int);
	void show() { cout << this->r << ' ' << this->i << endl; };
	void set();
};

Complex* maxRealPart(Complex* nums);

int main() {

	int n; cout << "Enter amount: "; cin >> n; cout << endl;

	Complex* nums = new Complex[n];
	for (int i = 0; i < n; i++)
		nums[i].set();
	cout << endl;

	int i1, i2; char choice;
	do {
		cout << "Enter 2 indexes: "; cin >> i1 >> i2;
		cout << "Select operation ( + , - , other to end): "; cin >> choice;
		if (choice == '+') sum(nums[i1], nums[i2]).show();
		if (choice == '-') difference(nums[i1], nums[i2]).show();
		cout << endl;
	} while (choice == '+' or choice == '-');

	cout << "Max real part in number: "; maxRealPart(nums, n)->show();

	delete[] nums;

	return 0;
}

Complex sum(Complex c1, Complex c2) {
	return Complex(c1.r + c2.r, c1.i + c2.i);
}

Complex difference(Complex c1, Complex c2) {
	return Complex(c1.r - c2.r, c1.i - c2.i);
}

void Complex::set() {
	cout << "Enter number (r, i): "; cin >> this->r >> this->i;
}

Complex* maxRealPart(Complex* nums, int n) {
	Complex* max = nums;
	for (Complex* p = nums; p < nums + n; p++)
		if ( p->r  >  max->r )
			max = p;
	return max;
}