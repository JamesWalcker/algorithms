#include <iostream>
#include <string>

using namespace std;

class MyStack {
public:
    MyStack() {
        // Пустой конструктор, потому что стринг это массив символов
    }

	 ~MyStack() {
		// Пустой деструктор потому что ничего удалять не надо
	 }

    void push(char currentChar) { // Добавление элемента в стек, через метод back в конец стека
        charIk.push_back(currentChar);
    }

    char top() {
        if (!charIk.empty()) { // верхушка стека
            return charIk.back();
        }
    }

    void pop() { // удаление верхнего элемента
        if (!charIk.empty()) { 
            charIk.pop_back();
        }
    }

    bool empty() {
        return charIk.empty();
    }

private:
    string charIk;
};

int main() {
	string s;
	cout << "Enter a string of brackets: ";
	cin >> s;

	MyStack stackAlmas;

   for (int i = 0; i < s.length(); i++) {

		char currentChar = s[i]; // присваиваю ему элемент для дальнейшей работы

    if (currentChar == '(' || currentChar == '[' || currentChar == '{') { // проверка на открытыю скобку
        stackAlmas.push(currentChar); // вставление в стек в случае если это открывающая скобка
    	}  
		else {

            char open = stackAlmas.top();
            stackAlmas.pop(); // не сразу понял вставить сюда

            if ((currentChar == ')' && open != '(') || (currentChar == ']' && open != '[') || (currentChar == '}' && open != '{')) {
                cout << "NO" << endl;
                return 0;
            }
        }
}

    if (stackAlmas.empty()) {
        cout << "Yep" << endl;
    } else {
        cout << "Nope" << endl;
    }

    return 0;
}
