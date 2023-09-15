#include <iostream>

using namespace std;

void splitArray(int* staticArray, 
int size, 
int*& positiveArray, 
int& positiveSize, 
int*& negativeArray, 
int& negativeSize, 
int*& zeroArray, 
int& zeroSize) {
    positiveSize = 0;
    negativeSize = 0;
    zeroSize = 0;

    // количество положительных, отрицательных и нулевых элементов
    for (int i = 0; i < size; i++) {
        if (staticArray[i] > 0) {
            positiveSize++;
        } else if (staticArray[i] < 0) {
            negativeSize++;
        } else {
            zeroSize++;
        }
    }

    // Создание динамических массивов
    positiveArray = new int[positiveSize];
    negativeArray = new int[negativeSize];
    zeroArray = new int[zeroSize];

    int positiveIndex = 0;
    int negativeIndex = 0;
    int zeroIndex = 0;

    for (int i = 0; i < size; i++) {
        if (staticArray[i] > 0) {
            positiveArray[positiveIndex++] = staticArray[i];
        } else if (staticArray[i] < 0) {
            negativeArray[negativeIndex++] = staticArray[i];
        } else {
            zeroArray[zeroIndex++] = staticArray[i];
        }
    }
}

int main() {
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int* staticArray = new int[size];

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> staticArray[i];
    }

    int* positiveArray;
    int positiveSize;
    int* negativeArray;
    int negativeSize;
    int* zeroArray;
    int zeroSize;

    splitArray(staticArray, size, positiveArray, positiveSize, negativeArray, negativeSize, zeroArray, zeroSize);

    cout << "Положительные элементы: ";
    for (int i = 0; i < positiveSize; i++) {
        cout << positiveArray[i] << " ";
    }
    cout << endl;

    cout << "Отрицательные элементы: ";
    for (int i = 0; i < negativeSize; i++) {
        cout << negativeArray[i] << " ";
    }
    cout << endl;

    cout << "Нулевые элементы: ";
    for (int i = 0; i < zeroSize; i++) {
        cout << zeroArray[i] << " ";
    }

    return 0;
}
