#include <iostream>
using namespace std;

const int SIZE = 40;

void printWords(char[]);

int main() {

    // 3. В заданной строке найти и вывести на экран все слова, в которых первый
    // и последний символы совпадают и длина которых чётная.

    char str[SIZE]; // Original string
    cout << "Enter your string: ";
    cin.get(str, SIZE);

    printWords(str);

    return 0;
}

void printWords(char str[]) {
    int firstSymInd, length = 0;

    // skipping spaces in start
    int i = 0;
    while (str[i] == ' ' || i > strlen(str)) {
        i++;
    }
    firstSymInd = i;

    // Searching words
    cout << "Your words: ";
    for (; i <= strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '\0') { // when end of the word
            if (str[firstSymInd] == str[i - 1] && length % 2 == 0) { // if passes according to the condition
                for (int k = firstSymInd; k < i; k++) { // cout word
                    cout << str[k];
                }
                cout << " ";
            }

            // skipping spaces
            while (str[i + 1] == ' ') i++;
            firstSymInd = i + 1;
            length = 0;
        }
        else length++;
    }
}