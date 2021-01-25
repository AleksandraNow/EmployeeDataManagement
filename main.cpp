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
    EmployeeList lista;

    int id;
    string name;
    int salary;
    int seniority;
    int prof;
    string readPath;
    string path;
    int choice;

    do {
        cout << "\n\t1.ADD EMPLOYEE";
        cout << "\n\t2.DISPLAY ALL EMPLOYEES";
        cout << "\n\t3.DELETE EMPLOYEE RECORD";
        cout << "\n\t4.DISPLAY THE EMPLOYEE WHO HAS THE NAME";
        cout << "\n\t5.DISPLAY THE EMPLOYEE ABOVE SALARY";
        cout << "\n\t6.DISPLAY THE EMPLOYEE BELOW SALARY";
        cout << "\n\t8.SAVE DATA TO FILE";
        cout << "\n\t9.READ DATA FROM FILE";
        cout << "\n\t10.EDIT EMPLOYEE";
        cout << "\n\t11.EXIT";
        cout << "\n\tPlease Enter Your Choice (1-10): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Employee emp = getDataEmployee();
                lista.addEmployee(emp);
                break;
            }
            case 2:
                lista.displayEmployee();
                break;
            case 3:
                cout << "id: ";
                cin >> id;
                lista.deleteEmployee(id);
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
                break;
            case 6:
                cout << "salary: ";
                cin >> salary;
                lista.displayEmployeeBelowSalary(salary);
                break;
            case 7:
                lista.sortEmp();
                break;
            case 8:
                cout << "Path do save data: ";
                cin >> path;
                lista.saveDataToFile(path);
                break;
            case 9:
                cout << "Path to read data: ";
                cin >> path;
                lista.readDataFromFile(path);
                break;
            case 10:
                cout << "Edit employee seniority: ";
                cout << "Id employee: ";
                cin >> id;
                cout << "change seniority to ";
                cin >> seniority;
                lista.editEmployee(id, seniority);
                break;
            default:
                cout << "test";

        }
    } while (choice != 11);

};








