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

    void add(Employee e);

    void display();

    void deleteEmp(int number);

    void saveToFile(std::__cxx11::string path);

    void load(std::__cxx11::string path);

    void displayAboveSalary(int number);

    void displayBelowSalary(int number);

    void displayChar(std::string name);

    void sortEmp();


    void edit(int a, int b);
};


#endif //UNTITLED_EMPLOYEELIST_H
