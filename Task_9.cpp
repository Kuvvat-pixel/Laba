#include <iostream>
#include <cmath>
double phi(double x) {
    // Здесь может быть твоя функция phi(x)
    return x; // замените на конкретную функцию
}
int main() {
    double z;
    std::cout << "Введите z: ";
    std::cin >> z;
    // Рассчитываем x
    double x = sin(z);
    // Вычисляем y
    double y = pow(sin(phi(x)), 7) + pow(2, 2) + pow(x, 3);
    std::cout << "Значение y: " << y << std::endl;   
    return 0;
}