#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    // Задаем константы согласно условию
    const double A = 0;
    const double B = M_PI / 2;  // π/2
    const int M = 20;
    const double H = (B - A) / M;  // Шаг

    cout << "Вычисление y = sin(x) - cos(x) на отрезке [0, π/2]:\n";
    cout << setw(10) << "x" <<setw(15) << "y" <<endl;
    cout << string(25, '-') <<endl;

    for (int i = 0; i <= M; ++i) {
        double x = A + i * H;  // Вычисляем текущее значение x
        double y = sin(x) - cos(x);  // Вычисляем значение функции
        // Выводим результат с форматированием
        cout << fixed <<setprecision(4) 
                  << setw(10) << x 
                  << setw(15) << y << endl;
    }

    return 0;
} 