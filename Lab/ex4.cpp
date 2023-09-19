#include <iostream>
using namespace std;


void blockElementsToEndArray(
int*& arr, // Указатель на указатель на int
int& size, // Адрес указателя
const int* elementsAdd, // Обьявление указателя
int elementsCount) {
    int* nArray = new int[size + elementsCount]; // обьявление указателя и присвоение к нему новый массив

    for (int i = 0; i < size; i++) {
        nArray[i] = arr[i];
    }

    for (int i = 0; i < elementsCount; i++) { // Добавление элементов с блока
        nArray[size + i] = elementsAdd[i];
    }

    delete[] arr; // очистка памяти для избежание утечки памяти и оптимизации
    arr = nArray; // присваем после выполнения функции
    size += elementsCount; // присваиваем чтобы колличество элементов соответствовало
}

int main() {
    int* dArray; // обьявление динамического массива который будет вначале
    int size;

   cout << "Введите размер изначального массива: ";
   cin >> size;

   dArray = new int[size]; // Обьявление указателем на динамически выделенный массив целых чисел размером size.

   cout << "Введите элементы изначального массива:" << endl;
    for (int i = 0; i < size; i++) {
      cin >> dArray[i];
    }

   cout << "Введите количество элементов для добавления в конец: ";
   
	int elementsCount; // Не знаю почему он не находит эту переменную, хоть я ее и определял уже выше
   cin >> elementsCount;

   int* elementsAdd = new int[elementsCount];
   cout << "Введите элементы для добавления в конец:" << endl;
   for (int i = 0; i < elementsCount; i++) {
      cin >> elementsAdd[i];
    }

    blockElementsToEndArray(dArray, size, elementsAdd, elementsCount); // вводим данные которые пойдут по указателями

   cout << "Массив после добавления элементов в конец: ";
    for (int i = 0; i < size; i++) {
      cout << dArray[i] << " ";
    }

    delete[] dArray; // чистка
    delete[] elementsAdd;

    return 0; // вывод при работе с указателями и динамической памятью не требуется копировать весь массив каждый раз, когда вы хотите добавить элементы. Вместо этого вы просто создаете новый массив с дополнительными элементами и копируете только необходимые данные.
}
