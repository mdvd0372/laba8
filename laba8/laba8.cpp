#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int power(int number, int n) { // перевантаження pow
	return pow(number, n);
}
double root(double base, int exponent) { // перевантаження root
	return pow(base, 1.0 / exponent);
}
int binaryToDecimal(int binary[], int size) { // перетворення з двійкової в десяткову
    int decimal = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (binary[i] == 1) {
            decimal += pow(2, size - 1 - i);
        }
    }
    return decimal;
}
int main()
{
    unsigned size;
    cout << "Масив може містити тільки елементи 1 або 0.\n";
    cout << "Введіть розмір масиву: " << endl;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
tryAgain:
        cout << "Введіть " << i + 1 << "-ий елемент: ";
        cin >> arr[i];
        if (arr[i] != 0 && arr[i] != 1) {
            cout << "Введені недопустимі значення. Введіть 0 або 1.\n";
            goto tryAgain;
        }
    }
    cout << "\n{ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "}\n";
    int decimal = binaryToDecimal(arr, size);
    cout << "\nЧисло в дестковій системі числення: " << decimal << endl;
}
