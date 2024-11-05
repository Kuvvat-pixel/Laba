#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return sin(x) - cos(x);
}

int main() {
    // Определяем интервал поиска
    // Для функции sin(x) - cos(x) = 0 корень находится около π/4
    const double a = 0;  // начало интервала
    const double b = M_PI/2;  // конец интервала
    int n;
    
    cout << "Введите количество частей для разбиения интервала [" 
         << a << ", " << b << "]: ";
    cin >> n;
    
    // Вычисляем шаг
    double h = (b - a) / n;
    
    // Инициализируем переменные для поиска минимума
    double min_x = a;
    double min_value = abs(f(a));
    
    cout << fixed << setprecision(6);
    cout << "\nПоиск корня уравнения sin(x) - cos(x) = 0\n";
    cout << "----------------------------------------\n";
    
    // Перебираем все точки
    for (int i = 0; i <= n; i++) {
        double x = a + i * h;
        double current_value = abs(f(x));
        
        cout << "x = " << setw(10) << x 
             << " | f(x) = " << setw(10) << f(x) 
             << " | |f(x)| = " << setw(10) << current_value << endl;
        
        // Если нашли значение ближе к нулю, обновляем минимум
        if (current_value < min_value) {
            min_value = current_value;
            min_x = x;
        }
    }
    
    cout << "\nНайденный корень: x = " << min_x << endl;
    cout << "Значение функции в корне: f(" << min_x << ") = " << f(min_x) << endl;
    cout << "Погрешность (|f(x)|): " << min_value << endl;
    
    // Для проверки: точный корень уравнения sin(x) - cos(x) = 0 равен π/4 ≈ 0.785398
    cout << "\nДля сравнения: точный корень (π/4) = " << M_PI/4 << endl;
    
    return 0;
}