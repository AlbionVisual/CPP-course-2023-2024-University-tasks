#include <iostream>
#include <ctime>
using namespace std;

void fillArr(int[], int, int= -RAND_MAX / 2, int= RAND_MAX / 2);
void outputArr(int[], int);

bool isMaxOne(int[], int);
int minDigit(int);
int rebuildArr(int[], int);
void deleteElem(int[], int, int);

int main() {

	// cout << (-1) % 10; здесь прикол :)

	const int SIZE = 10;
	int arr[SIZE];

	fillArr(arr, SIZE); // Ввод
	cout << "Array before: ";
	outputArr(arr, SIZE);

	int newSize; // После преобразований размер массива измениться
	if (isMaxOne(arr, SIZE)) { // Если максимальное единственное
		newSize = rebuildArr(arr, SIZE); // Преобразовать массив
		cout << endl << "Arr after: "; outputArr(arr, newSize); cout << endl;
	}
	else cout << "Max number isn't alone!"; // Иначе сказать что пошло не так

	return 0;
}

// Ввод / вывод массива
void fillArr(int arr[], int n, int min, int max) {
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		arr[i] = rand()%(max-min)+min;
	}

}
void outputArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}

bool isMaxOne(int arr[], int n) { // Проверка единственное ли максимальное значение
	int max = arr[0];
	bool isAlone = true;
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			isAlone = true;
			max = arr[i];
		}else if (arr[i] == max) {
			isAlone = false;
		}
	}
	return isAlone;
}
int minDigit(int num){ // Поиск минимальной цифры
	int min = num % 10;
	num /= 10;
	while (num) {
		if (num % 10 < min) min = num % 10;
		num /= 10;
	}
	return min;
}
int rebuildArr(int arr[], int n) { // Преобразование массива
	for (int i = 0; i < n; i++) {
		if (minDigit(abs(arr[i])) % 2 == 0) { // abs нужно из-за прикола сверху
			deleteElem(arr, n, i); // Если минимальная цифра чётная, то удалить этот элемент
			n--; // Уменьшить размер на 1
			i--; // и вернуть индекс для проверки, т. к. все числа сместяться на 1
		}
	}
	return n;
}
void deleteElem(int arr[], int size, int ind) { // Удаление элемента
	for (int i = ind; i < size-1; i++) {
		arr[i] = arr[i + 1]; // Смещение всех элементов на 1 начиная с i-ого
	}
	arr[size - 1] = 0; // Полседний элемент неопределён
}