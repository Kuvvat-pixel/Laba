#ifndef TASK_H
#define TASK_H

#include <vector>

typedef struct {
    char fullName[50];
    int department;
    char position[50];
    int startYear;
} Employee;

void addEmployee(std::vector<Employee>& employees);
void deleteEmployee(std::vector<Employee>& employees);
void displayEmployees(const std::vector<Employee>& employees);
void sortAndDisplayByDepartment(const std::vector<Employee>& employees);

#endif