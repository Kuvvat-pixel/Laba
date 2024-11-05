#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double x;
    char choice;
    
    do {
        cout << "Программа для нахождения минимального значения среди:\n";
        cout << "a = sin(x)\n";
        cout << "b = cos(x)\n";
        cout << "c = ln|x|\n\n";
        
        cout << "Введите значение x: ";
        cin >> x;
        
        // Вычисляем значения выражений
        double a = sin(x);
        double b = cos(x);
        double c = log(fabs(x));  // используем fabs для модуля числа
        
        cout << fixed << setprecision(6);
        cout << "\nПолученные значения:\n";
        cout << "a = sin(" << x << ") = " << a << endl;
        cout << "b = cos(" << x << ") = " << b << endl;
        cout << "c = ln|" << x << "| = " << c << endl;
        
        // Находим минимальное значение
        double min_value = a;  // предполагаем, что a минимальное
        
        if (b < min_value) {
            min_value = b;
        }
        if (c < min_value) {
            min_value = c;
        }
        
        cout << "\nМинимальное значение: " << min_value << endl;
        
        // Показываем, какие выражения дали минимальное значение
        cout << "Минимум достигается в выражении(ях): ";
        if (fabs(a - min_value) < 1e-10) cout << "sin(x) ";
        if (fabs(b - min_value) < 1e-10) cout << "cos(x) ";
        if (fabs(c - min_value) < 1e-10) cout << "ln|x| ";
        cout << endl;
        
        cout << "\nХотите продолжить? (y/n): ";
        cin >> choice;
        cout << "\n";
        
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}