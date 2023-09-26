#include <iostream>

using namespace std;

struct DoublyLinkedListNode {
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
    DoublyLinkedListNode(int x) : data(x), next(nullptr), prev(nullptr) {} // обьявдяем двусвязный список
};

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) //Эта функция нужна для вставки нового элемента с данными data в отсортированный двусвязный список, который начинается с головного узла
{
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data); // создаем новый узел который будет вставлен

    if (!head || data < head->data) { // если новый узел равен нулю или меньше головы, кладем его в самое начало
        newNode->next = head;
        if (head) head->prev = newNode;
        return newNode;
    }

    DoublyLinkedListNode* current = head;

    while (current->next && data > current->next->data) { // Внутри цикла while указатель current переходит к следующему элементу списка с помощью current->next. Это позволяет продолжать сравнивать data с следующими элементами списка до тех пор, пока не будет найдено подходящее место для вставки.
        current = current->next;
    }

    newNode->next = current->next;
    if (current->next) current->next->prev = newNode;
    newNode->prev = current; // вставляется элемент
    current->next = newNode;

    return head;
}

void printList(DoublyLinkedListNode* head) { // вывод в консоль
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Введите количество элементов в двусвязанном списке: ";
    cin >> n;

    DoublyLinkedListNode* head = nullptr;

    for (int i = 0; i < n; i++) {
        int data;
        cout << "Элемент номер " << i+1 << ": ";
        cin >> data;
        head = sortedInsert(head, data);
    }

    int newData;
    cout << "Введите новый элемент в список: ";
    cin >> newData;
    head = sortedInsert(head, newData);
    cout << "Ваш новый список: ";
    printList(head);

    return 0;
}
