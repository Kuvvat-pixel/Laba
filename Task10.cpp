#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция для вычисления факториала
double factorial(int n) {
    if (n == 0) return 1;
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    char choice;
    
    do {
        int n;
        double x;
        
        cout << "Программа для вычисления произведения ряда\n";
        cout << "P = (1 + x/1!) * (1 + x^2/2!) * ... * (1 + x^n/n!)\n\n";
        
        do {
            cout << "Введите количество членов ряда (n > 0): ";
            cin >> n;
        } while (n <= 0);
        
        cout << "Введите значение x: ";
        cin >> x;
        
        double P = 1.0;
        cout << "\nПромежуточные вычисления:\n";
        
        for (int i = 1; i <= n; i++) {
            double term = 1 + pow(x, i) / factorial(i);
            P *= term;
            
            cout << "Член " << i << ": (1 + " << x << "^" << i << "/" << i << "!) = "
                 << fixed << setprecision(6) << term << endl;
            cout << "P" << i << " = " << P << endl;
        }
        
        cout << "\nИтоговый результат P = " << P << endl;
        
        cout << "\nХотите выполнить новое вычисление? (y/n): ";
        cin >> choice;
        cout << "\n";
        
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}