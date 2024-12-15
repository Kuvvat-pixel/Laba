#include <stdio.h>
#include <stdlib.h>

void find_max_diagonal(int ***arr, int N) {
    int max_sum = -1;
    int diag_type = -1;
    int sum;

    // Проверка главной диагонали
    sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i][i][i];
    }
    if (sum > max_sum) {
        max_sum = sum;
        diag_type = 1; // Главная диагональ
    }

    // Проверка побочной диагонали
    sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i][i][N - i - 1];
    }
    if (sum > max_sum) {
        max_sum = sum;
        diag_type = 2; // Побочная диагональ
    }

    // Вывод результата
    if (diag_type == 1) {
        printf("Главная диагональ с суммой: %d\n", max_sum);
    } else if (diag_type == 2) {
        printf("Побочная диагональ с суммой: %d\n", max_sum);
    }
}

int main() {
    int N;

    // Ввод размера массива
    printf("Введите размер массива N (например, 3): ");
    scanf("%d", &N);

    // Динамическое выделение памяти для трехмерного массива
    int *arr = (int *)malloc(N * sizeof(int **));
    for (int i = 0; i < N; i++) {
        arr[i] = (int **)malloc(N * sizeof(int *));
        for (int j = 0; j < N; j++) {
            arr[i][j] = (int *)malloc(N * sizeof(int));
        }
    }

    // Ввод элементов массива
    printf("Введите элементы трехмерного массива размером %d x %d x %d:\n", N, N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                printf("arr[%d][%d][%d] = ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    // Нахождение диагонали с максимальной суммой
    find_max_diagonal(arr, N);

    // Освобождение памяти
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);

    return 0;
}