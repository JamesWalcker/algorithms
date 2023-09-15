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
	 if (static_cast<int>(sqrt(number)) == sqrt(number)){
		return false;
	 } 

    return true;
}

// Функция для удаления простых чисел из массива
int* removePrimes(int* arr, int& size) {
    int newSize = 0;

    // Определение нового размера массива
    for (int i = 0; i < size; i++) {
        if (!prostoeChislo(arr[i])) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    int* newArray = new int[newSize];
    for (int i = 0; i < newSize; i++) {
        newArray[i] = arr[i];
    }

    size = newSize; 

    return newArray; 
}

int main() {
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int* dynamicArray = new int[size];

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> dynamicArray[i];
    }

    int newSize = size; // Переменная для хранения нового размера массива
    int* newArray = removePrimes(dynamicArray, newSize);

    cout << "Массив без простых чисел:" << endl;
    for (int i = 0; i < newSize; i++) {
        cout << newArray[i] << " ";
    }


    return 0;
}
