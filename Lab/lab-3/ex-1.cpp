#include <iostream>
#include "FixedCapacityStack.h"

using namespace std;





int main() {
    int capacity;
    cout << "Введите максимальную вместимость стека: ";
    cin >> capacity;

    FixedCapacityStack stack(capacity);

    
for (int i = 1; i <= capacity; i++)
{
				int item;
            cout << "Введите элемент №" << i << ": ";
            cin >> item;
            stack.push(item);
}
	cout << stack << endl;


int popElement = stack.pop();
            if (popElement != -1) {
                cout << "Извлеченный элемент: " << popElement << endl;
            }

int topElement = stack.top();
            if (topElement != -1) {
                cout << "Вершина стека: " << topElement << endl;
            }			
	
	cout << stack << endl;
    return 0;
}