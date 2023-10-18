#ifndef _EXAMPLE2_H_

#define _EXAMPLE2_H_
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedStack {
public:
    LinkedStack() : top(nullptr) {}

    bool empty() const {
        return top == nullptr;
    }

    void push(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (empty()) {
            cout << "Стек пуст, не получается извлечь элемент." << endl;
            return -1;
        }

        int val = top->val; // dulp здесь важно, потому что оно позволяет нам сохранить значение верхнего элемента перед его удалением,
        ListNode* dupl = top;
        top = top->next;
        delete dupl;
        return val;
    }

    int topValue() const {
        if (empty()) {
            cout << "Стек пуст, вершины нет." << endl;
            return -1;
        }

        return top->val;
    }

    void print() const {
        ListNode* current = top;
        while (current != nullptr) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    ListNode* top;
};

#endif