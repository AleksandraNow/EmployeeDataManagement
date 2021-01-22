#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Prof.h"
#include "Employee.h"
#include "EmployeeList.h"


using namespace std;






int main() {
    cout << "test" << endl;

    int ch;
    EmployeeList lista;
    Employee emp = *new Employee(1, "ola", 12, 15, Prof(0));
    Employee wx = *new Employee(1, "ola", 12, 15, Prof(0));
    Employee gtf = *new Employee(1, "ola", 12, 15, Prof(0));

    lista.addEmployee(emp);
    lista.addEmployee(wx);
    lista.addEmployee(gtf);

    int id;
    std::string name;
    int salary;
    int seniority;
    int prof;
    int number;
    int index;
    string readPath;

    string path;
    cin >> ch;



        switch (ch) {
            case 1:
/*
                cout << "ID: ";
                cin >> id;

                cout << "name: ";
                cin >> name;

                cout << "salary: ";
                cin >> salary;

                cout << "seniority: ";
                cin >> seniority;

                cout << "professsion: ";
                cin >> prof;
                // Employee emp = *new Employee(id,name,salary,seniority, Prof(prof) );


                //lista.add(emp);
                */
            case 2:
                lista.displayEmployee();
                break;

            case 3:
                lista.deleteEmployee(1);
                break;
            case 4:
                cout << "name: ";
                cin >> name;
                lista.displayEmployeeByCharacter(name);
                break;
            case 5:
                cout << "salary: ";
                cin >> salary;
                lista.displayEmployeeAboveSalary(salary);
            case 6:
                cout << "salary: ";
                cin >> salary;
                lista.displayEmployeeBelowSalary(salary);
            /*case 7:
                lista.sortEmp();
                */
            case 8:
                cout << "Path do save data: ";
                cin >> path;
                lista.saveDataToFile(path);
                break;
            default:
                cout << "test";

        }
    };








