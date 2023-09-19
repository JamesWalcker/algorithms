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
    
    for (int i = 0; i < M; i++) { //  Так как мне нельзя использовать библиотеку Set для поиска уникальных чисел, будем действовать топорным методом поиска
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
               A[i] = -1;
					B[j] = -1; // Находим общие значения и приравниваем их к значению "-1"
            }
        }
    }

    // Заполняем массив C элементами из A, которые не Не ровняются значению "-1"
    for (int i = 0; i < M; i++) {
        if (A[i] != -1) {
            C[K] = A[i];
            K++;
        }
    }

    // Заполняем массив C элементами из В, которые не Не ровняются значению "-1"
    for (int i = 0; i < N; i++) {
        if (B[i] != -1) {
            C[K] = B[i];
            K++;
        }
    }
    
    cout << "Массив C:";
    for(int i = 0; i < K; i++){
        cout << " " << C[i];
    }
    
// итог: два массива "А" и "В" длинною "N" и "M" вводятся с клавиратуры. Массив "С" содержит в себе только уникальные числа, а так же он минимального размера
    return 0;
}