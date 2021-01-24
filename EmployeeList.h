//
// Created by linux-user on 22.01.2021.
//

#ifndef UNTITLED_EMPLOYEELIST_H
#define UNTITLED_EMPLOYEELIST_H


#include <vector>
#include "Employee.h"

class EmployeeList {
public:
    std::vector<Employee> vector;

    void addEmployee(Employee e);

    void displayEmployee();

    void deleteEmployee(int number);

    void saveDataToFile(std::__cxx11::string path);

    void readDataFromFile(std::__cxx11::string path);

    void displayEmployeeAboveSalary(int number);

    void displayEmployeeBelowSalary(int number);

    void displayEmployeeByCharacter(std::string name);

    void sortEmp();


    void editEmployee(int a, int b);


    typedef std::map<Prof, std::string> ProfMap;
};


#endif //UNTITLED_EMPLOYEELIST_H
