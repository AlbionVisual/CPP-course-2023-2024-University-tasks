// ѕример 1. ќрганизовать бесконечный цикл. ѕосчитать количество 
// итераций цикла. »спользовать оператор break.
#include <iostream>
using namespace std;
int main() {
	int count(0); 			// или count = 0; Ц кол-во итераций цикла
	char simv;
	while (true) { 			// бесконечный цикл 
		cout << "Enter symbol y/n to continue/exit the cycle: \n";
		cin >> simv;
		if (simv == 'n') break;
		count = count + 1;
	}
	cout << "the number of iteration cycle = " << count << endl;
}
