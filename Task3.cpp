#include <iostream>
#include <iomanip>
#include <limits>  
using namespace std;

void showMenu() {
    cout << "\n=== Контекстное меню ===\n";
    cout << "Задание: Вычисление суммы (ai - bi)^30 для i от 1 до 30\n";
    cout << "ai = i для нечетных i, i/2 для четных i\n";
    cout << "bi = i/2 для нечетных i, i/3 для четных i\n";
    cout << "Автор: Иванов Иван\n";
    cout << "Вариант: 1\n";
    cout << "1. Выполнить расчет\n";
    cout << "2. Показать меню\n";
    cout << "3. Выход\n";
    cout << "4. Я согласен на 4\n";// Новый пункт меню
}

double calculateSum() {
    double sum = 0;
    for (int i = 1; i <= 30; i++) {
        double ai, bi;
        if (i % 2 != 0) { // Нечетное
            ai = i;
            bi = i / 2.0;
        } else { // Четное
            ai = i / 2.0;
            bi = i / 3.0;
        }
        sum += (ai - bi);
    }
    return sum;
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int choice = 0;

    do {
        showMenu();
        cout << "\nВыберите действие: ";
        cin >> choice;

        // Проверка на ошибки ввода
        if (cin.fail()) {
            cout << "Ошибка ввода. Пожалуйста, введите число.\n";
            clearInput(); // Очищаем ввод
            continue; // Возвращаемся к началу цикла
        }

        switch (choice) {
            case 1:
                cout << fixed << setprecision(2);
                cout << "Результат вычисления: " << calculateSum() << "\n";
                cout << "Нажмите Enter для продолжения...";
                cin.ignore(); // Игнорируем оставшийся символ новой строки
                cin.get(); // Ждем нажатия клавиши
                break;
            case 2:
                showMenu();
                break;
            case 3:
                cout << "Выход из программы.\n";
                break;
            case 4:
                cout << "Я согласен на 4\n"; // Вывод сообщения
                cout << "Нажатия Enter для продолжения...";
                cin.ignore();
                cin.get(); 
                break;
            default:
                cout << "Некорректный выбор. Пожалуйста, выберите снова.\n";
                break;
        }
    } while (choice != 3);
return 0;
}