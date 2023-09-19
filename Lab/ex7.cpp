#include <iostream>
#include <cmath>
using namespace std;


// Функция которая проверяет простое число или нет
bool prostoeChislo(int number) {
    if (number <= 1){
		return false;
	 } 
    if (number == 2 || number == 3){
		return true;
	 } 
    if (number % 2 == 0 || number % 3 == 0){
		return false;
	 } 
	for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Функция для удаления простых чисел из массива
int* removePrimes(int* arr, int& size) {
    int nSize = 0;

    // Определение нового размера массива
    for (int i = 0; i < size; i++) {
        if (!prostoeChislo(arr[i])) {
            arr[nSize] = arr[i];
            nSize++;
        }
    }
    int* nArray = new int[nSize];
    for (int i = 0; i < nSize; i++) {
        nArray[i] = arr[i];
    }

    size = nSize; 

    return nArray; 
}

int main() {
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int* dArray = new int[size];

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> dArray[i];
    }

    int nSize = size; // Переменная для хранения нового размера массива
    int* nArray = removePrimes(dArray, nSize);

    cout << "Массив без простых чисел:" << endl;
    for (int i = 0; i < nSize; i++) {
        cout << nArray[i] << " ";
    }


    return 0;
}
