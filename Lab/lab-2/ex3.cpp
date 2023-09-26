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
    void coutList();
    void print();
    void reverse();

private:
    ListNode* head;
};

void MyLinkedList::addAtHead(int val) {
    // Создаем новый узел с заданным значением
    ListNode* newNode = new ListNode(val);

    // Присваиваем следующему элементу нового узла текущую голову списка
    newNode->next = head;

    // Обновляем голову списка, чтобы она указывала на новый узел
    head = newNode;
}

void MyLinkedList::coutList() {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

void MyLinkedList::print() {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

void MyLinkedList::reverse() {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next; // Сохраняем указатель на следующий элемент

        // Инвертируем указатель на следующий элемент
        current->next = prev;

        // Перемещаем указатели к следующим элементам
        prev = current;
        current = next;
    }

    // Обновляем голову списка
    head = prev;
}

int main() {
    MyLinkedList linkedList;

    int num;
    int numNodes;

    cout << "Введите количество связанных ячеек: ";
    cin >> numNodes;

    cout << "Введите " << numNodes << " чисел для добавления в список:" << endl;

    for (int i = 0; i < numNodes; ++i) {
        cin >> num;
        linkedList.addAtHead(num);
    }

    cout << "Список:" << endl;
    linkedList.coutList();

    cout << "Значения списка:" << endl;
    linkedList.print();

    cout << "Инвертированный список:" << endl;
    linkedList.reverse();
    linkedList.coutList();

    return 0;
}
