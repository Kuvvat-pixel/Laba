#include <iostream>

int main() {
    double X, Y;
    std::cout << "Введите два вещественных числа (X и Y): ";
    std::cin >> X >> Y;
    // Используем тернарную операцию
    double max_value = (X > Y) ? X : Y; 
    std::cout << "Максимальное число: " << max_value << std::endl; 
    return 0;
}
#include <iostream>
using namespace std;
int main() {
    double X, Y;
    cout << "Введите два вещественных числа (X и Y): ";
    cin >> X >> Y;

    double max_value;

    // Используем if-else вместо тернарной операции
    if (X > Y) {
        max_value = X;
    } else {
        max_value = Y;
    }

   cout << "Максимальное число: " << max_value <<endl;

    return 0;
}