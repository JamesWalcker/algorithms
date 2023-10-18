#ifndef _EXAMPLE_H_

#define _EXAMPLE_H_
#include <iostream>
using namespace std;


class FixedCapacityStack {
	private: 
	int* a;     // Массив, содержащий элементы стека
	int n;      // Количество элементов в стеке в данный момент
	int capacity; // Максимальная вместимость стека


	public:
	FixedCapacityStack(int capacity) { // конструктор чтобы передавать значения
        this->capacity = capacity; // this нужен для того чтобы знать о чем идет речь
        n = 0;
        a = new int[capacity];
    }

	 ~FixedCapacityStack() { // деструктор чтобы почищать за собой
        delete[] a;
    }

	 bool empty() const { // Использование const в методах помогает обозначить, какие методы могут изменять состояние объекта, а какие только читать его данные, что может быть полезным для понимания, какие операции безопасны и не изменяют объект при работе с ним.
        return n == 0;
    }

	 bool full() const {
        return n == capacity;
    }

    void push(int item) {
        if (full()) {
            cout << "Стек полон, не получается добавить элемент" << endl; // в случае если полон
            return;
        }
        a[n++] = item;
    }

    int pop() {
        if (empty()) {
            cout << "Стек пуст, не получается извлечь элемент." << endl;
            return -1;
        }
        return a[--n]; // потому что число элементов меняется до извлечения, а не после
    }

    int top() const {
        if (empty()) {
            cout << "Стек пуст, вершины нет." << endl;
            return -1;
        }
        return a[n - 1];
    }

	 friend ostream& operator<<(ostream& os, const FixedCapacityStack& st) {
        os << "Стек: ";
        for (int i = 0; i < st.n; i++) {
            os << st.a[i] << " ";
        }
        return os;
    } // Разница заключается в том, что во втором примере мы можем использовать оператор <<, чтобы напрямую выводить содержимое стека, не создавая дополнительных методов, таких как print(). Это делает код более читаемым и упрощает вывод объекта FixedCapacityStack.

};

#endif