#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция для вычисления факториала
double factorial(int n) {
    if (n == 0) return 1;
    double result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Функция для вычисления значения через ряд Тейлора
double calculateSeries(double x, int n) {
    double result = 0;
    // Разложение sin(x) - cos(x) в ряд Тейлора
    for (int i = 0; i < n; ++i) {
        // Члены ряда для sin(x)
        if (i % 2 == 0) {
            result += pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);
        }
        // Члены ряда для -cos(x)
        result -= pow(-1, i) * pow(x, 2 * i) / factorial(2 * i);
    }
    return result;
}

int main() {
    int n, count;
    
    cout << "Введите количество членов ряда: ";
    cin >> n;
    
    cout << "Введите количество точек для вычисления: ";
    cin >> count;
    
    cout << fixed << setprecision(6);
    
    for (int i = 0; i < count; ++i) {
        double x;
        do {
            cout << "Введите x (от 0.1 до 1): ";
            cin >> x;
        } while (x < 0.1 || x > 1);
        
        double series_result = calculateSeries(x, n);
        double actual_result = sin(x) - cos(x);
        
        cout << "Значение через ряд: " << series_result << endl;
        cout << "Точное значение:    " << actual_result << endl;
        cout << "Погрешность:        " << fabs(series_result - actual_result) << endl;
        cout << "------------------------\n";
    }
    
    return 0;
}