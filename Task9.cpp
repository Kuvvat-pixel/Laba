#include <iostream>
#include <iomanip>

using namespace std;

bool isPerfectNumber(int num) {
    if (num <= 0) return false;
    
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

int main() {
    char choice;
    
    do {
        int number;
        cout << "Программа для проверки совершенного числа\n";
        cout << "(Совершенное число равно сумме всех своих делителей, кроме самого себя)\n\n";
        
        cout << "Введите целое положительное число: ";
        cin >> number;
        
        if (isPerfectNumber(number)) {
            cout << "\nЧисло " << number << " является совершенным.\n";
            cout << "Делители числа " << number << ": ";
            for (int i = 1; i < number; i++) {
                if (number % i == 0) {
                    cout << i << " ";
                }
            }
            cout << "\n";
        } else {
            cout << "\nЧисло " << number << " не является совершенным.\n";
        }
        
        cout << "\nХотите проверить другое число? (y/n): ";
        cin >> choice;
        cout << "\n";
        
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}