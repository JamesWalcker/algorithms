#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class MyLinkedList {
public:
    MyLinkedList() : head(nullptr) {}
    void addAtHead(int val);
    void coutList(); // MyLinkedList() : head(nullptr) {}: Это конструктор класса MyLinkedList, который инициализирует голову списка (член head) значением nullptr. Этот конструктор будет вызван при создании объекта класса и устанавливает начальное состояние объекта.

	 // void addAtHead(int val);: Это объявление метода addAtHead, который будет добавлять элемент в начало списка.
	 //void coutList();: Это объявление метода coutList, который будет выводить содержимое списка на консоль.
	 //private: В этом разделе определены члены класса, которые не доступны извне класса. ListNode* head представляет голову связного списка.

private:
    ListNode* head;
};

void MyLinkedList::addAtHead(int val) {
    // Создаем новый узел с заданным значением
    ListNode* newNode = new ListNode(val);

    // Присваиваем следующему элементу нового узла текущую голову списка
    newNode->next = head;

    // Обновляем голову списка, чтобы она указывала на новый узел
    head = newNode; // Это определение метода addAtHead. Метод addAtHead добавляет новый элемент в начало связного списка. Он создает новый узел (ListNode) с заданным значением val, затем устанавливает указатель next нового узла на текущую голову списка (head) и, наконец, обновляет голову списка (head) так, чтобы она указывала на новый узел.
}

void MyLinkedList::coutList() {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    MyLinkedList linkedList;

    int num;
    int numNodes;

    cout << "Введите количество связанных ячеек: ";
    cin >> numNodes;

    cout << "Введите " << numNodes << " чисел для добавления в список:" << endl;

    for (int i = 0; i < numNodes; i++) {
        cin >> num;
        linkedList.addAtHead(num);
    }

    cout << "Список:" << endl;
    linkedList.coutList();

    return 0;
}
