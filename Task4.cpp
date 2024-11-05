#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;
void showMenu(const string& authorName) {
    cout << "\n=== Вычисление суммы ряда ===" << endl;
    cout << "Задание: Найти сумму ряда с точностью ε = 10^(-3)," << endl;
    cout << "где общий член dn = 1/(2^n) + 1/(3^n)" << endl;
    cout << "Автор: " << authorName << endl;
    cout << "================================\n" << endl;
}
double calculateSeriesSum() {
    const double EPSILON = 1e-3;
    double sum = 0.0;
    double dn;
    int n = 1;
    do {
        dn = 1.0/pow(2, n) + 1.0/pow(3, n);
        sum += dn;
        n++;
    } while (dn >= EPSILON);   
    return sum;
}
int main() {
    setlocale(LC_ALL, "Russian");
    char choice;
    string authorName;
    cout << "Введите имя автора: ";
    getline(cin, authorName);
    do {
        system("cls");
        showMenu(authorName);
        cout << "Сумма ряда с точностью " << fixed << setprecision(3) << 1e-3;
        cout << " равна: " << calculateSeriesSum() << endl;
        cout << "\nХотите выполнить расчет еще раз? (y/n): ";
        cin >> choice;
        cin.clear();
        cin.ignore(10000, '\n');
    } while (choice == 'y' || choice == 'Y');
    return 0;
}