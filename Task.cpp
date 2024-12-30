#include "Task.h"
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
void addEmployee(vector<Employee>& employees) {
    Employee newEmployee;
    cout << "Введите ФИО: ";
    cin.ignore();
    cin.getline(newEmployee.fullName, 50);
    cout << "Введите номер отдела: ";
    cin >> newEmployee.department;
    cout << "Введите должность: ";
    cin.ignore();
    cin.getline(newEmployee.position, 50);
    cout << "Введите год начала работы: ";
    cin >> newEmployee.startYear;
    employees.push_back(newEmployee);
}
void deleteEmployee(vector<Employee>& employees) {
    if (employees.empty()) {
        cout << "Список сотрудников пуст.\n";
        return;
    }
    int index;
    cout << "Введите номер сотрудника для удаления: ";
    cin >> index;
    if (index < 1 || index > employees.size()) {
        cout << "Неверный номер.\n";
        return;
    }
    employees.erase(employees.begin() + (index - 1));
}
void displayEmployees(const vector<Employee>& employees) {
    if (employees.empty()) {
        cout << "Список сотрудников пуст.\n";
        return;
    }
    for (size_t i = 0; i < employees.size(); ++i) {
        cout << i + 1 << ". " << employees[i].fullName << ", Отдел: " 
             << employees[i].department << ", Должность: " 
             << employees[i].position << ", Стаж: " 
             << 2024 - employees[i].startYear << " лет\n";
    }
}
void sortAndDisplayByDepartment(const vector<Employee>& employees) {
    if (employees.empty()) {
        cout << "Список сотрудников пуст.\n";
        return;
    }
    vector<Employee> sortedEmployees = employees;
    sort(sortedEmployees.begin(), sortedEmployees.end(), [](const Employee& a, const Employee& b) {
        if (a.department == b.department) {
            return (2024 - a.startYear) > (2024 - b.startYear);
        }
        return a.department < b.department;
    });
    for (const auto& emp : sortedEmployees) {
        cout << emp.fullName << ", Отдел: " << emp.department 
             << ", Должность: " << emp.position 
             << ", Стаж: " << 2024 - emp.startYear << " лет\n";
    }
}
void displayMenu() {
    cout << "\nМеню:\n";
    cout << "1. Добавить сотрудника\n";
    cout << "2. Удалить сотрудника\n";
    cout << "3. Просмотреть сотрудников\n";
    cout << "4. Вывести списки сотрудников по отделам\n";
    cout << "5. Выйти\n";
    cout << "Выберите пункт: ";
}
int main() {
    vector<Employee> employees;
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee(employees);
                break;
            case 2:
                deleteEmployee(employees);
                break;
            case 3:
                displayEmployees(employees);
                break;
            case 4:
                sortAndDisplayByDepartment(employees);
                break;
            case 5:
                cout << "Выход.\n";
                break;
            default:
                cout << "Неверный выбор.\n";
        }
    } while (choice != 5);
    return 0;
}