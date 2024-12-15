#include <iostream>
#include <climits> // Для INT_MIN
using namespace std;

int main() {
    int M, N; // Размеры матрицы

    // Пользователь вводит размеры матрицы
    cout << "Введите количество строк матрицы (M): ";
    cin >> M;
    cout << "Введите количество столбцов матрицы (N): ";
    cin >> N;

    // Создаем матрицу
    int matrix[M][N];

    // Заполняем матрицу
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Выводим введенную матрицу
    cout << "Введенная матрица:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    int maxBelowDiagonal = INT_MIN; // Переменная для максимума, начальное значение - минимально возможное

    // Проходим по элементам ниже побочной диагонали
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i + j > N - 1) { // Условие: элемент ниже побочной диагонали
                if (matrix[i][j] > maxBelowDiagonal) {
                    maxBelowDiagonal = matrix[i][j]; // Обновляем максимум
                }
            }
        }
    }

    // Вывод результата
    if (maxBelowDiagonal != INT_MIN) {
        cout << "Максимальный элемент ниже побочной диагонали: " << maxBelowDiagonal << endl;
    } else {
        cout << "Элементов ниже побочной диагонали нет." << endl;
    }

    return 0;
}