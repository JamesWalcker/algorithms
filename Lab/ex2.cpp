#include <iostream> // Муратов Алмас

using namespace std;

int main() {
    int M, N, K=0; // Обьевляем перемнные. Переменную К мы сразу обнуляем, чтобы не возникло ошибок

    cout << "Введите размер массива A: ";
    cin >> M;

    cout << "Введите размер массива B: ";
    cin >> N;

    int A[M], B[N], C[100]; // После того как перменные "M" и "N" обьявленны конкретной цифрой - можно обьявить массив. Потому как чтобы массив был неопределенной длинны нужно использовать vector. А по спецофикации мне запрещено использовать vector and set
	 // Массив "C" ограничил до "K", потому как нельзя использовать вектора

    cout << "Введите элементы массива A:" << endl;
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Введите элементы массива B:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    cout << "Массив A:";
    for (int i = 0; i < M; i++) {
        cout << " " << A[i];
    }
    cout << endl;

    cout << "Массив B:";
    for (int i = 0; i < N; i++) {
        cout << " " << B[i];
    }
    cout << endl;
    
    for (int i = 0; i < M; i++) {
        bool findInArrayB = false; // Булевое значение для переменной "findInArrayB" чтобы дать понять системе где совпадает, а где нет
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                findInArrayB = true;
                break; // Если элемент найден в B, прекращаем итерации в цикле
            }
        }
        if (findInArrayB == false) { // В случуае если найдено значения которого нет в массиве В
            C[K] = A[i];
            K++;
        }
    }
    
    cout << "Массив C:";
    for(int i = 0; i < K; i++){
        cout << " " << C[i];
    }
    
// итог: два массива "А" и "В" длинною "N" и "M" вводятся с клавиратуры. Массив "С" содержит в себе элементы массива А которых нет в массиве В, а так же он минимального размера
    return 0;
}