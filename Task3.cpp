#include <iostream>
#include <vector> 
#include <algorithm> 

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void shiftRight(std::vector<int>& arr, int n) {
    int size = arr.size();

    // Если массив пуст или сдвиг равен 0, ничего делать не нужно
    if (size == 0 || n % size == 0) {
        return;
    }

    // Нормализуем сдвиг (если n больше длины массива)
    n = n % size;

    // Используем rotate для циклического сдвига
    std::rotate(arr.rbegin(), arr.rbegin() + n, arr.rend());
}

int main() {
    // Инициализируем массив
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    // Выводим исходный массив
    std::cout << "Исходный массив: ";
    printArray(arr);

    // Вводим значение N для сдвига
    int n;
    std::cout << "Введите количество позиций для сдвига вправо: ";
    std::cin >> n;

    // Сдвигаем массив вправо на N позиций
    shiftRight(arr, n);

    // Выводим результат
    std::cout << "Массив после сдвига: ";
    printArray(arr);

    return 0;
}






