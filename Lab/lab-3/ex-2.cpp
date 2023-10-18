#include <iostream>
#include "LinkedStack.h"


using namespace std;

int main() {
    LinkedStack stack;

    int capacity;
    cout << "Введите максимальную вместимость стека: ";
    cin >> capacity;

    for (int i = 1; i <= capacity; i++) {
        int item;
        cout << "Введите элемент №" << i << ": ";
        cin >> item;
        stack.push(item);
    }

    cout << "Стек: ";
    stack.print();

    int popElement = stack.pop();
    if (popElement != -1) {
        cout << "Извлеченный элемент: " << popElement << endl;
    }

    int topElement = stack.topValue();
    if (topElement != -1) {
        cout << "Вершина стека: " << topElement << endl;
    }

    cout << "Стек: ";
    stack.print();

    return 0;
}
